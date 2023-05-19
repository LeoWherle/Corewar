/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** vm_init
*/

#include <stdlib.h>
#include "vm.h"
#include "herror.h"

static void process_init(process_t *self)
{
    self->champion = NULL;
    self->index = 0;
    self->cycle_to_wait = 0;
    self->carry = false;
    self->instruction = NULL;
    return;
}

/**
 * @return NULL on failure else initialized champion
 */
WUR process_t *process_create(champion_t *champion)
{
    process_t *process = NULL;

    process = malloc(sizeof(process_t));
    ASSERT_MALLOC(process, NULL);
    process_init(process);
    process->champion = champion;
    return process;
}

void process_destroy(void *self)
{
    process_t *process = self;
    free(process);
}

void kill_process(process_t *process, vm_t *vm)
{
    node_delete(vm->process, process, process_destroy);
}
