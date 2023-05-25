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
It loads the value of the first parameter into the second parameter,
which must be a register (not the PC). This operation modifies the carry.

ld 34,r3 loads the REG_SIZE bytes starting
at the address PC + 34 % IDX_MOD into r3.
*/
int ld_to_reg(vm_t *vm, process_t *process, unsigned char *type,
                int *size)
{
    int value = 0;
    int tot = 0;
    int pos = 0;

    pos = process->index;
    process->index += 2;
    value = param_getter(process, vm, type[0], size[0]);
    if (!get_param_value(process, type[0], &value))
        return 0;
    if (type[0] == IND_CODE) {
        tot = pos + value % IDX_MOD;
        value = cbuffer_gets(vm->arena, tot);
    }
    process->carry = (value == 0) ? 1 : 0;
    set_reg(process, vm, value);
    return value;
}

void cmd_ld(vm_t *vm, process_t *process)
{
    unsigned char coding_byte = '\0';
    char command = 2;
    unsigned char *type = NULL;
    int *size = NULL;
    int future_index = 0;

    coding_byte = cbuffer_getb(vm->arena, process->index + 1);
    type = get_coding_byte(coding_byte);
    size = get_size(type, command - 1);
    future_index = process->index + 2;
    for (int i = 0; i < op_tab[command - 1].nbr_args; i++)
        future_index += size[i];
    if (param_checker(type, command - 1)) {
        ld_to_reg(vm, process, type, size);
    }
    process->index = future_index;
    free(type);
    free(size);
}
