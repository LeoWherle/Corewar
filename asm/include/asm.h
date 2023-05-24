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

    #define REG_CODE 0b01
    #define DIR_CODE 0b10
    #define IND_CODE 0b11
    #define SWAP_INT32(x) (((x) >> 24) | (((x) << 8) & 0x00FF0000) \
| (((x) >> 8) & 0x0000FF00) | ((x) << 24))

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

    typedef struct parser_s {
        char *line;
        char **args;
        size_t len;
        int shift;
    } parser_t;

    //add functions
    int add_register(char *dest, char *arg, int i, int delta);
    int add_direct(char *dest, char *arg, int i, int delta);
    int add_indirect(char *dest, char *arg, int i, int delta);
    bool line_to_command(command_t *com);

    //getter functions
    char *get_type(char **arg, int index);
    int *get_size(char *type, int index);
    char *get_param(int *param_size, char *type, char **arg, int index);

    //parser funcitions
    char *clear_line(char *line);
    int header_parser(header_t *header, FILE *fd);
    int get_instrucion(char *instruction);
    int code_parser(header_t *header, FILE *fd, list_t *com_list,
                list_t *label_list);
    int check_valid_line(char **args, list_t *com_list, header_t *header);
    int is_label_matrix(char **args);
    int put_label_in_list(char **args, list_t *label_list, int prog_size);
    bool print_comp(list_t *command, header_t *head, char *name);
    bool search_in_command(list_t *commands, list_t *labels);
    int free_list(list_t *com_list, list_t *label_list, int r);
    void initilalize_com(command_t *com);
    void free_line_args(parser_t *pars);

#endif /* ASM_H */
