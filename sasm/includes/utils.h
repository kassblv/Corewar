#ifndef UTILS_H
#define UTILS_H

#include <stdarg.h>
#include "../../libft/libft.h"
#include <unistd.h>
#include <stdbool.h>

#define RED_COLOR       ("\e[31m")
#define GREEN_COLOR     ("\e[32m")
#define ORANGE_COLOR    ("\e[33m")
#define NO_COLOR        ("\e[0m")

void errorf(size_t, char const*, ...);
void completef(bool, char const*, ...);
void pendingf(bool, char const*, ...);

#endif /* UTILS_H */
