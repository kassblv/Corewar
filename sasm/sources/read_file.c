#include "../includes/read_file.h"

char*
read_file(int fd) {
    if (read(fd, NULL, 0) == -1)
        { return (NULL); }
    char* buff = (char*)malloc(sizeof(char) * BUFF_NEXT);
    if (!buff)
        { return (NULL); }

    char* offset_buff = buff;
    size_t count_buff = BUFF_NEXT;

    int rd;
    while ((rd = read(fd, offset_buff, BUFF_NEXT)) == BUFF_NEXT) {
        char* new_buff = NULL;
        if (!(new_buff = realloc(buff, count_buff + BUFF_NEXT))) {
            free((void*)buff);
            return (NULL);
        }   
        offset_buff = (buff = new_buff) + (count_buff);
        count_buff += BUFF_NEXT;
    }
    if (rd == -1) {
        free((void*)buff);
        return (NULL);
    }
    offset_buff[rd] = '\0';
    return (buff);
}
