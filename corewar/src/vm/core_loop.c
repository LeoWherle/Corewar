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

static int core_end(vm_t *vm)
{
    if (vm->champions->size == 0) {
        my_putstr("No winner\n");
        return (1);
    }
    if (vm->champions->size == 1) {
        my_fputstr(1, "The player ");
        my_fputnbr(1, ((champion_t *)vm->champions->head)->id);
        my_fputstr(1, "(");
        my_fputstr(1, ((champion_t *)vm->champions->head)->header.prog_name);
        my_fputstr(1, ")has won.\n");
        return (1);
    }
    return (0);
}

void core_loop(vm_t *vm)
{
    while (vm->cycle_to_die > 0) {
        instruction_get(vm);
        instruction_exec(vm);
        vm->cycle_amount++;
        vm->total_cycle++;
        if (vm->cycle_amount >= vm->cycle_to_die) {
            vm->cycle_amount = 0;
            vm->curr_period++;
            vm->local_live = 0;
        }
        if (vm->local_live >= NBR_LIVE) {
            vm->cycle_to_die -= CYCLE_DELTA;
            vm->local_live = 0;
        }
        if (core_end(vm))
            return;
    }
}