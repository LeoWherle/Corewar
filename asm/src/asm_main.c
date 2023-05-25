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

int compile_and_print(list_t *com_list, list_t *label_list,
                    header_t *header, char **av)
{
    if (!search_in_command(com_list, label_list)) {
        return free_list(com_list, label_list, 84);
    }
    for (node_t *node = com_list->head; node; node = node->next) {
        if (!line_to_command(node->data)) {
            return free_list(com_list, label_list, 84);
        }
    }
    if (!print_comp(com_list, header, av[1])) {
        return free_list(com_list, label_list, 84);
    }
    return free_list(com_list, label_list, 0);
}

FILE *open_file(char *name, header_t *header)
{
    FILE *fd = NULL;

    fd = fopen(name, "r");
    if (!fd)
        return NULL;
    if (my_strcmp(name + my_strlen(name) - 2, ".s") != 0) {
        fclose(fd);
        return NULL;
    }
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    return fd;
}

int parsing_main(header_t *header, list_t *com_list,
                    list_t *label_list, FILE *fd)
{
    if (header_parser(header, fd) == 84) {
        fclose(fd);
        return 84;
    }
    fseek(fd, 0, SEEK_SET);
    if (code_parser(header, fd, com_list, label_list) == 84) {
        fclose(fd);
        return 84;
    }
    fclose(fd);
    return 0;
}

int main(int ac, char **av)
{
    list_t *com_list = NULL;
    list_t *label_list = NULL;
    header_t header = {0};
    FILE *fd = NULL;

    if (ac != 2)
        return 84;
    fd = open_file(av[1], &header);
    if (!fd)
        return 84;
    com_list = list_init();
    label_list = list_init();
    if (!com_list || !label_list)
        return 84;
    if (parsing_main(&header, com_list, label_list, fd) == 84)
        return free_list(com_list, label_list, 84);
    return compile_and_print(com_list, label_list, &header, av);
}
