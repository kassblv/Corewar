#include "../includes/buffer.h"

static size_t	round_up(size_t size)
{
	size_t close2 = 1;

	while (close2 <= size)
	{ close2 <<= 1; }
	return (close2);
}

static buffer_t*	make_len_buff(size_t len)
{
	buffer_t* buff = (buffer_t*)ft_memalloc(sizeof(buffer_t));
	if (!buff)
	{ return (NULL); }
	buff->body = (char*)malloc(sizeof(char) * len);
	if (!buff->body)
	{ return (NULL); }
	buff->alloc = len;
	buff->index = 0;
	ft_memset(buff->body, 0, buff->alloc);
	return (buff);
}

buffer_t*	new_buffer(void)
{
	return (make_len_buff(_BUFF_SIZE));
}

buffer_t*	dup_buffer(buffer_t const* buff)
{
	if (!buff)
	{ return (NULL); }
	buffer_t* new_buff = make_len_buff(buff->alloc);
	if (!new_buff)
	{ return (NULL); }
	ft_memcpy(new_buff->body, buff->body, buff->alloc);
	return (new_buff);
}

void	del_buffer(buffer_t* buff)
{
	if (buff)
	{ free((void*)buff->body); }
	free((void*)buff);
}

static int	extend_buffer(buffer_t* buff)
{
	if (!buff)
	{ return (-1); }
	if (SIZE_BUFFER(buff) + 1 >= buff->alloc) {
		size_t new_sz = round_up(SIZE_BUFFER(buff) + 1);
		char* nw_body = (char*)realloc(buff->body, new_sz);
		if (nw_body) {
			buff->body = nw_body;
			buff->alloc = new_sz;
			ft_memset(buff->body + SIZE_BUFFER(buff), 0,
					buff->alloc - SIZE_BUFFER(buff));
		}
		else
		{ return (-1); }
	}
	return (0);
}

int		write_char_buffer(buffer_t* buff, char c, bool byte_oriented)
{
	if (extend_buffer(buff) == -1)
		return (-1);
	buff->body[SIZE_BUFFER(buff)] = c;
	if ((c) || (byte_oriented))
		++(buff->index);
	return ((unsigned char)c);
}

int		write_byte_buffer(buffer_t* buff, uint64_t value, size_t size, int endian)
{
	buffer_t* new_buff = new_buffer();
	if ((!buff) || (!new_buff))
	{ return (-1); }
	for (size_t i = 0; i < size; ++i) {
		char byte = (value % 0x100);
		if (write_char_buffer(new_buff, byte, true) == -1) {
			del_buffer(new_buff);
			return (-1);
		}
		value /= 0x100;
	}
	if (endian == BG_ENDIAN)
	{ reverse_buffer(new_buff); }
	int r = append_buffer(buff, new_buff);
	del_buffer(new_buff);
	return (r);
}

int		write_buffer(buffer_t* buff, char const* str)
{
	if (!buff || !str)
	{ return (-1); }
	size_t index = 0;
	for (; str[index]; ++index) {
		if (write_char_buffer(buff, str[index], false) == -1)
		{ return (-1); }
	}
	if (write_char_buffer(buff, '\0', false) == -1)
		return (-1);
	return (index);
}

int		write_file_buffer(buffer_t* buff, int filde)
{
	if (filde == -1)
		return (-1);
	return (write(filde, BODY_BUFFER(buff), SIZE_BUFFER(buff)));
}


int		append_buffer(buffer_t* buff, buffer_t const* src)
{
	if (!buff || !src)
		return (-1);
	for (size_t i = 0; i < SIZE_BUFFER(src); ++i)
	{
		if (write_char_buffer(buff, CHAR_AT(src, i), true) == -1)
		{ return (-1); }
	}
	return (SIZE_BUFFER(src));
}

void	unget_char_front_buffer(buffer_t* buff, size_t sz)
{
	if (!buff)
		return;
	else if (SIZE_BUFFER(buff) <= sz)
		reset_buffer(buff);
	else
	{
		buff->index -= sz;
		ft_memmove(buff->body, buff->body + sz, SIZE_BUFFER(buff));
		ft_memset(buff->body + SIZE_BUFFER(buff), 0, sz);
	}
}

void	unget_char_back_buffer(buffer_t* buff, size_t sz)
{
	if (!buff)
	{ return; }

	if (sz > SIZE_BUFFER(buff))
		sz = SIZE_BUFFER(buff);
	while (sz--)
		buff->body[--(buff->index)] = '\0';
}

void	reset_buffer(buffer_t* buff)
{
	if (!buff)
	{ return; }
	ft_memset(buff->body, 0, buff->alloc);
	buff->index = 0;
}

int		hash_buffer(buffer_t const* buff)
{
	if (!buff)
	{ return (0); }
	int sum_char = 0;
	for (size_t i = 0; i < SIZE_BUFFER(buff); ++i)
	{ sum_char += buff->body[i]; }
	return (sum_char);
}

void	reverse_buffer(buffer_t* buff)
{
	if (!buff)
	{ return; }
	for (size_t i = 0; i < (SIZE_BUFFER(buff) / 2); ++i)
	{
		char swap_char = CHAR_AT(buff, i);
		BODY_BUFFER(buff)[i] = BODY_BUFFER(buff)[SIZE_BUFFER(buff) - i - 1];
		BODY_BUFFER(buff)[SIZE_BUFFER(buff) - i - 1] = swap_char;
	}
}

void	move_back_buffer(buffer_t* dst_buff, buffer_t* src_buff, size_t size)
{
	if (size > SIZE_BUFFER(src_buff))
		size = SIZE_BUFFER(src_buff);
	size_t start_index = SIZE_BUFFER(src_buff) - size;
	for (size_t i = start_index; i < SIZE_BUFFER(src_buff); ++i) {
		int char_at = CHAR_AT(src_buff, i);
		if (write_char_buffer(dst_buff, char_at, false) == -1)
		{ return; }
	}
	unget_char_back_buffer(src_buff, size);
}

void	move_front_buffer(buffer_t* dst_buff, buffer_t* src_buff, size_t size)
{
	if (size > SIZE_BUFFER(src_buff))
		size = SIZE_BUFFER(src_buff);
	for (size_t i = 0; i < size; ++i)
	{
		int char_at = CHAR_AT(src_buff, i);
		if (write_char_buffer(dst_buff, char_at, false) == -1)
			return;
	}
	unget_char_front_buffer(src_buff, size);
}
