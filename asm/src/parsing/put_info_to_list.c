/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** put info to list
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "clist.h"
#include "mystr.h"
#include "op.h"
#include "asm.h"

command_t *get_command_struct(int inst_in, char *type, int *size, char **args)
{
    command_t *new = NULL;
    int len = 0;

    new = malloc(sizeof(command_t));
    ASSERT_MALLOC(new, NULL);
    initilalize_com(new);
    new->code_command = inst_in + 1;
    new->param_type = type;
    new->param_size = size;
    len = matrix_len(args);
    new->line = malloc((len + 1) * sizeof(char *));
    ASSERT_MALLOC(new->line, NULL);
    for (int i = 0; i < len; i++) {
        new->line[i] = my_strdup(args[i]);
        ASSERT_MALLOC(new->line[i], NULL);
    }
    new->line[len] = NULL;
    return new;
}

bool check_valid_reg(char *type, char **args, int i)
{
    int reg = 0;

    if (type[i] == REG_CODE) {
        reg = my_getnbr(args[i + 1] + 1);
        if (reg < 1 || reg > REG_NUMBER || !my_str_isnum(args[i + 1] + 1))
            return 0;
    }
    return 1;
}

bool check_valid_type(char **args, char *type, int inst_in)
{
    for (int i = 0; i < op_tab[inst_in].nbr_args; i++) {
        if (!check_valid_reg(type, args, i))
            return 0;
        if (type[i] == 0)
            return 0;
    }
    return 1;
}

int check_valid_line(char **args, list_t *com_list, header_t *header)
{
    int inst_in = get_instrucion(args[0]);
    char *type = get_type(args, inst_in);
    int *size = get_size(type, inst_in);
    command_t *new = NULL;

    ASSERT_MALLOC(type, 84);
    ASSERT_MALLOC(size, 84);
    if (!check_valid_type(args, type, inst_in)) {
        free(type);
        free(size);
        return 84;
    }
    for (int i = 0; i < op_tab[inst_in].nbr_args ; i++)
        header->prog_size += size[i];
    header->prog_size +=
    (op_tab[inst_in].nbr_args == 1 && inst_in != 15) ? 1 : 2;
    new = get_command_struct(inst_in, type, size, args);
    ASSERT_PTR(new, 84);
    node_append(com_list, new);
    return 0;
}
