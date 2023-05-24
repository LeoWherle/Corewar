/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** core_cleanup
*/

#include "vm.h"

void champion_reset_live(any_t data, UNUSED void *vm_ptr, UNUSED void *none)
{
    champion_t *champion = data;

    champion->alive = false;
}

void p_clean_all(vm_t *vm, process_t *process, UNUSED void *none)
{
    process->index = process->index % vm->arena->size;
}

void core_cleanup(vm_t *vm)
{
    node_t *node = NULL;

    node = vm->process->head;
    while (node) {
        p_clean_all(vm, node->data, NULL);
        node = node->next;
    }
}
