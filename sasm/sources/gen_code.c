#include "../includes/gen_code.h"

static int
gen_header_program_rep(program_rep* prog, buffer_t* buff) {
#ifdef USE_PADDING
    size_t len_prog_name    = ft_strlen(prog->header.prog_name);
    size_t len_comment      = ft_strlen(prog->header.comment);
#endif /* USE_PADDING */

    if ((write_byte_buffer(buff, prog->header.magic, 4, BG_ENDIAN) == -1) ||
        (write_buffer(buff, prog->header.prog_name) == -1))
        { return (-1); }

#ifdef USE_PADDING
    write_byte_buffer(buff, 0, (PROG_NAME_LENGTH - len_prog_name) + PADDING, LT_ENDIAN);
#endif /* USE_PADDING */

    if ((write_byte_buffer(buff, prog->header.prog_size, 4, BG_ENDIAN) == -1) ||
        (write_buffer(buff, prog->header.comment) == -1))
        { return (-1); }

#ifdef USE_PADDING
    write_byte_buffer(buff, 0, (COMMENT_LENGTH - len_comment) + PADDING, LT_ENDIAN);
#endif /* USE_PADDING */
    return (0);
}

static int
gen_instr_list_program_rep(program_rep* prog, buffer_t* buff) {
    instr_list* iter = prog->ir_list;
    while (iter) {
        write_byte_buffer(buff, iter->ir_node.opcode, 1, BG_ENDIAN);
        if (iter->ir_node.ocp != -1)
            { write_byte_buffer(buff, iter->ir_node.ocp, 1, BG_ENDIAN); }
        for (int i = 0; i < 3; ++i) {
            struct operand_t* op;

            switch (i) {
                case 0: op = &iter->ir_node.op1; break;
                case 1: op = &iter->ir_node.op2; break;
                case 2: op = &iter->ir_node.op3; break;
            }

            label_list* iter_l = NULL;
            bool found = false;

            switch (op->kind_op) {
                case EMPTY:     break;
                case REGISTER:  if (write_byte_buffer(buff, op->_register, 1, BG_ENDIAN) == -1)
                                    { return (-1); }
                                break;
                case LITERAL:   if (write_byte_buffer(buff, op->_literal,
                                		(!op->direct) ? 2 : ((op->direct4) ? 4 : 2), BG_ENDIAN) == -1)
                                	{ return (-1); }
                                break;
                case LABEL:     iter_l = prog->symbol_list;
                                while (iter_l) {
                                    if (!ft_strcmp(iter_l->label_name, op->_label)) {
                                        found = true;
                                        break;
                                    }
                                    iter_l = iter_l->next;
                                }

                                if (!found) {
                                    errorf(iter->ir_node.lineno,
                                        "The symbol '%s' is not defined.", op->_label);
                                    return (-1);
                                }
			    	if (write_byte_buffer(buff, iter_l->location - op->_pos_pc,
						(!op->direct) ? 2 : ((op->direct4) ? 4 : 2), BG_ENDIAN) == -1)
					{ return (-1); }
                                break;
            }
        }
        iter = iter->next;
    }
    return (0);
}

buffer_t*
gen_program_rep(program_rep* prog) {
    if (!prog)
        { return (NULL); }
    buffer_t* buff = new_buffer();
    if (!buff)
        { return (NULL); }
    if (gen_header_program_rep(prog, buff) || gen_instr_list_program_rep(prog, buff)) {
        del_buffer(buff);
        return (NULL);
    }
    return (buff);
}

