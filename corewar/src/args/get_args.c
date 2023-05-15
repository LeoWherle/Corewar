/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get vm args
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "op.h"
#include "args.h"
#include "herror.h"
#include "mystr.h"

static void init_args(args_t *args)
{
    args->dump = 0;
    args->dump_cycle = 0;
    args->nb_champions = 0;
    args->champions = NULL;
}

static int count_champions(int ac, char **av)
{
    int nb_champions = 0;
    int i = 1;

    for (; i < ac; i++) {
        if (av[i][0] != '-' && (i == 0 || av[i - 1][0] != '-'))
            nb_champions++;
    }
    return nb_champions;
}

static void init_champion(champ_arg_t *champions, int nb_champions)
{
    int index = 0;

    while (index <= nb_champions) {
        champions[index] = (champ_arg_t){NULL, false, 0, false, 0};
        index++;
    }
}

static int get_dump(args_t *args, char *av[])
{
    int index = 0;

    while (av[index] != NULL) {
        if (my_strcmp(av[index], "-dump") == 0) {
            args->dump = 1;
            if (av[index + 1] == NULL || !my_str_isnum(av[index + 1])) {
                write(2, "Error: -dump option need a cycle number.\n", 41);
                return (84);
            }
            args->dump_cycle = my_getnbr(av[index + 1]);
            return (0);
        }
        index++;
    }
    return (0);
}

static int handle_prog_nb()
{
    
}

static int get_champ(champ_arg_t *champion, char *av[])
{
    int index = 1;
    int champ = 0;

    while (av[index] != NULL) {
        if (av[index][0] != '-' && (index == 0 || av[index - 1][0] != '-')) {
            champion[champ].name = av[index];
            if (index > 1 && my_strcmp(av[index - 2], "-n") == 0) {
                champion->prog_number = true;
                if (!my_str_isnum(av[index - 1])) {
                    write(2, "Error: -n option need a number.\n", 32);
                    return (84);
                }
                champion[champ].prog_number_value = my_getnbr(av[index - 1]);
                champ++;
            }
        }
        index++;
    }
    return (0);
}

args_t *get_args(int ac, char *av[], args_t *args)
{
    init_args(args);
    args->nb_champions = count_champions(ac, av);
    if (ac < 2 || args->nb_champions < 2) {
        write(2, "Error: 2 champions minimum are required.\n", 41);
        return (NULL);
    }
    args->champions = malloc(sizeof(champ_arg_t) * (args->nb_champions + 1));
    ASSERT_MALLOC(args->champions, NULL);
    init_champion(args->champions, args->nb_champions);
    if (get_dump(args, av) != 0)
        return (NULL);
    if (get_champ(args->champions, av) != 0)
        return (NULL);
    printf("name: %s|%d\n", args->champions[0].name, args->champions[0].prog_number_value);
    return (args);
}
