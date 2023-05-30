/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** param setter
*/

#include "vm.h"

/**
 * @brief Set the new value to the register
 * that is at the actual index of the process
 *
 * @param process the acutal process
 * @param vm
 * @param new the value to set to the register
 * @return int 0 if ok -1 if ko
 */
int set_reg(process_t *process, vm_t *vm, int new)
{
    char reg = '\0';

    reg = cbuffer_getb(vm->arena, process->index);
    if (reg < 1 || reg > REG_NUMBER) {
        return -1;
    }
    process->registr[reg - 1] = new;
    process->index++;
    return 0;
}

/**
 * @brief Set new value at the position pos of the cbuffer of the vm
 * on size byte
 *
 * @param vm
 * @param pos the adress to write
 * @param new the value to write
 * @param size the size of the write
 */
void set_mem(vm_t *vm, int pos, int new, int size, char champid)
{
    int correct_new = 0;

    correct_new = SWAP_INT32_SAFE(new);
    cbuffer_set(vm->arena, &correct_new, size, pos);
    cbuffer_setbforn(vm->arena_ownership, champid, pos, size);
}
