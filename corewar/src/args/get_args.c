/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get vm args
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>
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

static bool is_available_prog_nb(champ_arg_t *champions, int prog_nb)
{
    uint index = 0;

    while (champions[index].prog_number != false) {
        if (champions[index].prog_number_value == prog_nb)
            return (false);
        index++;
    }
    return (true);
}

static bool is_available_adress(champ_arg_t *champions, int prog_address)
{
    uint index = 0;

    while (champions[index].load_address != false) {
        if (champions[index].load_address_value == prog_address)
            return (false);
        index++;
    }
    return (true);
}

static int handle_prog_nb(champ_arg_t *champions, char *av[], uint index,
uint champ)
{
    if (av[index + 1] != NULL && my_str_isnum(av[index + 1])) {
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

static int handle_prog_address(champ_arg_t *champions, char *av[], uint index,
uint champ)
{
    if (av[index + 1] != NULL && my_str_isnum(av[index + 1])) {
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

static int handle_champ_name(champ_arg_t *champions, char *av[], uint index,
uint champ)
{
    champions[champ].name = av[index];
    return (0);
}

static int fill_champs(champ_arg_t *champions, char *av[])
{
    uint index = 1;
    uint champ = 0;
    int error = 1;
    int old_index = 0;

    while (av[index] != NULL) {
        old_index = index;
        if (my_strcmp(av[old_index], "-n") == 0) {
            error = handle_prog_nb(champions, av, old_index, champ);
            index += 2;
        }
        if (my_strcmp(av[old_index], "-a") == 0) {
            error = handle_prog_address(champions, av, old_index, champ);
            index += 2;
        }
        if (my_strcmp(av[old_index], "-dump") == 0) {
            error = 0;
            index += 2;
        }
        if (av[old_index][0] != '-' && (old_index == 0 || av[old_index - 1][0]
        != '-')) {
            error = handle_champ_name(champions, av, old_index, champ);
            champ++;
            index++;
        }
        if (error != 0)
            return (84);
        error = 1;
    }
    return (0);
}

static int check_all_champ(champ_arg_t *champions, int nb_champions)
{
    int index = 0;

    if (nb_champions < 2) {
        write(2, "Error: 2 champions minimum are required.\n", 41);
        return (84);
    }
    if (nb_champions > 4) {
        write(2, "Error: 4 champions maximum are required.\n", 41);
        return (84);
    }
    for (;champions[index].name != NULL; index++);
    if (champions[index].load_address || champions[index].prog_number) {
        write(2, "Error: missing champion name.\n", 30);
        return (84);
    }
    return (0);
}

args_t *get_args(int ac, char *av[], args_t *args)
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
    return (args);
}
