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
static void sti_to_reg(vm_t *vm, process_t *process, unsigned char *type,
                        int *size)
{
    int first = 0;
    int second = 0;
    int pos = process->index;
    int reg = 0;

    process->index += 2;
    reg = param_getter(process, vm, type[0], size[0]);
    if (!get_param_value(process, type[0], &reg))
        return;
    first = param_getter(process, vm, type[1], size[1]);
    if (!get_param_value(process, type[1], &first))
        return;
    second = param_getter(process, vm, type[2], size[2]);
    if (!get_param_value(process, type[2], &second))
        return;
    if (type[1] == IND_CODE)
        first = cbuffer_gets(vm->arena, pos + first % IDX_MOD);
    set_mem(vm, pos + (first + second) % IDX_MOD, reg, REG_SIZE, process->champion->id);
}

void cmd_sti(vm_t *vm, process_t *process)
{
    unsigned char coding_byte = '\0';
    char command = 11;
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
        sti_to_reg(vm, process, type, size);
    }
    process->index = future_index;
    free(type);
    free(size);
}
