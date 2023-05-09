/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** comand to data
*/

char **turn_str_to_word_array(char const *str, char sep);
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
        if (arg[i][0] >= '0' && arg[i][0] <= '9') {
            type[i - 1] = 0b11;
        }
    }
    return type;
}

char *get_param(int param_size, char *type, char **arg, int index)
{
    char *new = NULL;
    int mv = 0;

    new = malloc(param_size * sizeof(char));
    ASSERT_MALLOC(new, NULL);
    memset(new, 0, param_size);
    for (int i = 0; i < op_tab[index].nbr_args; i++)
        mv = arg_type[type[i] - 1].ptr(new, arg[i + 1], mv);
    return new;
}

void make_coding_byte(command_t *new, char *type, int index)
{
    new->coding_byte = 0;
    new->param_size = 0;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        new->coding_byte <<= 2;
        new->coding_byte += type[i];
        new->param_size += arg_type[type[i] - 1].size;
    }
    for (int i = 0; i < MAX_ARGS_NUMBER - op_tab[index].nbr_args; i++)
        new->coding_byte <<= 2;
}

bool line_to_command(command_t *com, int index)
{
    char **arg = NULL;
    char *type = NULL;

    arg = turn_str_to_word_array(com->line, ' ');
    ASSERT_MALLOC(arg, false);
    com->code_command = op_tab[index].code;
    type = get_type(arg, index);
    ASSERT_MALLOC(type, false);
    make_coding_byte(com, type, index);
    com->parameters = get_param(com->param_size, type, arg, index);
    ASSERT_MALLOC(com->parameters, false);
    return true;
}
