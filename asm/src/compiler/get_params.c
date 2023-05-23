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
    for (int i = 0; i < op_tab[index].nbr_args; i++)
        type[i] = 0;
    for (int i = 1; arg[i]; i++) {
        if (arg[i][0] == 'r' && (op_tab[index].type[i - 1] & T_REG)) {
            type[i - 1] = REG_CODE;
        }
        if (arg[i][0] == DIRECT_CHAR && (op_tab[index].type[i - 1] & T_DIR)) {
            type[i - 1] = DIR_CODE;
        }
        if (((arg[i][0] >= '0' && arg[i][0] <= '9') ||
            arg[i][0] == LABEL_CHAR || arg[i][0] == '-') &&
            (op_tab[index].type[i - 1] & T_IND)) {
            type[i - 1] = IND_CODE;
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
static bool special_cases(int index, int i, char type)
{
    if (type == REG_CODE)
        return false;
    if ((index == 8 || index == 11 || index == 14) && i == 0)
        return true;
    if (index == 10 && (i == 1 || i == 2))
        return true;
    if ((index == 9 || index == 13) && (i == 0 || i == 1))
        return true;
    return false;
}

int *get_size(char *type, int index)
{
    int *size = NULL;

    size = malloc(op_tab[index].nbr_args * sizeof(int));
    ASSERT_MALLOC(size, NULL);
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        if (type[i] == REG_CODE)
            size[i] = 1;
        if (type[i] == DIR_CODE)
            size[i] = DIR_SIZE;
        if (special_cases(index, i, type[i]) || type[i] == IND_CODE)
            size[i] = IND_SIZE;
    }
    return size;
}

char *get_param(int *param_size, char *type, char **arg, int index)
{
    char *new = NULL;
    int mv = 0;
    int size = 0;

    for (int i = 0; i < op_tab[index].nbr_args; i++)
        size = size + param_size[i];
    new = malloc(size * sizeof(char));
    ASSERT_MALLOC(new, NULL);
    for (int i = 0; i < size; i++)
        new[i] = 0;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        mv = arg_type[type[i] - 1].ptr(new, arg[i + 1], mv, param_size[i]);
    }
    return new;
}
