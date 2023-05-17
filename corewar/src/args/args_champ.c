/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arguments for champ manager
*/

#include <unistd.h>
#include "args.h"
#include "mystr.h"

/**
 * @brief count the number of champions
 *
 * @param ac argv list len (user input)
 * @param av argv list (user input)
 * @return int number of champions
 */
int count_champions(int ac, const char *av[])
{
    unsigned int nb_champions = 0;
    int i = 1;

    for (; i < ac; i++) {
        if (av[i][0] != '-' && (i == 0 || av[i - 1][0] != '-'))
            nb_champions++;
    }
    return (nb_champions);
}

/**
 * @brief init the champion struct with default infos
 *
 * @param champions list of champions
 * @param nb_champions number of champions
 */
void init_champion(champ_arg_t *champions, int nb_champions)
{
    int index = 0;

    while (index <= nb_champions) {
        champions[index].load_address = false;
        champions[index].load_address_value = 0;
        champions[index].prog_number = false;
        champions[index].prog_number_value = 0;
        champions[index].name = NULL;
        index++;
    }
}

/**
 * @brief check champion options
 *
 * @param champions champions list
 * @param av argv list (user input)
 * @param old_index index of the option
 * @param champ current champ index
 * @return int 0 on success, 84 on failure and 1 if no option is found
 */
int fill_champs_options(champ_arg_t *champions, const char *av[],
unsigned int old_index, unsigned int champ)
{
    int error = 1;

    if (my_strcmp(av[old_index], "-n") == 0)
        error = handle_prog_nb(champions, av, old_index, champ);
    if (my_strcmp(av[old_index], "-a") == 0)
        error = handle_prog_address(champions, av, old_index, champ);
    if (my_strcmp(av[old_index], "-dump") == 0)
        error = 0;
    return (error);
}

/**
 * @brief fill_champs with the arguments given by the user
 *
 * @param champions list of champions
 * @param av argv list (user input)
 * @return int 0 on success, 84 on failure
 */
int fill_champs(champ_arg_t *champions, const char *av[])
{
    unsigned int index = 1;
    unsigned int champ = 0;
    int error = 1;
    int old_i = 0;

    while (av[index] != NULL) {
        old_i = index;
        error = fill_champs_options(champions, av, old_i, champ);
        if (error == 0)
            index += 2;
        if (av[old_i][0] != '-' && (old_i == 0 || av[old_i - 1][0] != '-')) {
            error = check_champ_name(&champions[champ], av[old_i]);
            champ++;
            index++;
        }
        if (error != 0)
            return (84);
        error = 1;
    }
    return (0);
}
