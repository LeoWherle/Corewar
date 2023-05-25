/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** param getter
*/

#include <stdlib.h>
#include <stddef.h>
#include "vm.h"

static int get_reg(process_t *process, vm_t *vm)
{
    char r = 0;

    cbuffer_get(vm->arena, &r, sizeof(char), process->index);
    process->index++;
    if (r < 1 || r > REG_NUMBER) {
        return -1;
    }
    return r;
}

static int initialise_int(char buff)
{
    int r = 0;

    if (buff & 128){
        for (int i = 0; i < 32; i++) {
            r <<= 1;
            r++;
        }
    }
    return r;
}

static int get_dir_ind(process_t *process, vm_t *vm, int size)
{
    char *buffer = NULL;
    int r = 0;
    int pow = 128;

    buffer = malloc(sizeof(char) * size);
    ASSERT_MALLOC(buffer, 0);
    cbuffer_get(vm->arena, buffer, size, process->index);
    r = initialise_int(buffer[0]);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 8; j++) {
            r <<= 1;
            r += (buffer[i] & pow) ? 1 : 0;
            pow >>= 1;
        }
        pow = 128;
    }
    free(buffer);
    process->index += size;
    return r;
}

/**
 * @brief give the value of the next parameter
 * if it is a register it returns the value inside the register
 * else the raw value of the parameter.
 * Increment the process index by the size of the arg
 *
 * @param process
 * @param vm
 * @param type the type of the next parameter
 * @param size the size of the next parameter
 * @return int
 */
int param_getter(process_t *process, vm_t *vm, char type, int size)
{
    if (type == REG_CODE) {
        return get_reg(process, vm);
    } else {
        return get_dir_ind(process, vm, size);
    }
}
