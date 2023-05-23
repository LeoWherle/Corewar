/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** process_list_create
*/

#include "vm.h"
#include "serrorh.h"
#include "ansi_colors.h"

int init_champion_processes(vm_t *vm)
{
    process_t *new_process = NULL;

    for (node_t *node = vm->champions->head; node != NULL; node = node->next) {
        new_process = process_create(node->data);
        if (new_process == NULL)
            return (84);
        new_process->champion = node->data;
        new_process->index = ((champion_t *)(node->data))->laddress_value;
        new_process->cycle_to_wait = 0;
        for (int i = 0; i < REG_NUMBER; i++)
            new_process->registr[i] = 0;
        new_process->registr[0] = ((champion_t *)(node->data))->id;
        node_append(vm->process, new_process);
        DEBUGF(WHT"new Process for champion "BLU"%s"WHT" at "GRN"%d"CRESET"\n",
            ((champion_t *)(node->data))->header.prog_name, new_process->index);
    }
    return (0);
}
