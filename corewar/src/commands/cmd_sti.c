/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
takes 3 parameters.
The first one must be a register.
The other two can be indexes or registers.
sti r2,%4,%5 copies the content of r2 into the address PC + (4+5)% IDX_MOD.
*/
static void sti_to_reg(vm_t *vm, process_t *process, char *type, int *size)
{
    int first = 0;
    int second = 0;
    int tot = 0;
    int pos = 0;
    int reg = 0;

    pos = process->index;
    process->index += 2;
    reg = param_getter(process, vm, type[0], size[0]);
    first = param_getter(process, vm, type[1], size[1]);
    second = param_getter(process, vm, type[2], size[2]);
    if (type[1] == IND_CODE) {
        first = cbuffer_geti(vm->arena, pos + first % IDX_MOD);
    }
    set_mem(vm, pos + (first + second) % IDX_MOD,
    SWAP_INT32_SAFE(reg), REG_SIZE);
}

void cmd_sti(vm_t *vm, process_t *process)
{
    char coding_byte = '\0';
    char command = '\0';
    char *type = NULL;
    int *size = NULL;

    command = cbuffer_getb(vm->arena, process->index);
    coding_byte = cbuffer_getb(vm->arena, process->index + 1);
    type = get_coding_byte(coding_byte);
    size = get_size(type, command - 1);
    if (command != 11 || !param_checker(type, command - 1)) {
        kill_process(process, vm);
    } else {
        st_to_reg(vm, process, type, size);
    }
    free(type);
    free(size);
}

