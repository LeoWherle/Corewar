/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include <stdlib.h>
#include "instructions.h"

/*
Similar to fork without the % IDX_MOD.
*/
void cmd_lfork(vm_t *vm, process_t *process)
{
    short param = 0;
    process_t *child = NULL;
    unsigned int new_index = 0;

    process->index++;
    param = param_getter(process, vm, IND_CODE, IND_SIZE);
    new_index = process->index + (param - (1 + IND_SIZE));
    child = process_duplicate(process, new_index);
    if (child)
        node_append(vm->process, child);
}
