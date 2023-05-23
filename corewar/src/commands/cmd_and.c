/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction and for the VM
*/

#include "vm.h"
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
    int pos = 0;

    pos = process->index;
    process->index += 2;
    first = param_getter(process, vm, type[0], size[0]);
    second = param_getter(process, vm, type[1], size[1]);
    if (type[0] == REG_CODE) {
        if (first < 1 || first > REG_NUMBER) return 1;
        first = process->registr[first - 1];
    } else if (type[0] == IND_CODE)
        first = cbuffer_gets(vm->arena, pos + first);
    if (type[1] == REG_CODE) {
        if (second < 1 || second > REG_NUMBER) return 1;
        second = process->registr[second - 1];
    } else if (type[1] == IND_CODE)
        second = cbuffer_gets(vm->arena, pos + second);
    set_reg(process, vm, first & second);
    return first & second;
}

void cmd_and(vm_t *vm, process_t *process)
{
    char coding_byte = '\0';
    char command = '\0';
    char *type = NULL;
    int *size = NULL;

    command = cbuffer_getb(vm->arena, process->index);
    coding_byte = cbuffer_getb(vm->arena, process->index + 1);
    type = get_coding_byte(coding_byte);
    size = get_size(type, command - 1);
    if (command != 4 || !param_checker(type, command - 1)) {
        kill_process(process, vm);
    } else {
        process->carry = (!and_to_reg(vm, process, type, size)) ? 1 : 0;
    }
    free(type);
    free(size);
}
