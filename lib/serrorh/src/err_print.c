/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** err_print
*/

#include <unistd.h>
#include <stdarg.h>
#include "serrorh.h"

static void varg_print(const char *fmt, va_list ap)
{
    char *tmp = NULL;

    while (*fmt) {
        if (*fmt == '%' && *(fmt + 1) == 's') {
            tmp = va_arg(ap, char *);
            err_put(tmp);
            fmt++;
        } else {
            write(2, fmt, 1);
        }
        fmt++;
    }
}

void err_print(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    varg_print(fmt, ap);
    va_end(ap);
}

void expr_assert(int expr, const char *fmt, ...)
{
    va_list ap;

    if (!expr) {
        va_start(ap, fmt);
        varg_print(fmt, ap);
        va_end(ap);
    }
}
