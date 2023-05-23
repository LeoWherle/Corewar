/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
Similar to ldi without the % IDX_MOD. This operation modifies the carry.
*/
int lldi_to_reg(vm_t *vm, process_t *process, char *type, int *size)
{
    int value = 0;
    int s = 0;
    int pos = 0;
    int to_add = 0;
    int tot = 0;

    pos = process->index;
    process->index += 2;
    value = param_getter(process, vm, type[0], size[0]);
    to_add = param_getter(process, vm, type[1], size[1]);
    if (type[0] == IND_CODE) {
        tot = pos + value;
        s = cbuffer_gets(vm->arena, tot);
    }
    s += to_add;
    tot = pos + s;
    value = cbuffer_geti(vm->arena, tot);
    process->carry = (value == 0) ? 1 : 0;
    set_reg(process, vm, value);
    return value;
}

void cmd_lldi(vm_t *vm, process_t *process)
{
    char coding_byte = '\0';
    char command = '\0';
    char *type = NULL;
    int *size = NULL;

    command = cbuffer_getb(vm->arena, process->index);
    coding_byte = cbuffer_getb(vm->arena, process->index + 1);
    type = get_coding_byte(coding_byte);
    size = get_size(type, command - 1);
    if (command != 10 || !param_checker(type, command - 1)) {
        kill_process(process, vm);
    } else {
        ldi_to_reg(vm, process, type, size);
    }
    free(type);
    free(size);
}
