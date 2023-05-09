/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#ifndef ASM_H
    #define ASM_H

    typedef struct label {
        char *name;
        unsigned int ad;
    } label_t;

    typedef struct command {
        char code_command;
        char coding_byte;
        char *parameters;
        int param_size;
    } command_t;

    typedef struct arg_type {
        int size;
        int (*ptr)(char *, char *, int);
    } arg_type_t;

#endif /* ASM_H */