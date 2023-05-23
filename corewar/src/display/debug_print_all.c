/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** debug_print_all
*/

#include "serrorh.h"
#include "ansi_colors.h"
#include "vm.h"

static void print_process_status(process_t *process, vm_t *vm, UNUSED void *non)
{
    char hexabyte[3] = {0};

    put_byte_as_hex(cbuffer_getb(vm->arena, process->index), hexabyte);
    hexabyte[2] = '\0';
    DEBUGF(MAG"*-----------------------------------------------\n"CRESET, NULL);
    DEBUGF(MAG"|"CRESET"Process of champion "BLU"%s"CRESET" with id "GRN
        "%d\n"CRESET,
        process->champion->header.prog_name, process->champion->id);
    DEBUGF(MAG"|"CRESET"Index: "GRN"%d\n"CRESET, process->index);
    DEBUGF(MAG"|"CRESET"Value of Index: "GRN"%s "CRESET"|"GRN" %d\n"CRESET,
        hexabyte, cbuffer_getb(vm->arena, process->index));
    DEBUGF(MAG"|"CRESET"Cycle to wait: "GRN"%d\n"CRESET,
        process->cycle_to_wait);
    DEBUGF(MAG"|"CRESET"Carry: "GRN"%d\n"CRESET, process->carry);
    DEBUGF(MAG"|"CRESET"Registers:\n", NULL);
    for (int i = 0; i < REG_NUMBER; i++) {
        DEBUGF(MAG"|"CRESET CYN"%s%d"CRESET":\t"GRN"%d\n"CRESET,
            "  r", (i + 1), process->registr[i]);
    }
}

void debug_print_process_status(vm_t *vm)
{
    DEBUGF(BRED"##############################################\n"CRESET, NULL);
    DEBUGF(BRED"################ VM STATUS  ##################\n"CRESET, NULL);
    DEBUGF(BRED"##############################################\n"CRESET, NULL);
    DEBUGF(BRED"# "CRESET"Cycle: "GRN"%d\n"CRESET, vm->cycle_amount);
    DEBUGF(BRED"# "CRESET"Cycle to die: "GRN"%d\n"CRESET, vm->cycle_to_die);
    DEBUGF(BRED"# "CRESET"Total live: "GRN"%d\n"CRESET, vm->local_live);
    DEBUGF(BRED"# "CRESET"Total cycle: "GRN"%d\n"CRESET, vm->total_cycle);
    DEBUGF(BRED"# "CRESET"Total period: "GRN"%d\n"CRESET, vm->curr_period);
    if (vm->has_dump) {
        DEBUGF(BRED"# "CRESET"Dump cycle: "GRN"%d\n"CRESET, vm->dump_cycle);
    }
    DEBUGF(BRED"##############################################\n"CRESET, NULL);
    list_foreach_wargs(vm->process, (fun_foreach_wargs)print_process_status,
    vm, NULL);
}
