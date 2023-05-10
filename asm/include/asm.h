/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdbool.h>

#ifndef ASM_H
    #define ASM_H

    typedef struct label {
        char *name;
        long int ad;
    } label_t;

    typedef struct command {
        char **line;
        char code_command;
        char coding_byte;
        char *parameters;
        int param_size;
    } command_t;

    typedef struct arg_type {
        int size;
        int (*ptr)(char *, char *, int);
    } arg_type_t;

    int add_register(char *dest, char *arg, int i);
    int add_direct(char *dest, char *arg, int i);
    int add_indirect(char *dest, char *arg, int i);
    bool line_to_command(command_t *com, int index);

#endif /* ASM_H */
