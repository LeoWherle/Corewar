/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** getter
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "op.h"
#include "asm.h"
#include "herror.h"

static const arg_type_t arg_type[3] = {
    {REG_SIZE, add_register},
    {DIR_SIZE, add_direct},
    {IND_SIZE, add_indirect},
};

char *get_type(char **arg, int index)
{
    char *type = NULL;

    type = malloc(op_tab[index].nbr_args * sizeof(char));
    ASSERT_MALLOC(type, NULL);
    for (int i = 1; arg[i]; i++) {
        if (arg[i][0] == 'r') {
            type[i - 1] = 0b1;
        }
        if (arg[i][0] == DIRECT_CHAR) {
            type[i - 1] = 0b10;
        }
        if ((arg[i][0] >= '0' && arg[i][0] <= '9') ||
            arg[i][0] == '-') {
            type[i - 1] = 0b11;
        }
    }
    return type;
}

/*
index:
zjump / fork / lfork 1rst
sti first two
ldi / lldi last two
*/
static bool special_cases(int index, int i)
{
    if ((index == 8 || index == 11 || index == 14) && i == 0)
        return true;
    if (index == 10 && (i == 0 || i == 1))
        return true;
    if ((index == 9 || index == 13) && (i == 1 || i == 2))
        return true;
    return false;
}

int *get_size(char *type, int index)
{
    int *size = NULL;

    size = malloc(op_tab[index].nbr_args * sizeof(int));
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        if (special_cases(index, i) || type[i] == 0b11)
            type[i] = IND_SIZE;
        if (type[i] == 0b1)
            type[i] = REG_SIZE;
        if (type[i] == 0b10)
            type[i] = DIR_SIZE;
    }
    return size;
}

char *get_param(int *param_size, char *type, char **arg, int index)
{
    char *new = NULL;
    int mv = 0;
    int size = 0;

    for (int i = 0; i < op_tab[index].nbr_args; i++)
        size += param_size[i];
    new = malloc(size * sizeof(char));
    ASSERT_MALLOC(new, NULL);
    memset(new, 0, size);
    for (int i = 0; i < op_tab[index].nbr_args; i++)
        mv = arg_type[type[i] - 1].ptr(new, arg[i + 1], mv, param_size[i]);
    return new;
}
