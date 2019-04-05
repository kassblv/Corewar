#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "../../libft/libft.h"
#include "ir.h"

program_rep*    parse(char const*);
void            clean_parser(void);

typedef struct {
    bool kind_reg;
    bool kind_dir;
    bool kind_ind;
} param_allow;

#endif /* PARSER_H */
