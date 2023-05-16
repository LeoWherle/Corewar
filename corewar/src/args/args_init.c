/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get vm args
*/

#include <stdlib.h>
#include <stddef.h>
#include "args.h"
#include "herror.h"


/**
 * @brief init the args struct with default infos
 *
 * @param args args struct empty but malloc
 */
static void init_args(args_t *args)
{
    args->dump = 0;
    args->dump_cycle = 0;
    args->nb_champions = 0;
    args->champions = NULL;
}

/**
 * @brief free the 'args' struct
 *
 * @param args args struct for VM
 */
void free_args_struct(args_t *args)
{
    free(args->champions);
    free(args);
}

/**
 * @brief Get the args options and champions
 *
 * @param ac argv list len (user input)
 * @param av argv list (user input)
 * @param args must be malloc before
 * @return args_t* with all the infos for the vm and NULL on error
 */
args_t *get_args(int ac, const char *av[], args_t *args)
{
    init_args(args);
    args->nb_champions = count_champions(ac, av);
    args->champions = malloc(sizeof(champ_arg_t) * (args->nb_champions + 1));
    ASSERT_MALLOC(args->champions, NULL);
    init_champion(args->champions, args->nb_champions);
    if (get_dump(args, av) != 0)
        return (NULL);
    if (fill_champs(args->champions, av) != 0)
        return (NULL);
    if (check_all_champ(args->champions, args->nb_champions) != 0)
        return (NULL);
    fill_empty_pg_nb(args->champions);
    return (args);
}
