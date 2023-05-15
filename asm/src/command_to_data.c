/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** comand to data
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mystr.h"
#include "asm.h"
#include "op.h"
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

int *get_size(char *type, int index)
{
    int *size = NULL;

    size = malloc(op_tab[index].nbr_args * sizeof(int));
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
    memset(new, 0, param_size);
    for (int i = 0; i < op_tab[index].nbr_args; i++)
        mv = arg_type[type[i] - 1].ptr(new, arg[i + 1], mv, param_size[i]);
    return new;
}

void make_coding_byte(command_t *new, char *type)
{
    new->coding_byte = 0;
    for (int i = 0; i < op_tab[new->code_command].nbr_args; i++) {
        new->coding_byte <<= 2;
        new->coding_byte += type[i];
    }
    for (int i = 0; i < MAX_ARGS_NUMBER - op_tab[new->code_command].nbr_args;
        i++) {
        new->coding_byte <<= 2;
    }
}

bool line_to_command(command_t *com)
{
    make_coding_byte(com, com->param_type);
    com->parameters = get_param(com->param_size, com->param_type,
                                com->line, com->param_size);
    ASSERT_MALLOC(com->parameters, false);
    return true;
}
