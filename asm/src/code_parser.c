/*
** EPITECH PROJECT, 2023
** asm
** File description:
** assembly parser
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "clist.h"
#include "mystr.h"
#include "op.h"
#include "asm.h"

int get_instrucion(char *instruction)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(instruction, op_tab[i].mnemonique) == 0)
            return i + 1;
    }
    return -1;
}

void put_label_in_list(char **args, list_t *label_list, int prog_size)
{
    label_t *lab = NULL;

    if (args[0][my_strlen(args[0]) - 1] == LABEL_CHAR) {
        lab = malloc(sizeof(label_t));
        ASSERT_MALLOC(lab, 84);
        lab->name = malloc(sizeof(char) * my_strlen(args[0]));
        ASSERT_MALLOC(lab->name, 84);
        my_strcpy(lab->name, args[0]);
        lab->ad = prog_size;
        node_append(label_list, lab);
        args = args + 1;
    }
}

int put_command_in_list(char **args, list_t *com_list, header_t *header)
{
    int inst_in = get_instrucion(args[0]);
    char *type = get_type(args, inst_in);
    int *size = get_size(args, inst_in);
    command_t *new = NULL;

    ASSERT_MALLOC(type, 84);
    ASSERT_MALLOC(size, 84);
    for (int i = 0; type[i] != '\0'; i++)
        if (type[i] == 0)
            return 84;
    for (int i = 0; size[i] != '\0'; i++)
        header->prog_size += size[i];
    new = malloc(sizeof(command_t));
    ASSERT_MALLOC(new, 84);
    new->code_command = inst_in;
    new->param_type = type;
    new->param_size = size;
    new->line = args;
    node_append(com_list, new);
}

int check_syntax(char *line, char *instruction)
{
    char **comma_args = my_str_to_word_array(line, ",");
    int inst_in = 0;
    int nb_args = 0;

    if (!comma_args)
        return 84;
    inst_in = get_instrucion(instruction);
    if (inst_in == -1)
        return 84;
    for (int i = 0; comma_args[i]; i++)
        nb_args++;
    if (nb_args + 1 != op_tab[inst_in - 1].nbr_args)
        return 84;
}

int code_parser(header_t *header, FILE *fd, list_t *com_list,
                list_t *label_list)
{
    char *line = NULL;
    char **args = NULL;
    size_t len = 0;

    while (getline(&line, &len, fd) != -1) {
        args = my_str_to_word_array(line, " \t,");
        ASSERT_MALLOC(args, 84);
        put_label_in_list(args, label_list, header->prog_size);
        if (check_syntax(line, args[0]) == 84)
            return 84;
        put_command_in_list(args, com_list, header);
    }
}
