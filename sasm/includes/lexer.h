#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#include "utils.h"
#include "../../libft/libft.h"
#define END_LOOK    (-1)
#define TOTAL_TOKEN	(30)

enum {
	T_NAME,
	T_COMMENT,
	T_STR,
	T_LABEL,
	T_REGT,
	T_INDIRECT,
	T_DIRECT,
	T_SEP,
	T_LFORK,
	T_STI,
	T_FORK,
	T_LLD,
	T_LD,
	T_ADD,
	T_ZJMP,
	T_SUB,
	T_LDI,
	T_OR,
	T_ST,
	T_AFF,
	T_LIVE,
	T_XOR,
	T_LLDI,
	T_AND,
	T_NEWLINE,
	T_UNKNOWN,
	T_SCOMMENT,
	T_SPACE,
	T_ERROR,
	T_EOF,
};

void        set_stream(char const*, bool);
char const* get_lexeme(void);
char const* get_token_str(int);
size_t      get_lineno(void);
int         peek_token(void);
bool        match(int);
int         lexer(void);
void        clean_lexer(void);
bool        is_eof(void);
bool        is_error(void);
bool        is_in_first(int, ...);

typedef struct lexeme_list {
    char const*             lexeme;
    struct lexeme_list*     next;
} lexeme_list;

#endif /* LEXER_H */
