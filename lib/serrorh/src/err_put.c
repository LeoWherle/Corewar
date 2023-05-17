/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** err_put
*/

#include <unistd.h>
#include "serrorh.h"

void err_put(const char *str)
{
    size_t len = 0;

    if (!str)
        return;
    while (str[len]) {
        len++;
    }
    write(2, str, len);
}

void err_printchar(va_list ap)
{
    char c = va_arg(ap, int);

    write(2, &c, 1);
}

void err_printstr(va_list ap)
{
    char *str = va_arg(ap, char *);

    err_put(str);
}
