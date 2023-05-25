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
#include "ansi_colors.h"

/**
 * @brief if the instruction is NULL (kill the process | set do dead)
 * otherwise if the countdown is 0 execute the instruction
 * else do nothing ((skip))
 *
 * @param data the process to handle(execute) the instruction
 * @param vm a pointer to the vm
 */
static void instruction_exec_process(process_t *process, vm_t *vm)
{
    if (process->instruction == NULL) {
        return;
    }
    if (process->cycle_to_wait == 0) {
        process->exec = true;
        process->instruction(vm, process);
    } else {
        process->cycle_to_wait--;
    }
}

void instruction_exec(vm_t *vm)
{
    node_t *node = NULL;
    node_t *next = NULL;
    process_t *process = NULL;

    node = vm->process->head;
    while (node) {
        next = node->next;
        process = node->data;
        instruction_exec_process(process, vm);
        node = next;
    }
}
