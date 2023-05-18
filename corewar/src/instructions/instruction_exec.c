/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** instruction_exec
*/

#include "vm.h"
#include "cbuffer.h"
#include "serrorh.h"
#include "instructions.h"

/**
 * @brief if the instruction is NULL (kill the process | set do dead)
 * otherwise if the countdown is 0 execute the instruction
 * else do nothing ((skip))
 *
 * @param data the process to handle(execute) the instruction
 * @param vm a pointer to the vm
 */
static void instruction_exec_process(any_t data, void *vm_ptr, UNUSED void *non)
{
    vm_t *vm = vm_ptr;
    process_t *process = data;

    if (process->instruction == NULL) {
        process->champion->process_count--;
        node_pop(vm->process, process);
        return;
    }
    if (process->cycle_to_wait == 0) {
        process->instruction(vm, process);
    } else {
        process->cycle_to_wait--;
    }
}

void instruction_exec(vm_t *vm)
{
    list_foreach_wargs(vm->process, &instruction_exec_process, vm, NULL);
}
