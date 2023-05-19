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

void make_coding_byte(command_t *new, char *type)
{
    new->coding_byte = 0;
    for (int i = 0; i < op_tab[new->code_command - 1].nbr_args; i++) {
        new->coding_byte <<= 2;
        new->coding_byte += type[i];
    }
    for (int i = 0; i < MAX_ARGS_NUMBER -
        op_tab[new->code_command - 1].nbr_args; i++) {
        new->coding_byte <<= 2;
    }
}

bool line_to_command(command_t *com)
{
    make_coding_byte(com, com->param_type);
    com->parameters = get_param(com->param_size, com->param_type,
                                com->line, com->code_command - 1);
    ASSERT_MALLOC(com->parameters, false);
    return true;
}
