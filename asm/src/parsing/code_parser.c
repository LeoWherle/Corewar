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

static int check_syntax(char *line, char *instruction)
{
    char **comma_args = my_str_to_word_array(line, ",");
    int inst_in = 0;
    int nb_args = 0;

    if (!comma_args)
        return 84;
    inst_in = get_instrucion(instruction);
    if (inst_in == -1) {
        free_matrix(comma_args);
        return 84;
    }
    nb_args = matrix_len(comma_args);
    if (nb_args != op_tab[inst_in].nbr_args) {
        free_matrix(comma_args);
        return 84;
    }
    free_matrix(comma_args);
    return 0;
}

static int line_parsing(parser_t *pars, header_t *header, list_t *com_list)
{
    if (pars->shift == 84)
        return 84;
    if (check_syntax(pars->line, pars->args[pars->shift]) == 84)
        return 84;
    if (check_valid_line(pars->args + pars->shift, com_list, header) == 84)
        return 84;
    return 0;
}

static int edge_cases(parser_t *pars, list_t *label_list, header_t *header)
{
    if (pars->line[0] == '\0' || pars->line[0] == '.' ||
    pars->line[0] == '\n') {
        free_line_args(pars);
        pars->line = NULL;
        return 1;
    }
    pars->shift = put_label_in_list(pars->args, label_list, header->prog_size);
    if (matrix_len(pars->args) == pars->shift) {
        free_line_args(pars);
        pars->line = NULL;
        return 1;
    }
    return 0;
}

int code_parser(header_t *header, FILE *fd, list_t *com_list,
                list_t *label_list)
{
    parser_t pars = {NULL, NULL, 0, 0};

    while (getline(&pars.line, &pars.len, fd) != -1) {
        if (pars.line[0] == COMMENT_CHAR)
            continue;
        pars.line = clear_line(pars.line);
        ASSERT_PTR(pars.line, 84);
        pars.args = my_str_to_word_array(pars.line, " \t,\n");
        ASSERT_PTR(pars.args, 84);
        if (edge_cases(&pars, label_list, header))
            continue;
        if (line_parsing(&pars, header, com_list) == 84) {
            free_line_args(&pars);
            return 84;
        }
        free_line_args(&pars);
        pars.line = NULL;
    }
    free(pars.line);
    return 0;
}
