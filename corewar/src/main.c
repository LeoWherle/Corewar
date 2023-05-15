/*
** EPITECH PROJECT, 2023
** 42sh [WSL: fedora]
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "clist.h"
#include "args.h"

int main(int ac, char *av[])
{
    args_t *args = malloc(sizeof(args_t));

    args = get_args(ac, av, args);
    if (args == NULL)
        return 84;
    return 0;
}
