/*
** EPITECH PROJECT, 2023
** main
** File description:
** asm
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "clist.h"
#include "mystr.h"
#include "op.h"
#include "asm.h"

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

static int free_list(list_t *com_list, list_t *label_list, int r)
{
    free(label_list->interface);
    list_destroy(label_list, free_label);
    list_destroy(com_list, free_command);
    return r;
}

int compile_and_print(list_t *com_list, list_t *label_list,
                    header_t *header, char **av)
{
    if (!search_in_command(com_list, label_list)) {
        return free_list(com_list, label_list, 84);
    }
    for (node_t *node = com_list->head; node; node = node->next) {
        if (!line_to_command(node->data)) {
            return free_list(com_list, label_list, 84);;
        }
    }
    if (!print_comp(com_list, header, av[1])) {
        return free_list(com_list, label_list, 84);
    }
    return free_list(com_list, label_list, 0);
}

int main(int ac, char **av)
{
    list_t *com_list = list_init();
    list_t *label_list = list_init();
    header_t header = {0};
    FILE *fd = NULL;

    if (ac != 2)
        return free_list(com_list, label_list, 84);
    fd = fopen(av[1], "r");
    if (!fd)
        return free_list(com_list, label_list, 84);
    header.magic = COREWAR_EXEC_MAGIC;
    header.prog_size = 0;
    if (header_parser(&header, fd) == 84)
        return free_list(com_list, label_list, 84);
    fseek(fd, 0, SEEK_SET);
    if (code_parser(&header, fd, com_list, label_list) == 84)
        return free_list(com_list, label_list, 84);
    fclose(fd);
    return compile_and_print(com_list, label_list, &header, av);
}
