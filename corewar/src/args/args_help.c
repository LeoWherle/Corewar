/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** helper flag on VM
*/

#include <unistd.h>
#include "mystr.h"

static void print_helper(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./corewar [-dump nbr_cycle] [[-n prog_number]", 47);
    write(1, " [-a load_address] prog_name] ...\n", 34);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\t-dump nbr_cycle dumps the memory after the nbr_cycle", 52);
    write(1, " execution (if the round isn't already over) with the", 52);
    write(1, " following format: 32 bytes/line\n", 33);
    write(1, "\tin hexadecimal (A0BCDEFE1DD3...)\n", 34);
    write(1, "\t-n prog_number sets the next program's number. By", 49);
    write(1, " default, the first free number in the parameter order\n", 55);
    write(1, "\t-a load_address sets the next program's loading", 49);
    write(1, " address. When no address is specified, optimize the", 51);
    write(1, " addresses so that the processes are as far away from", 52);
    write(1, " each other as possible. The addresses are MEM_SIZE", 50);
    write(1, " modulo.\n", 9);
}

/**
 * @brief detect if the helper flag is present and print the helper
 *
 * @param av arguments list (user input)
 * @return int 0 if no helper flag, 1 if helper flag
 */
int detect_helper_flag(const char *av[])
{
    int index = 1;

    while (av[index] != NULL) {
        if (my_strcmp(av[index], "-h") == 0) {
            print_helper();
            return (1);
        }
        index++;
    }
    return (0);
}
