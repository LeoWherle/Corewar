/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** args adress for champ
*/

#include <unistd.h>
#include "args.h"
#include "mystr.h"

/**
 * @brief check if the address is available
 *
 * @param champions champions list
 * @param prog_address tested address
 * @return true if available
 * @return false if not available
 */
static bool is_available_adress(champ_arg_t *champions, int prog_address)
{
    unsigned int index = 0;

    while (champions[index].load_address != false) {
        if (champions[index].load_address_value == prog_address)
            return (false);
        index++;
    }
    return (true);
}

/**
 * @brief handle the -a option errors
 *
 * @param champions champions list
 * @param av argv list (user input)
 * @param index current arg index
 * @param champ current champ index
 * @return int 0 on success, 84 on failure
 */
int handle_prog_address(champ_arg_t *champions, const char *av[], unsigned int
index, unsigned int champ)
{
    if (av[index + 1] != NULL && av[index + 1][0] != '-'
    && my_str_isnum(av[index + 1])) {
        if (champions[champ].load_address == true) {
            write(2, "Error: -a option can't be used twice.\n", 38);
            return (84);
        }
        if (!is_available_adress(champions, my_getnbr(av[index + 1]))) {
            write(2, "Error: same address used twice.\n", 32);
            return (84);
        }
        champions[champ].load_address = true;
        champions[champ].load_address_value = my_getnbr(av[index + 1]);
    } else {
        write(2, "Error: -a option need a number.\n", 32);
        return (84);
    }
    return (0);
}
