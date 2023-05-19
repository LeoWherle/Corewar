/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction live for the VM
*/

#include <unistd.h>
#include "vm.h"
#include "mystr.h"

static int print_is_alive(list_t *champions, int champion_id)
{
    node_t *tmp = NULL;
    champion_t *champion = NULL;
    char *name = NULL;

    while (tmp != NULL) {
        champion = tmp->data;
        if (champion->id == champion_id) {
            name = champion->header.prog_name;
            my_fprintf(1, "The champion %d (%s) is alive.\n",
            champion_id, name);
            return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}

void cmd_live(vm_t *vm, process_t *process)
{
    int champion_id = 0;

    process->index++;
    champion_id = cbuffer_geti(vm->arena, process->index);
    process->index += 4;
    if (!print_is_alive(vm->champions, champion_id))
        kill_process(process, vm);
    else {
        vm->local_live++;
        process->champion->alive = true;
    }
}
