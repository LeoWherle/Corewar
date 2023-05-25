/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
takes 1 parameter, which must be an index.
It creates a new program that inherits different states from the parent.
This program is executed at the address PC + first parameter % IDX_MOD.
*/
void cmd_fork(vm_t *vm, process_t *process)
{
    short param = 0;
    process_t *child = NULL;
    unsigned int new_index = 0;

    process->index++;
    param = param_getter(process, vm, IND_CODE, IND_SIZE);
    new_index = process->index + (param % IDX_MOD - (1 + IND_SIZE));
    child = process_duplicate(process, new_index);
    if (child)
        node_append(vm->process, child);
}
