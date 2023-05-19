/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** err_print
*/

#include <unistd.h>
#include <stdarg.h>
#include "serrorh.h"

static const struct flag_s flags[] = {
    {'s', &err_printstr},
    {'d', &err_printnbr},
    {'c', &err_printchar},
    {'u', &err_printnbr_u},
    {'l', &err_printnbr_l},
};

static void varg_print_arg(const char *fmt, va_list ap)
{
    for (unsigned int i = 0; i < sizeof(flags) / sizeof(struct flag_s); i++) {
        if (*(fmt + 1) == flags[i].flag) {
            flags[i].fptr(ap);
        }
    }
}

static void varg_print(const char *fmt, va_list ap)
{
    while (*fmt) {
        if (*fmt == '%' && IS_FLAG(*(fmt + 1))) {
            varg_print_arg(fmt, ap);
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
