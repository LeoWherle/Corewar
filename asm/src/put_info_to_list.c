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

int put_label_in_list(char **args, list_t *label_list, int prog_size)
{
    label_t *lab = NULL;

    if (args[0][my_strlen(args[0]) - 1] == LABEL_CHAR) {
        lab = malloc(sizeof(label_t));
        ASSERT_MALLOC(lab, 84);
        lab->name = malloc(sizeof(char) * my_strlen(args[0]) + 1);
        ASSERT_MALLOC(lab->name, 84);
        lab->name[0] = '\0';
        my_strcpy(lab->name, args[0]);
        lab->ad = prog_size;
        node_append(label_list, lab);
        return 1;
    }
    return 0;
}

command_t *get_command_struct(int inst_in, char *type, int *size, char **args)
{
    command_t *new = NULL;

    new = malloc(sizeof(command_t));
    ASSERT_MALLOC(new, NULL);
    new->code_command = inst_in + 1;
    new->param_type = type;
    new->param_size = size;
    new->line = args;
    return new;
}

bool check_valid_reg(char *type, char **args, int i)
{
    int reg = 0;

    if (type[i] == REG_CODE) {
        reg = my_getnbr(args[i] + 1);
        if (reg < 1 || reg > REG_NUMBER)
            return 0;
    }
    return 1;
}

bool check_valid_type(char **args, char *type, int inst_in)
{
    int reg = 0;

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
    if (!check_valid_type(args, type, inst_in))
        return 84;
    for (int i = 0; i < op_tab[inst_in].nbr_args ; i++)
        header->prog_size += size[i];
    header->prog_size +=
    (op_tab[inst_in].nbr_args == 1 && inst_in != 15) ? 1 : 2;
    new = get_command_struct(inst_in, type, size, args);
    ASSERT_PTR(new, 84);
    node_append(com_list, new);
    return 0;
}
