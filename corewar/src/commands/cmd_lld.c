/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
Similar to ld without the % IDX_MOD. This operation modifies the carry
*/
int lld_to_reg(vm_t *vm, process_t *process, unsigned char *type, int *size)
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
        tot = pos + value;
        value = cbuffer_geti(vm->arena, tot);
    }
    process->carry = (tot == 0) ? 1 : 0;
    set_reg(process, vm, value);
    return value;
}

void cmd_lld(vm_t *vm, process_t *process)
{
    unsigned char coding_byte = '\0';
    char command = 13;
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
        lld_to_reg(vm, process, type, size);
    }
    process->index = future_index;
    free(type);
    free(size);
}
