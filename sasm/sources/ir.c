#include "../includes/ir.h"
#include "../includes/lexer.h"

#include <string.h>

static int opcode_table[TOTAL_TOKEN] = {
	[T_LFORK]=0x0F,
	[T_STI]=0x0B,
	[T_FORK]=0x0C,
	[T_LLD]=0x0D,
	[T_LD]=0x02,
	[T_ADD]=0x04,
	[T_ZJMP]=0x09,
	[T_SUB]=0x05,
	[T_LDI]=0x0A,
	[T_OR]=0x07,
	[T_ST]=0x03,
	[T_AFF]=0x10,
	[T_LIVE]=0x01,
	[T_XOR]=0x08,
	[T_LLDI]=0x0E,
	[T_AND]=0x06,
};

static size_t
param2ocp(int kind[3]) {
    size_t ocp = 0;
    for (size_t i = 0; i < 3; ++i) {
        switch (kind[i]) {
            case T_REGT:        ocp |= REG_CODE; break;
            case T_DIRECT:      ocp |= DIR_CODE; break;
            case T_INDIRECT:    ocp |= IND_CODE; break;
        }
        ocp <<= 2;
    }
    return (ocp);
}

program_rep*
new_program_rep(void) {
    program_rep* prog = (program_rep*)malloc(sizeof(program_rep));
    if (!prog)
        { return (NULL); }
    ft_memset(prog, sizeof(*prog), 0);
    prog->header.magic = COREWAR_EXEC_MAGIC;
    return (prog);
}

static void
free_instr_list(instr_list* list) {
    if (!list)
        { return; }
    free_instr_list(list->next);
    if (list->ir_node.op1.kind_op == LABEL)
        { free((void*)list->ir_node.op1._label); }
    if (list->ir_node.op2.kind_op == LABEL)
        { free((void*)list->ir_node.op2._label); }
    if (list->ir_node.op3.kind_op == LABEL)
        { free((void*)list->ir_node.op3._label); }
    free((void*)list);
}

static void
free_label_list(label_list* list) {
    if (!list)
        { return; }
    free_label_list(list->next);
    free((void*)list->label_name);
    free((void*)list);
}

void
free_program_rep(program_rep* prog) {
    if (prog) {
        free_label_list(prog->symbol_list);
        free_instr_list(prog->ir_list);
    }
    free((void*)prog);
}

bool
insert_instr_list(program_rep* prog, int lineno, instr_info info,
                  size_t pos_pc, int token_kind, ...) {
    if (!prog)
        { return (false); }
    instr_list* node = (instr_list*)malloc(sizeof(instr_list));
    if (!node)
        { return (false); }

    node->ir_node.opcode = opcode_table[token_kind];
    node->ir_node.lineno = lineno;

    int kinds[3] = { -1, -1, -1 };

    va_list args;
    va_start(args, token_kind);
    for (int i = 0; i < 3; ++i) {
        struct operand_t* op;

        switch (i) {
            case 0: op = &node->ir_node.op1; break;
            case 1: op = &node->ir_node.op2; break;
            case 2: op = &node->ir_node.op3; break;
        }

        char const* lexeme = va_arg(args, char const*);
        if (!lexeme)
            { break; }
        int param_kind = va_arg(args, int);
        kinds[i] = param_kind;
        if (param_kind == T_REGT) {
            op->kind_op = REGISTER;
            op->_register = (size_t)ft_atoi(lexeme + 1);
        }
        else {
            if (param_kind == T_DIRECT) {
                op->direct  = true;
                op->direct4 = info.direct_4;
                ++lexeme;
            }
            if ((*lexeme) == LABEL_CHAR) {
                op->kind_op = LABEL;
                op->_label = ft_strdup(lexeme + 1);
                op->_pos_pc = pos_pc;
            }
            else {
                bool overflow = false;
                op->kind_op = LITERAL;
              	op->_literal = ft_atoi(lexeme);
		if (!op->direct)
			{ op->_literal += pos_pc; }
                if (overflow) {
                    errorf(lineno, "The literal '%s' does not fit into 4 byte.", lexeme);
                    free((void*)node);
                    return (false);
                }
            }
        }
    }
 
    node->ir_node.ocp = -1;
    if (info.have_ocp)
        { node->ir_node.ocp = param2ocp(kinds); }

    if (!prog->ir_list)
        { prog->ir_list = node; }
    else {
        instr_list* iter = prog->ir_list;
        while (iter->next)
            { iter = iter->next; }
        iter->next = node;
    }

    va_end(args);
    return (true);
}

bool
insert_label_list(program_rep* prog, char const* name, size_t location, bool* defined) {
    if (!prog)
        { return (false); }
    label_list* iter = prog->symbol_list;
    while (iter) {
        if (!ft_strcmp(iter->label_name, name)) {
            if (defined)
                { *defined = true; }
            return (false);
        }
        iter = iter->next;
    }
    label_list* node = (label_list*)malloc(sizeof(label_list));
    if (!node)
        { return (false); }
    node->label_name = name;
    node->location = location;
    node->next = prog->symbol_list;
    prog->symbol_list = node;
    return (true);
}

