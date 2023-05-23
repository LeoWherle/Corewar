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
            return i;
    }
    return -1;
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
    nb_args = matrix_len(comma_args);
    if (nb_args != op_tab[inst_in].nbr_args)
        return 84;
    free_matrix(comma_args);
    return 0;
}

bool parse_line(char *line, int shift, char **args)
{
    if (shift == 84) {
        free(line);
        return false;
    }
    if (check_syntax(line, args[shift]) == 84) {
        free(line);
        return false;
    }
    free(line);
    return true;
}

static void free_linarg(char *line, char **args)
{
    free(line);
    free_matrix(args);
}

int code_parser(header_t *header, FILE *fd, list_t *com_list,
                list_t *label_list)
{
    char *line = NULL, **args = NULL;
    int len = 0, shift = 0;
    while (getline(&line, &len, fd) != -1) {
        line = clear_line(line);
        args = my_str_to_word_array(line, " \t,\n");
        ASSERT_MALLOC(args, 84);
        if (line[0] == '\0' || line[0] == '\n' || line[0] == '.') {
            free_linarg(line, args);
            line = NULL;
            continue;
        }
        shift = put_label_in_list(args, label_list, header->prog_size);
        if (matrix_len(args) == shift) continue;
        if (!parse_line(line, shift, args)) return 84;
        if (check_valid_line(args + shift, com_list, header) == 84) return 84;
        free_matrix(args);
        line = NULL;
    }
    free(line);
    return 0;
}
