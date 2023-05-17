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
    if (header_parser(&header, fd) == 84)
        return 84;
    fclose(fd);
    print_comp(com_list, &header, av[1]);
    return 0;
}
