/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** functions to handle the program nb in champions
*/

#include <unistd.h>
#include "args.h"
#include "mystr.h"

/**
 * @brief check if the prog nb is available
 *
 * @param champions champions list
 * @param prog_nb tested nb
 * @return true if available
 * @return false if not available
 */
static bool is_available_prog_nb(champ_arg_t *champions, int prog_nb)
{
    unsigned int index = 0;

    while (champions[index].prog_number != false) {
        if (champions[index].prog_number_value == prog_nb)
            return (false);
        index++;
    }
    return (true);
}

/**
 * @brief fill the champion program nb when they don't have one
 *
 * @param champions list of champions
 */
void fill_empty_pg_nb(champ_arg_t *champions)
{
    unsigned int index = 0;
    unsigned int pg_nb = 1;

    while (champions[index].name != NULL) {
        while (!is_available_prog_nb(champions, pg_nb))
            pg_nb++;
        if (champions[index].prog_number == false) {
            champions[index].prog_number = true;
            champions[index].prog_number_value = pg_nb;
        }
        index++;
    }
}

/**
 * @brief handle the -n option errors
 *
 * @param champions champions list
 * @param av argv list (user input)
 * @param index current arg index
 * @param champ current champ index
 * @return int 0 on success, 84 on failure
 */
int handle_prog_nb(champ_arg_t *champions, const char *av[], unsigned int index,
unsigned int champ)
{
    if (av[index + 1] != NULL && av[index + 1][0] != '-'
    && my_str_isnum(av[index + 1])) {
        if (champions[champ].prog_number == true) {
            write(2, "Error: -n option can't be used twice.\n", 38);
            return (84);
        }
        if (!is_available_prog_nb(champions, my_getnbr(av[index + 1]))) {
            write(2, "Error: same prog nb used twice.\n", 32);
            return (84);
        }
        champions[champ].prog_number = true;
        champions[champ].prog_number_value = my_getnbr(av[index + 1]);
    } else {
        write(2, "Error: -n option need a number.\n", 32);
        return (84);
    }
    return (0);
}
