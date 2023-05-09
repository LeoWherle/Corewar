/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** comand to data
*/

char **turn_str_to_word_array(char const *str, char sep);
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "asm.h"
#include "op.h"

void add_int(char *dest, long int nb, int i, int delta)
{
    long int order = 0;
    int cond = 0;

    order = pow(2, delta * 8);
    for (int x = i; x < i + delta; x++) {
        for (int y = 0; y < 8; y++) {
            cond = (nb & order);
            dest[x] += cond;
            nb -= cond;
            order /= 2;
        }
    }
    cond = (nb & order);
    dest[i + delta - 1] += cond;
    nb >>= (cond) ? 1 : 0;
}

int add_register(char *dest, char *arg, int i)
{
    int reg = 0;
    int order = 0;

    reg = atoi(&arg[1]);
    add_int(dest, reg, i, REG_SIZE);
    return i + REG_SIZE;
}

int add_direct(char *dest, char *arg, int i)
{
    int dir = 0;
    int order = 0;

    dir = atoi(&arg[1]);
    add_int(dest, dir, i, DIR_SIZE);
    return i + DIR_SIZE;
}

int add_indirect(char *dest, char *arg, int i)
{
    int ind = 0;
    int order = 0;

    ind = atoi(arg);
    add_int(dest, ind, i, IND_SIZE);
    return i + IND_SIZE;
}

static const arg_type_t arg_type[3] = {
    {REG_SIZE, add_register},
    {DIR_SIZE, add_direct},
    {IND_SIZE, add_indirect},
};

char *get_type(char **arg, int index)
{
    char *type = NULL;

    type = malloc(op_tab[index].nbr_args * sizeof(char));
    for (int i = 1; arg[i]; i++) {
        if (arg[i][0] == 'r') {
            type[i - 1] = 0b1;
        }
        if (arg[i][0] == DIRECT_CHAR) {
            type[i - 1] = 0b10;
        }
        if (arg[i][0] >= '0' && arg[i][0] <= '9') {
            type[i - 1] = 0b11;
        }
    }
    return type;
}

char *get_param(int param_size, char *type, char **arg, int index)
{
    char *new = NULL;
    int mv = 0;

    new = malloc(param_size * sizeof(char));
    memset(new, 0, param_size);
    for (int i = 0; i < op_tab[index].nbr_args; i++)
        mv = arg_type[type[i] - 1].ptr(new, arg[i + 1], mv);
    return new;
}

char make_coding_byte(command_t *new, char *type, int index)
{
    new->coding_byte = 0;
    new->param_size = 0;
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        new->coding_byte <<= 2;
        new->coding_byte += type[i];
        new->param_size += arg_type[type[i] - 1].size;
    }
    for (int i = 0; i < MAX_ARGS_NUMBER - op_tab[index].nbr_args; i++)
        new->coding_byte <<= 2;
}

command_t *line_to_command(char *line, int index)
{
    command_t *new = NULL;
    char **arg = NULL;
    char *type = NULL;
    int mv = 0;

    arg = turn_str_to_word_array(line, ' ');
    new = malloc(sizeof(command_t));
    new->code_command = op_tab[index].code;
    type = get_type(arg, index);
    make_coding_byte(new, type, index);
    new->parameters = get_param(new->param_size, type, arg, index);
    return new;
}

int main(void)
{
    header_t head = {0};
    command_t *new = NULL;

    new = line_to_command("ld %0, r3", 1);
    write(1, &new->code_command, sizeof(char));
    write(1, &new->coding_byte, sizeof(char));
    write(1, new->parameters, new->param_size);
    return 0;
}
