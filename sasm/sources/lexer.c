#include "../includes/lexer.h"
#include "../includes/corewar.lex.h"

static char const* stream = NULL;
static size_t stream_pos = 0;

static lexeme_list* list_lexeme = NULL;
static int look_token = -1;

static size_t lineno = 1;

static int
add_lexeme(char const* lexeme) {
    if (!lexeme)
        { return (0); }
    lexeme_list* node = (lexeme_list*)malloc(sizeof(lexeme_list));
    if (!node)
        { return (-1); }
    node->lexeme = lexeme;
    node->next = list_lexeme;
    list_lexeme = node;
    return (0);
}

static void
free_lexeme_list(lexeme_list* list) {
    if (!list)
        { return; }
    free_lexeme_list(list->next);
    free((void*)list->lexeme);
    free((void*)list);
}

void
set_stream(char const* buff, bool must_free) {
    if (must_free)
        { free((void*)stream); }
    stream = buff;
    stream_pos = 0;
    lineno = 1;
}

char const*
get_lexeme(void) {
    if (!list_lexeme)
        { return (NULL); }
    return (list_lexeme->lexeme);
}

char const*
get_token_str(int token_kind) {
    return (g_corewar_token_name_table[token_kind]);
}

size_t
get_lineno(void) {
    return (lineno);
}

int
peek_token(void) {
    if (look_token == -1)
        { look_token = lexer(); }
    return (look_token);
}

bool
match(int token_kind) {
    if (peek_token() != token_kind) {
        errorf(lineno, "Token %s does not match the actual input.",
                                g_corewar_token_name_table[token_kind]);
        return (false);
    }
    look_token = -1;
    return (true);
}

int
lexer(void) {
    size_t state = START_STATE;
    int last_Match = T_ERROR;

    size_t len = 0;

    char const* beg_lexeme = (stream) ? (stream + stream_pos) : (NULL);

    if (look_token != -1) {
        last_Match = look_token;
        look_token = -1;
        return (last_Match);
    }
    if ((!stream) || (!stream[stream_pos]))
        { return (T_EOF); }

    while (1) {
        if (!stream[stream_pos])
            { state = DEAD_STATE; }
        else
            { state = g_corewar_state_table[state][(unsigned char)stream[stream_pos]]; }
        for (size_t j = 0; *g_corewar_final_table[j]; ++j) {
            if (*g_corewar_final_table[j] == state) {
                last_Match = g_corewar_final_table[j][1];
                len = ((stream + stream_pos) - beg_lexeme) + 1; 
                break;
            }
        }

        if (state == DEAD_STATE) {
            bool skip = false;
            for (size_t j = 0; g_corewar_skip_table[j]; ++j) {
                if (g_corewar_skip_table[j] == last_Match) {
                    skip = true;
                    break;
                }
            }

            if (!skip) {
                if ((last_Match != T_ERROR) && (last_Match != T_EOF)) {
                    char* lexeme = (char*)malloc(sizeof(char)*(len+1));
                    if (lexeme) {
                        ft_strncpy(lexeme, beg_lexeme, len);
                        lexeme[len] = '\0';
                    }
                    if ((!lexeme) || (add_lexeme(lexeme) == -1)) {
                        last_Match = T_ERROR;
                        break;
                    }
                }
                break;
            }

            beg_lexeme = (stream + stream_pos);

            last_Match = T_ERROR;
            state = START_STATE;

            continue;
        }
        if (stream[stream_pos] == '\n')
            { ++lineno; }
        ++stream_pos;
    }
    look_token = -1;
    return (last_Match);
}


void
clean_lexer(void) {
    free((void*)stream);
    free_lexeme_list(list_lexeme);
}

bool 
is_eof(void) {
    return (peek_token() == T_EOF);
}


bool
is_error(void) {
    return (peek_token() == T_ERROR);
}

bool
is_in_first(int token_kind, ...) {
    va_list args;
    int next_token_kind;
    bool result = false;
    if (peek_token() == token_kind)
        { return (true); }
    va_start(args, token_kind);
    while ((next_token_kind = va_arg(args, int)) != END_LOOK) {
        if (peek_token() == next_token_kind) {
            result = true;
            break;
        }
    }
    va_end(args);
    return (result);
}

