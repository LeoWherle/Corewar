/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** add param
*/

#include <stdlib.h>
#include "mystr.h"
#include "op.h"
#include "asm.h"

long int power_long(long int base, long int exp)
{
    long int r = 1;

    for (int i = 0; i < exp; i++)
        r *= base;
    return r;
}

static void add_int(char *dest, long int nb, int i, int delta)
{
    long int order = 0;
    int cond = 0;

    order = power_long(2, delta * 8);
    for (int x = i; x < i + delta; x++) {
        for (int y = 0; y < 8; y++) {
            cond = (nb & order);
            dest[x] += cond;
            nb -= cond;
            order /= 2;
        }
    }
    cond = (nb & order);
    dest[i + delta - 1] += cond;
}

int add_register(char *dest, char *arg, int i)
{
    int reg = 0;

    reg = my_getnbr(&arg[1]);
    add_int(dest, reg, i, REG_SIZE);
    return i + REG_SIZE;
}

int add_direct(char *dest, char *arg, int i)
{
    int dir = 0;

    dir = my_getnbr(&arg[1]);
    add_int(dest, dir, i, DIR_SIZE);
    return i + DIR_SIZE;
}

int add_indirect(char *dest, char *arg, int i)
{
    int ind = 0;

    ind = my_getnbr(arg);
    add_int(dest, ind, i, IND_SIZE);
    return i + IND_SIZE;
}
