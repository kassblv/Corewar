$TOKEN
{
    NAME        = / \.(?i:name)             / ;
    COMMENT     = / \.(?i:comment)          / ;
    STR         = / \"[^"\n]*\"             / ;
    LABEL_NAME  = / [[:alpha:][:digit:]_]+  / -> $FRAGMENT ;
    LABEL       = / {LABEL_NAME}:           / ;
    REGT        = / [rR]([2-9]|1[0-6]?)     / ;
    NUM         = / [+-]?([[:digit:]]+)     / -> $FRAGMENT ;
    INDIRECT    = / ({NUM}|:{LABEL_NAME})   / ;
    DIRECT      = / %{INDIRECT}             / ;
    SEP         = / ,                       / ;
    LFORK       = / (?i:lfork)              / ;
    STI         = / (?i:sti)                / ;
    FORK        = / (?i:fork)               / ;
    LLD         = / (?i:lld)                / ;
    LD          = / (?i:ld)                 / ;
    ADD         = / (?i:add)                / ;
    ZJMP        = / (?i:zjmp)               / ;
    SUB         = / (?i:sub)                / ;
    LDI         = / (?i:ldi)                / ;
    OR          = / (?i:or)                 / ;
    ST          = / (?i:st)                 / ;
    AFF         = / (?i:aff)                / ;
    LIVE        = / (?i:live)               / ;
    XOR         = / (?i:xor)                / ;
    LLDI        = / (?i:lldi)               / ;
    AND         = / (?i:and)                / ;
    NEWLINE     = / \n                      / ;
    UNKNOWN     = / [[:alpha:]_][[:alpha:][:digit:]_]*  / ;
};

$SKIP
{
    SCOMMENT    = / (#|;).*                 / ;
    SPACE       = / [ \t]+                  / ;
};

