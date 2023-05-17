/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm
*/

#include <stdbool.h>
#include <stdio.h>
#include "op.h"
#include "clist.h"

#ifndef ASM_H
    #define ASM_H

    #define REG_CODE 0b1
    #define DIR_CODE 0b10
    #define IND_CODE 0b11

    typedef struct label {
        char *name;
        long int ad;
    } label_t;

    typedef struct command {
        char **line;
        char code_command;
        char coding_byte;
        char *param_type;
        int *param_size;
        char *parameters;
    } command_t;

    typedef struct arg_type {
        int size;
        int (*ptr)(char *, char *, int, int);
    } arg_type_t;

    int add_register(char *dest, char *arg, int i, int delta);
    int add_direct(char *dest, char *arg, int i, int delta);
    int add_indirect(char *dest, char *arg, int i, int delta);
    bool line_to_command(command_t *com);
    char *get_type(char **arg, int index);
    int *get_size(char *type, int index);
    char *get_param(int *param_size, char *type, char **arg, int index);
    char *clear_line(char *line);
    int header_parser(header_t *header, FILE *fd);
    int get_instrucion(char *instruction);
    int code_parser(header_t *header, FILE *fd, list_t *com_list,
                list_t *label_list);
    int check_valid_line(char **args, list_t *com_list, header_t *header);
    int put_label_in_list(char **args, list_t *label_list, int prog_size);

#endif /* ASM_H */
