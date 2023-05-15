/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** args vm manager
*/

#ifndef ARGS_H_
    #define ARGS_H_

    #include <stdbool.h>

    typedef struct champ_arg_s {
        char *name;
        bool prog_number;
        int prog_number_value;
        bool load_address;
        int load_address_value;
    } champ_arg_t;

    typedef struct args_s {
        bool dump;
        int dump_cycle;
        bool graphic;
        int nb_champions;
        champ_arg_t *champions;
    } args_t;

    args_t *get_args(int ac, char *av[], args_t *args);

    // champ
    int count_champions(int ac, char **av);
    void init_champion(champ_arg_t *champions, int nb_champions);
    int fill_champs(champ_arg_t *champions, char *av[]);
    int check_all_champ(champ_arg_t *champions, int nb_champions);
    int check_champ_name(champ_arg_t *champion, char *arg);

    // prog nb
    void fill_empty_pg_nb(champ_arg_t *champions);
    int handle_prog_nb(champ_arg_t *champions, char *av[],
    unsigned int index, unsigned int champ);

    // dump
    int get_dump(args_t *args, char *av[]);

    // adress
    int handle_prog_address(champ_arg_t *champions, char *av[],
    unsigned int index, unsigned int champ);

#endif /* !ARGS_H_ */
