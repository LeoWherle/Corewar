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
        kill_process(process, vm);
        return -1;
    }
    return r;
}

static int get_dir_ind(process_t *process, vm_t *vm, int size)
{
    char *buffer = NULL;
    int r = 0;

    buffer = malloc(sizeof(char) * size);
    ASSERT_MALLOC(buffer, 0);
    cbuffer_get(vm->arena, buffer, size, process->index);
    for (int i = 0; i < size; i++) {
        r <<= 8;
        r += buffer[i];
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
