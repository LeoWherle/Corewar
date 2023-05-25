/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction aff for the VM
*/

#include <unistd.h>
#include <stdlib.h>
#include "instructions.h"

/*
takes 1 parameter, which must be a register. It displays on the standard output
the character whose ASCII code is the content of the register (in base 10).
A 256 modulo is applied to this ASCII code.
aff r3 displays ’*’ if r3 contains 42.
*/
static void print_reg(vm_t *vm, process_t *process, unsigned char *type,
                        int *size)
{
    int reg_nb = 0;
    int value = 0;
    unsigned char c = '\0';

    process->index++;
    reg_nb = param_getter(process, vm, type[0], size[0]);
    if (reg_nb < 1 || reg_nb > REG_NUMBER) {
        return;
    }
    value = process->registr[reg_nb - 1];
    c = value % 256;
    write(1, &c, 1);
}

void cmd_aff(vm_t *vm, process_t *process)
{
    unsigned char coding_byte = '\0';
    char command = 16;
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
    if (param_checker(type, command - 1)) {
        print_reg(vm, process, type, size);
    }
    process->index = future_index;
    free(type);
    free(size);
}
