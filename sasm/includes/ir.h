#ifndef IR_H
#define IR_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../libft/libft.h"
#include "utils.h"
#include "op.h"

enum {
    EMPTY=0,
    REGISTER,
    LABEL,
    LITERAL,
};

typedef struct {
    size_t opcode;
    int ocp;
    int lineno;
    struct operand_t {
        int kind_op;
        union {
            size_t      _register;
            struct {
                char const* _label;
                size_t      _pos_pc;
            };
            long        _literal;
        };
        bool direct;    
        bool direct4;
    } op1, op2, op3;
} ir_node;

typedef struct instr_list {
    ir_node             ir_node;
    struct instr_list*  next;
} instr_list;

typedef struct label_list {
    char const*         label_name;
    size_t              location;
    struct label_list*  next;
} label_list;

typedef struct {
    header_t    header;
    instr_list* ir_list;
    label_list* symbol_list;
} program_rep;

typedef struct {
    bool have_ocp;
    bool direct_4;
} instr_info;

program_rep*    new_program_rep(void);
void            free_program_rep(program_rep*);
bool            insert_instr_list(program_rep*, int, instr_info, size_t, int, ...);
bool            insert_label_list(program_rep*, char const*, size_t, bool*);

#endif /* IR_H */
