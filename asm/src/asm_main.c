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
    if (!search_in_command(com_list, label_list))
        return 84;
    for (node_t *node = com_list->head; node; node = node->next)
        if (!line_to_command(node->data))
            return 84;
    if (!print_comp(com_list, header, av[1]))
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    list_t *com_list = list_init();
    list_t *label_list = list_init();
    header_t header = {0};
    FILE *fd = NULL;

    if (ac != 2)
        return 84;
    fd = fopen(av[1], "r");
    ASSERT_PTR(fd, 84);
    header.magic = COREWAR_EXEC_MAGIC;
    header.prog_size = 0;
    if (header_parser(&header, fd) == 84)
        return 84;
    if (code_parser(&header, fd, com_list, label_list) == 84)
        return 84;
    fclose(fd);
    return compile_and_print(com_list, label_list, &header, av);
}
