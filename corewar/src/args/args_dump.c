/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** functions to handle dump option
*/

#include <unistd.h>
#include <stddef.h>
#include "args.h"
#include "mystr.h"

/**
 * @brief check if the dump option is correct and fill it
 *
 * @param args args struct with all the infos
 * @param av argv list (user input)
 * @param index argv position
 * @return int 0 on success, 84 on failure
 */
static int check_dump_error(args_t *args, const char *av[], int index)
{
    if (my_strcmp(av[index], "-dump") == 0) {
        if (args->dump == true) {
            write(2, "Error: -dump option can't be used twice.\n", 41);
            return (84);
        }
        args->dump = true;
        if (av[index + 1] == NULL || !my_str_isnum(av[index + 1])) {
            write(2, "Error: -dump option need a cycle number.\n", 41);
            return (84);
        }
        args->dump_cycle = my_getnbr(av[index + 1]);
        if (args->dump_cycle < 0) {
            write(2, "Error: -dump option need a positive number.\n", 45);
            return (84);
        }
    }
    return (0);
}

/**
 * @brief Try to get the dump option
 *
 * @param args args struct with all the infos
 * @param av argv list (user input)
 * @return int 0 on success, 84 on failure
 */
int get_dump(args_t *args, const char *av[])
{
    int index = 0;

    while (av[index] != NULL) {
        if (check_dump_error(args, av, index) != 0)
            return (84);
        index++;
    }
    return (0);
}
