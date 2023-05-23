/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** core_cleanup
*/

#include "vm.h"

void p_clean_all(vm_t *vm, process_t *process, UNUSED void *none)
{
    process->index = process->index % vm->arena->size;
}

void core_cleanup(vm_t *vm)
{
    list_foreach_wargs(vm->process, (fun_foreach_wargs)p_clean_all, vm, NULL);
}
