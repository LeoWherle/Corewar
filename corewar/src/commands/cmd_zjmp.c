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
It jumps to this index if the carry is worth 1.
Otherwise, it does nothing but consumes the same time.
zjmp %23 puts, if carry equals 1, PC + 23 % IDX_MOD into the PC.
*/
void cmd_zjmp(vm_t *vm, process_t *process)
{
    short param = 0;

    process->index++;
    param = param_getter(process, vm, IND_CODE, IND_SIZE);
    if (process->carry == 1){
        process->index += (param % IDX_MOD - (1 + IND_SIZE));
    }
}
