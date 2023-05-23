/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction and for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
takes 3 parameters.
It performs a binary AND between the first two parameters
and stores the result into the third one (which must be a register).
This operation modifies the carry.
and r2, %0,r3 puts r2 & 0 into r3.
*/

static int and_to_reg(vm_t *vm, process_t *process, char *type, int *size)
{
    int first = 0;
    int second = 0;
    int tot = 0;

    process->index++;
    first = param_getter(process, vm, type[0], size[0]);
    second = param_getter(process, vm, type[1], size[1]);
    tot = first & second;
    set_reg(process, vm, tot);
    process->carry = (tot == 0) ? 1 : 0;
    return tot;
}

void cmd_and(vm_t *vm, process_t *process)
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
    if (command != 6 || !param_checker(type, command - 1)) {
        kill_process(process, vm);
    } else {
        and_to_reg(vm, process, type, size);
    }
    free(type);
    free(size);
}
