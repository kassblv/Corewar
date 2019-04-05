#include "../includes/parser.h"

static program_rep* prog    = NULL;
static size_t       pc      = 0;

static bool parse_lfork_instr(void);
static bool parse_sti_instr(void);  
static bool parse_fork_instr(void);
static bool parse_lld_instr(void);
static bool parse_ld_instr(void);
static bool parse_add_instr(void);
static bool parse_zjmp_instr(void);
static bool parse_sub_instr(void);
static bool parse_ldi_instr(void);
static bool parse_or_instr(void);
static bool parse_st_instr(void);
static bool parse_aff_instr(void);
static bool parse_live_instr(void);
static bool parse_xor_instr(void);
static bool parse_lldi_instr(void);
static bool parse_and_instr(void);

typedef bool(*instr_ptr)(void);
static instr_ptr instr_table[TOTAL_TOKEN] = {
	[T_LFORK]=&parse_lfork_instr,
	[T_STI]=&parse_sti_instr,
	[T_FORK]=&parse_fork_instr,
	[T_LLD]=&parse_lld_instr,
	[T_LD]=&parse_ld_instr,
	[T_ADD]=&parse_add_instr,
	[T_ZJMP]=&parse_zjmp_instr,
	[T_SUB]=&parse_sub_instr,
	[T_LDI]=&parse_ldi_instr,
	[T_OR]=&parse_or_instr,
	[T_ST]=&parse_st_instr,
	[T_AFF]=&parse_aff_instr,
	[T_LIVE]=&parse_live_instr,
	[T_XOR]=&parse_xor_instr,
	[T_LLDI]=&parse_lldi_instr,
	[T_AND]=&parse_and_instr,
};

static instr_info info[TOTAL_TOKEN] = {
	[T_LFORK]   = {.have_ocp = false, .direct_4 = false},
	[T_STI]     = {.have_ocp = true,  .direct_4 = false},
	[T_FORK]    = {.have_ocp = false, .direct_4 = false},
	[T_LLD]     = {.have_ocp = true,  .direct_4 = true},
	[T_LD]      = {.have_ocp = true,  .direct_4 = true},
	[T_ADD]     = {.have_ocp = true,  .direct_4 = false},
	[T_ZJMP]    = {.have_ocp = false, .direct_4 = false},
	[T_SUB]     = {.have_ocp = true,  .direct_4 = false},
	[T_LDI]     = {.have_ocp = true,  .direct_4 = false},
	[T_OR]      = {.have_ocp = true,  .direct_4 = true},
	[T_ST]      = {.have_ocp = true,  .direct_4 = false},
	[T_AFF]     = {.have_ocp = true,  .direct_4 = false},
	[T_LIVE]    = {.have_ocp = false, .direct_4 = true},
	[T_XOR]     = {.have_ocp = true,  .direct_4 = true},
	[T_LLDI]    = {.have_ocp = true,  .direct_4 = false},
	[T_AND]     = {.have_ocp = true,  .direct_4 = true},
};

static bool
parse_newline_list(void) {
    if (peek_token() != T_NEWLINE)
        { return (false); }
    match(T_NEWLINE);
    while (peek_token() == T_NEWLINE)
        { match(T_NEWLINE); }
    return (true);
}

static bool check_validity(int kind_token) {
    size_t len_lexeme = (ft_strlen(get_lexeme() + 1)) - 1;
    if (kind_token == T_NAME) {
        if (len_lexeme > PROG_NAME_LENGTH) {
            errorf(get_lineno(), "A '.name' cannot exceed 128 byte long.");
            return (false);
        }
        ft_strcpy(prog->header.prog_name, get_lexeme() + 1);
        prog->header.prog_name[len_lexeme] = '\0';
    }
    else {
        if (len_lexeme > COMMENT_LENGTH) {
            errorf(get_lineno(), "A '.comment' cannot exceed 2048 byte long.");
            return (false);
        }
        ft_strcpy(prog->header.comment, get_lexeme() + 1);
        prog->header.comment[len_lexeme] = '\0';
    }
    return (true);
}

static bool
parse_name_comment(int instr_kind) {
    match(instr_kind);
    return (match(T_STR)                &&
            check_validity(instr_kind)  &&
            parse_newline_list());
}

static bool
parse_prolog(void) {
    if (is_in_first(T_NAME, T_COMMENT, END_LOOK)) {
        int instr_kind = peek_token();

        char const* const name      = ".name";
        char const* const comment   = ".comment";

        if (!parse_name_comment(instr_kind))
            { return (false); }
        if (peek_token() != ((instr_kind == T_NAME ? (T_COMMENT) : (T_NAME)))) {
            errorf(get_lineno(), "Missing '%s' after '%s'.", 
                                (instr_kind == T_NAME) ? (comment) : (name),
                                (instr_kind == T_NAME) ? (name) : (comment));
            return (false);
        }
        return (parse_name_comment(peek_token()));
    }
    errorf(get_lineno(), "Missing either '.name' or '.comment'.");
    return (false);
}

bool
parse_atom(bool reg, bool direct, bool indirect, bool direct4, int* save_type) {
    if ((!reg) && (!direct) && (!indirect))
        { return (true); }

    int kind_type = -1;
    if ((reg) && (peek_token() == T_REGT))
        { kind_type = T_REGT; }
    if ((direct) && (peek_token() == T_DIRECT))
        { kind_type = T_DIRECT; }
    if ((indirect) && (peek_token() == T_INDIRECT))
        { kind_type = T_INDIRECT; }
    if (kind_type != -1) {
        if (save_type)
            { *save_type = kind_type; }

        switch (kind_type) {
            case T_REGT:        pc += 1; break;
            case T_INDIRECT:    pc += 2; break;
            case T_DIRECT:      pc += 2;
                                if (direct4)
                                    { pc += 2; }
                                break;
        }
        return (match(kind_type));
    }
    return (false);
}

bool
match_atom_instr(int kind_instr) {
    if (match(kind_instr)) {
        pc += (1 + ((info[kind_instr].have_ocp) ? 1 : 0));
        return (true);
    }
    return (false);
}

static bool
parse_param(int kind, size_t count, param_allow p1,
                                    param_allow p2,
                                    param_allow p3) {
    char const* op1_str = NULL;
    int op1_kind = -1;

    char const* op2_str = NULL;
    int op2_kind = -1;

    char const* op3_str = NULL;
    int op3_kind = -1;

    size_t old_pc = pc;

    if (!(match_atom_instr(kind) && parse_atom(p1.kind_reg, p1.kind_dir, p1.kind_ind,
                                                info[kind].direct_4, &op1_kind)))
        { return (false); }
    op1_str = get_lexeme();

    if (count > 1) {
        if (!(match(T_SEP) && parse_atom(p2.kind_reg, p2.kind_dir, p2.kind_ind,
                                                info[kind].direct_4, &op2_kind)))
            { return (false); }
        op2_str = get_lexeme();

        if (count > 2) {
            if (!(match(T_SEP) && parse_atom(p3.kind_reg, p3.kind_dir, p3.kind_ind,
                                                info[kind].direct_4, &op3_kind)))
                { return (false); }
            op3_str = get_lexeme();
        }
    }
    return (insert_instr_list(prog, get_lineno(), info[kind], old_pc, kind,
                                    op1_str,    op1_kind,
                                    op2_str,    op2_kind,
                                    op3_str,    op3_kind));
}

bool
parse_lfork_instr(void) {
    return (parse_param(T_LFORK, 1, (param_allow){false, true, false},
                                    (param_allow){},
                                    (param_allow){}));
}

bool
parse_sti_instr(void) {
    return (parse_param(T_STI, 3,   (param_allow){true, false, false},
                                    (param_allow){true, true, true},
                                    (param_allow){true, true, false}));
}  

bool
parse_fork_instr(void) {
    return (parse_param(T_FORK, 1,  (param_allow){false, true, false},
                                    (param_allow){},
                                    (param_allow){}));
}

bool
parse_lld_instr(void) {
    return (parse_param(T_LLD, 2,   (param_allow){false, true, true},
                                    (param_allow){true, false, false},
                                    (param_allow){}));
}

bool
parse_ld_instr(void) {
    return (parse_param(T_LD, 2,    (param_allow){false, true, true},
                                    (param_allow){true, false, false},
                                    (param_allow){}));
}

bool
parse_add_instr(void) {
    return (parse_param(T_ADD, 3,   (param_allow){true, false, false},
                                    (param_allow){true, false, false},
                                    (param_allow){true, false, false}));
}

bool
parse_zjmp_instr(void) {
    return (parse_param(T_ZJMP, 1,  (param_allow){false, true, false},
                                    (param_allow){},
                                    (param_allow){}));
}

bool
parse_sub_instr(void) {
    return (parse_param(T_ADD, 3,   (param_allow){true, false, false},
                                    (param_allow){true, false, false},
                                    (param_allow){true, false, false}));
}

bool
parse_ldi_instr(void) {
    return (parse_param(T_LDI, 3,   (param_allow){true, true, true},
                                    (param_allow){true, true, false},
                                    (param_allow){true, false, false}));
}

bool
parse_or_instr(void) {
    return (parse_param(T_OR, 3,    (param_allow){true, true, true},
                                    (param_allow){true, true, true},
                                    (param_allow){true, false, false}));
}

bool
parse_st_instr(void) {
    return (parse_param(T_ST, 2,    (param_allow){true, false, false},
                                    (param_allow){true, false, true},
                                    (param_allow){}));
}

bool
parse_aff_instr(void) {
    return (parse_param(T_AFF, 1,   (param_allow){true, false, false},
                                    (param_allow){},
                                    (param_allow){}));
}

bool
parse_live_instr(void) {
    return (parse_param(T_LIVE, 1,  (param_allow){false, true, false},
                                    (param_allow){},
                                    (param_allow){}));
}

bool
parse_xor_instr(void) {
    return (parse_param(T_XOR, 3,   (param_allow){true, true, true},
                                    (param_allow){true, true, true},
                                    (param_allow){true, false, false}));
}

bool
parse_lldi_instr(void) {
    return (parse_param(T_LLDI, 3,  (param_allow){true, true, true},
                                    (param_allow){true, true, false},
                                    (param_allow){true, false, false}));
}

bool
parse_and_instr(void) {
    return (parse_param(T_AND,  3,  (param_allow){true, true, true},
                                    (param_allow){true, true, true},
                                    (param_allow){true, false, false}));
}

bool
parse_mixed_instr(void) {
    int kind_instr  = peek_token();
    int save_lineno = get_lineno();

    if (is_in_first(T_LFORK, T_STI, T_FORK, T_LLD, T_LD, T_ADD,
	                T_ZJMP,  T_SUB, T_LDI,  T_OR,  T_ST, T_AFF,
	                T_LIVE,  T_XOR, T_LLDI, T_AND, END_LOOK)) {
        if (!(instr_table[peek_token()]())) {
            errorf(save_lineno, "Instruction %s is ill-formatted.", get_token_str(kind_instr));
            return (false);
        }
        return (true);
    }
    else if (kind_instr == T_NEWLINE)
        { return (true); }
    else if (kind_instr == T_UNKNOWN){
        errorf(get_lineno(), "Unknown instruction '%s'.", get_lexeme());
        return (false);
    }
    return (false);
}

bool
parse_asm_layout(void) {
    if (peek_token() == T_LABEL) {
        char const* new_lexeme = ft_strndup(get_lexeme(), ft_strlen(get_lexeme())-1);
        bool defined = false;
        if (!insert_label_list(prog, new_lexeme, pc, &defined) && (defined)) {
            errorf(get_lineno(), "Label name already defined %s.", new_lexeme);
            return (false);
        }
        match(T_LABEL);
    }
    return (parse_mixed_instr() && parse_newline_list());
}


bool
parse_list(void) {
    if (!parse_asm_layout())
        { return (false); }
    while (!is_eof()) {
        if (!parse_asm_layout())
            { return (false); }
    }
    return (true);
}

static bool
parse_program(void) {
    while (peek_token() == T_NEWLINE)
        { parse_newline_list(); }
    if (!parse_prolog())
        { return (false); }
    if (!is_eof())
        return (parse_list());
    return (true);
}

program_rep*
parse(char const* buff) {
    if (!buff)
        { return (NULL); }

    set_stream(buff, true);

    free_program_rep(prog);
    prog = new_program_rep();

    if (!(prog && parse_program()))
        { return (NULL); }

    prog->header.prog_size = pc;
    return (prog);
}

void
clean_parser(void) {
    clean_lexer();
    free_program_rep(prog);
}

