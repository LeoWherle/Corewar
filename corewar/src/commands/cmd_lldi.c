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
int lldi_to_reg(vm_t *vm, process_t *process, unsigned char *type,
                int *size)
{
    ldi_t ldi = {0, 0, 0, 0, 0};
    ldi.pos = process->index;
    process->index += 2;
    ldi.value = param_getter(process, vm, type[0], size[0]);
    if (!get_param_value(process, type[0], &ldi.value))
        return 0;
    ldi.to_add = param_getter(process, vm, type[1], size[1]);
    if (!get_param_value(process, type[1], &ldi.to_add))
        return 0;
    if (type[0] == IND_CODE) {
        ldi.tot = ldi.pos + ldi.value;
        ldi.s += cbuffer_gets(vm->arena, ldi.tot);
    } else
        ldi.s += ldi.value;
    ldi.s += ldi.to_add;
    ldi.tot = ldi.pos + ldi.s;
    ldi.value = cbuffer_geti(vm->arena, ldi.tot);
    process->carry = (ldi.value == 0) ? 1 : 0;
    set_reg(process, vm, ldi.value);
    return ldi.value;
}

void cmd_lldi(vm_t *vm, process_t *process)
{
    unsigned char coding_byte = '\0';
    char command = 14;
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
        lldi_to_reg(vm, process, type, size);
    }
    process->index = future_index;
    free(type);
    free(size);
}
