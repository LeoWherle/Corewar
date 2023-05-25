/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruction add for the VM
*/

#include <stdlib.h>
#include "instructions.h"

static int add_to_reg(vm_t *vm, process_t *process, unsigned char *type,
                    int *size)
{
    int tmp_reg = 0;
    int first = 0;
    int second = 0;
    int tot = 0;

    process->index++;
    tmp_reg = param_getter(process, vm, type[0], size[0]);
    if (tmp_reg == -1)
        return -1;
    first = process->registr[tmp_reg - 1];
    tmp_reg = param_getter(process, vm, type[1], size[1]);
    if (tmp_reg == -1)
        return -1;
    second = process->registr[tmp_reg - 1];
    tot = first + second;
    set_reg(process, vm, tot);
    process->carry = tot == 0 ? 1 : 0;
    return tot;
}

void cmd_add(vm_t *vm, process_t *process)
{
    unsigned char coding_byte = '\0';
    char command = 4;
    unsigned char *type = NULL;
    int *size = NULL;
    int future_index = 0;

    process->index++;
    coding_byte = cbuffer_getb(vm->arena, process->index);
    type = get_coding_byte(coding_byte);
    size = get_size(type, command - 1);
    future_index = process->index + 1;
    for (int i = 0; i < op_tab[command - 1].nbr_args; i++)
        future_index += size[i];
    if (param_checker(type, command - 1)){
        add_to_reg(vm, process, type, size);
    }
    process->index = future_index;
    free(type);
    free(size);
}
