/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction or for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
Similar to and, but performing a binary OR.
*/
static int or_to_reg(vm_t *vm, process_t *process, char *type, int *size)
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
    set_reg(process, vm, first | second);
    return first | second;
}

void cmd_or(vm_t *vm, process_t *process)
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
        process->carry = (!or_to_reg(vm, process, type, size)) ? 1 : 0;
    }
    free(type);
    free(size);
}
