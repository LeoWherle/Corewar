/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get coding byte
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "op.h"
#include "herror.h"
#include "vm.h"

static bool special_cases(int index, int i, char type)
{
    if (type == REG_CODE)
        return false;
    if ((index == 8 || index == 11 || index == 14) && i == 0)
        return true;
    if (index == 10 && (i == 1 || i == 2))
        return true;
    if ((index == 9 || index == 13) && (i == 0 || i == 1))
        return true;
    return false;
}

/**
 * @brief Get the size of all parameters
 *
 * @param type type of all the parameters
 * (can be acquired with get_coding_byte)
 * @param index the index of the function in op_tab
 * @return int*
 */
int *get_size(unsigned char *type, int index)
{
    int *size = NULL;

    size = malloc(op_tab[index].nbr_args * sizeof(int));
    ASSERT_MALLOC(size, NULL);
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        size[i] = 0;
        if (type[i] == REG_CODE)
            size[i] = 1;
        if (type[i] == DIR_CODE)
            size[i] = DIR_SIZE;
        if (special_cases(index, i, type[i]) || type[i] == IND_CODE)
            size[i] = IND_SIZE;
    }
    return size;
}

/**
 * @brief Get the type of all of the arugments
 *
 * @param coding_byte
 * @return char*
 */
unsigned char *get_coding_byte(unsigned char coding_byte)
{
    unsigned char *type = NULL;

    type = malloc(MAX_ARGS_NUMBER * sizeof(char));
    ASSERT_MALLOC(type, NULL);
    for (int i = MAX_ARGS_NUMBER - 1; i >= 0; i--) {
        type[i] = coding_byte % 4;
        coding_byte >>= 2;
    }
    return type;
}

/**
 * @brief check if the parameter type are valid
 *
 * @param type the type of the parameters
 * @param index the index of the function in op_tab
 * @return true if parameters are valid
 * @return false if parameters aren't valid
 */
bool param_checker(unsigned char *type, int index)
{
    for (int i = 0; i < op_tab[index].nbr_args; i++) {
        if (type[i] == REG_CODE && !(T_REG & op_tab[index].type[i]))
            return false;
        if (type[i] == DIR_CODE && !(T_DIR & op_tab[index].type[i]))
            return false;
        if (type[i] == IND_CODE && !(T_IND & op_tab[index].type[i]))
            return false;
    }
    for (int i = op_tab[index].nbr_args; i < MAX_ARGS_NUMBER; i++) {
        if (type[i] != 0) {
            return false;
        }
    }
    return true;
}
