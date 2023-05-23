/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruction add for the VM
*/

#include <stdlib.h>
#include "instructions.h"

static int add_to_reg(vm_t *vm, process_t *process, char *type, int *size)
{
    int tmp_reg = 0;
    int first = 0;
    int second = 0;
    int tot = 0;

    process->index++;
    tmp_reg = param_getter(process, vm, type[0], size[0]);
    if (tmp_reg == -1)
        return -1;
    first = process->registr[tmp_reg - 1];
    tmp_reg = param_getter(process, vm, type[1], size[1]);
    if (tmp_reg == -1)
        return -1;
    second = process->registr[tmp_reg - 1];
    tot = first + second;
    set_reg(process, vm, tot);
    return tot;
}

void cmd_add(vm_t *vm, process_t *process)
{
    char coding_byte = '\0';
    char command = '\0';
    char *type = NULL;
    int *size = NULL;

    command = cbuffer_getb(vm->arena, process->index);
    process->index++;
    coding_byte = cbuffer_getb(vm->arena, process->index);
    type = get_coding_byte(coding_byte);
    size = get_size(type, command - 1);
    if (command != 4 || !param_checker(type, command - 1)) {
        kill_process(process, vm);
    } else {
        add_to_reg(vm, process, type, size);
    }
    free(type);
    free(size);
}
