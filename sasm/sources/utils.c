#include "../includes/utils.h"

#include <stdio.h>

static void
print_error(size_t lineno, char const* label, char const* color,
                                char const* format, va_list args) {
    int tty = isatty(STDERR_FILENO);
    if (tty)
        { fprintf(stderr, "%s", color); }
    fprintf(stderr, "[%s", label);
    if (lineno)
        { fprintf(stderr, ":%zu", lineno); }
    fprintf(stderr, "] ");
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    if (tty)
        { fprintf(stderr, NO_COLOR); }
}

void
errorf(size_t lineno, char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    print_error(lineno, "ERROR", RED_COLOR, fmt, args);
    va_end(args);
}

void
completef(bool print, char const* fmt, ...) {
    if (!print)
        { return; }
    va_list args;
    va_start(args, fmt);
    print_error(0, "COMPLETE", GREEN_COLOR, fmt, args);
    va_end(args);
}

void
pendingf(bool print, char const* fmt, ...) {
    if (!print)
        { return; }
    va_list args;
    va_start(args, fmt);
    print_error(0, "PENDING", ORANGE_COLOR, fmt, args);
    va_end(args);
}

