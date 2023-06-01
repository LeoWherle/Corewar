/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** core_loop
*/

// # game loop (launch)

// ### - get current instruction of each process
// - if instruction byte is not valid, set cmd to NULL WILL BE VERIFIED
// - set countdown to the corresponding intruction

// ### - execute the instruction
// - if the instruction is NULL (kill the process | set do dead)
// - otherwise if the countdown is 0 **execute the instruction**
// - else do nothing ((skip))

// ### - cleanup
// - check if a process is dead () -> free
// - check if a player is dead (process count == 0) -> free
// - if there is only one player left setwin
// - if nbr_live is >= crr_live decrease curr_period by cycle_delta

// ### - Dump
// - if flag print status

#include "vm.h"
#include "cbuffer.h"
#include "serrorh.h"
#include "instructions.h"
#include "mystr.h"
#include "ansi_colors.h"

static int core_end(vm_t *vm)
{
    int champion_alive = 0;
    champion_t *champion = NULL;

    champion_alive = count_champion_alive(vm);
    if (champion_alive == 0) {
        my_fputstr(1, "No winner\n");
        return (1);
    }
    champion = get_champion_alive(vm->champions);
    if (champion_alive == 1 && champion != NULL) {
        my_fprintf(1, "The player %d(%s) has won.\n",
            champion->id, vm->last_live->header.prog_name);
        return (1);
    }
    return (0);
}

static void kill_champion_processes(vm_t *vm, champion_t *champion)
{
    node_t *node = vm->process->head;
    process_t *process = NULL;

    while (node != NULL) {
        process = node->data;
        if (process->champion == champion) {
            kill_process(process, vm);
        }
        node = node->next;
    }
}

static void champion_get_kill(any_t data, void *vm_ptr, UNUSED void *none)
{
    champion_t *champion = data;
    vm_t *vm = vm_ptr;

    if (champion->alive == false && champion->dead == false) {
        my_fprintf(1, "The player %d(%s) has been killed by the game.\n",
        champion->id, champion->header.prog_name);
        kill_champion_processes(vm, champion);
        champion->dead = true;
    }
}

int core_check(vm_t *vm)
{
    vm->cycle_amount++;
    vm->total_cycle++;
    if (vm->local_live >= NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->local_live = 0;
    }
    if (vm->cycle_amount >= vm->cycle_to_die) {
        vm->cycle_amount = 0;
        vm->curr_period++;
        list_foreach_wargs(vm->champions, &champion_get_kill, vm, NULL);
        if (core_end(vm))
            return 1;
        list_foreach_wargs(vm->champions, &champion_reset_live, vm, NULL);
    }
    if (vm->has_dump && vm->total_cycle >= vm->dump_cycle) {
        print_string_byte_per_byte(vm->arena->data, vm->arena->size);
        return 1;
    }
    return 0;
}

void core_loop(vm_t *vm)
{
    while (vm->cycle_to_die > 0) {
        instruction_get(vm);
        instruction_exec(vm);
        if (core_check(vm))
            return;
        core_cleanup(vm);
    }
}
