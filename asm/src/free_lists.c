/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free lists
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "clist.h"
#include "mystr.h"
#include "op.h"
#include "asm.h"

void initilalize_com(command_t *com)
{
    com->line = NULL;
    com->code_command = 0;
    com->coding_byte = 0;
    com->param_type = NULL;
    com->param_size = NULL;
    com->parameters = NULL;
}

void free_line_args(parser_t *pars)
{
    free_matrix(pars->args);
    free(pars->line);
}

void free_label(void *ptr)
{
    label_t *label = NULL;

    label = ptr;
    free(label->name);
    free(label);
}

void free_command(void *ptr)
{
    command_t *command = NULL;

    command = ptr;
    free_matrix(command->line);
    free(command->param_type);
    free(command->param_size);
    free(command->parameters);
    free(command);
}

int free_list(list_t *com_list, list_t *label_list, int r)
{
    free(label_list->interface);
    list_destroy(label_list, free_label);
    list_destroy(com_list, free_command);
    return r;
}
