/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include "vm.h"
#include "instructions.h"

/*
takes 3 parameters.
The first two must be indexes or registers, the third one must be a register.
This operation modifies the carry.
ldi 3,%4,r1:
reads IND_SIZ bytes from the address PC + 3 % IDX_MOD, adds 4 to this value.
The sum is named S.REG_SIZE bytes are read
from the address PC + S % IDX_MOD and copied into r1.
*/
void cmd_ldi(vm_t *vm, process_t *process)
{

}
