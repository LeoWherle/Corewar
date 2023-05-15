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

    /**
     * @brief Get the args options and champions
     *
     * @param ac
     * @param av
     * @param args must be malloc before
     * @return args_t* with all the infos for the vm and NULL on error
     */
    args_t *get_args(int ac, char *av[], args_t *args);

#endif /* !ARGS_H_ */
