/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** vm_init
*/

#include <stdlib.h>
#include "vm.h"
#include "herror.h"

static void vm_init(vm_t *vm)
{
    vm->arena = NULL;
    vm->arena_ownership = NULL;
    vm->champions = NULL;
    vm->process = NULL;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->local_live = 0;
    vm->curr_period = 0;
    vm->cycle_amount = 0;
    vm->total_cycle = 0;
    return;
}

/**
 * @return NULL on failure else initialized vm
 */
WUR vm_t *vm_create(void)
{
    vm_t *vm = NULL;

    vm = malloc(sizeof(vm_t));
    ASSERT_MALLOC(vm, NULL);
    vm_init(vm);
    vm->arena = cbuffer_create(MEM_SIZE);
    ASSERT_PTR(vm->arena, NULL);
    vm->arena_ownership = cbuffer_create(MEM_SIZE);
    ASSERT_PTR(vm->arena_ownership, NULL);
    vm->champions = list_init();
    ASSERT_PTR(vm->champions, NULL);
    vm->process = list_init();
    ASSERT_PTR(vm->process, NULL);
    cbuffer_fill(vm->arena, 0);
    cbuffer_fill(vm->arena_ownership, 0);
    return vm;
}

void vm_destroy(vm_t *vm)
{
    cbuffer_destroy(vm->arena);
    cbuffer_destroy(vm->arena_ownership);
    list_destroy(vm->champions, champion_destroy);
    list_destroy(vm->process, process_destroy);
    free(vm);
}
