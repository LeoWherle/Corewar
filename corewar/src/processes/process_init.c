/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** vm_init
*/

#include <stdlib.h>
#include "vm.h"
#include "herror.h"
#include "serrorh.h"
#include "ansi_colors.h"

static void process_init(process_t *self)
{
    self->champion = NULL;
    self->index = 0;
    self->cycle_to_wait = 0;
    self->carry = false;
    self->instruction = NULL;
    self->exec = true;
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
    process->champion->process_count--;
    DEBUGF(REDB"process of champion : %s", process->champion->header.prog_name);
    DEBUGF("with id : %d has been killed"CRESET"\n", process->champion->id);
    node_delete(vm->process, process, process_destroy);
}

process_t *process_duplicate(process_t *process, int index)
{
    process_t *new = NULL;

    new = process_create(process->champion);
    ASSERT_MALLOC(new, NULL);
    new->carry = process->carry;
    new->index = index;
    new->cycle_to_wait = 2;
    new->instruction = process->instruction;
    new->exec = true;
    for (int i = 0; i < REG_NUMBER; i++)
        new->registr[i] = process->registr[i];
    process->champion->process_count++;
    return new;
}
