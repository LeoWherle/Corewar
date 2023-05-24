/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
takes 2 parameters.
It stores the first parameter’s value (which is a register) into
the second (whether a register or a number).
st r4,34 stores the content of r4 at the address PC + 34 % IDX_MOD.
st r3,r8 copies the content of r3 into r8.
*/
static void st_to_reg(vm_t *vm, process_t *process, char *type, int *size)
{
    int first = 0;
    int second = 0;
    int tot = 0;
    int pos = 0;

    pos = process->index;
    process->index += 2;
    first = param_getter(process, vm, type[0], size[0]);
    if (!get_param_value(process, type[0], &first))
        return;
    if (type[1] == IND_CODE) {
        second = param_getter(process, vm, type[1], size[1]);
        if (!get_param_value(process, type[1], &second))
            return;
        set_mem(vm, pos + second % IDX_MOD, first, REG_SIZE);
    } else {
        set_reg(process, vm, tot);
    }
}

void cmd_st(vm_t *vm, process_t *process)
{
    char coding_byte = '\0';
    char command = 3;
    char *type = NULL;
    int *size = NULL;

    coding_byte = cbuffer_getb(vm->arena, process->index + 1);
    type = get_coding_byte(coding_byte);
    size = get_size(type, command - 1);
    if (!param_checker(type, command - 1)) {
        kill_process(process, vm);
    } else {
        st_to_reg(vm, process, type, size);
    }
    free(type);
    free(size);
}
