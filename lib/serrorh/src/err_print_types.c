/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** err_print_fun
*/

#include <unistd.h>
#include <stdarg.h>
#include "serrorh.h"

static void err_putnbr(long nbr)
{
    char c = 0;

    if (nbr < 10) {
        c = '0' + nbr;
        write(2, &c, 1);
        return;
    }
    err_putnbr(nbr / 10);
    c = '0' + (nbr % 10);
    write(2, &c, 1);
}

void err_printnbr(va_list ap)
{
    int nbr = va_arg(ap, int);
    char c = 0;

    if (nbr < 0) {
        write(2, "-", 1);
        nbr = -nbr;
    }
    if (nbr < 10) {
        c = '0' + nbr;
        write(2, &c, 1);
        return;
    }
    err_putnbr(nbr / 10);
    c = '0' + (nbr % 10);
    write(2, &c, 1);
}

void err_printnbr_u(va_list ap)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char c = 0;

    if (nbr < 10) {
        c = '0' + nbr;
        write(2, &c, 1);
        return;
    }
    err_putnbr(nbr / 10);
    c = '0' + (nbr % 10);
    write(2, &c, 1);
}

void err_printnbr_l(va_list ap)
{
    unsigned long nbr = va_arg(ap, unsigned long);
    char c = 0;

    if (nbr < 10) {
        c = '0' + nbr;
        write(2, &c, 1);
        return;
    }
    err_putnbr(nbr / 10);
    c = '0' + (nbr % 10);
    write(2, &c, 1);
}
