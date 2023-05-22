/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include "op.h"
    #include "vm.h"

    // used to get the instruction from the bytecode
    typedef struct instruction_s {
        command_t command;
        int cycles;
    } instruction_t;

    /*
    ** HANDLERS
    */
    void instruction_get(vm_t *vm);

    /*
    **  INSTRUCTIONS
    */

    void cmd_live(vm_t *vm, process_t *process);
    void cmd_ld(vm_t *vm, process_t *process);
    void cmd_st(vm_t *vm, process_t *process);
    void cmd_add(vm_t *vm, process_t *process);
    void cmd_sub(vm_t *vm, process_t *process);
    void cmd_and(vm_t *vm, process_t *process);
    void cmd_or(vm_t *vm, process_t *process);
    void cmd_xor(vm_t *vm, process_t *process);
    void cmd_zjmp(vm_t *vm, process_t *process);
    void cmd_ldi(vm_t *vm, process_t *process);
    void cmd_sti(vm_t *vm, process_t *process);
    void cmd_fork(vm_t *vm, process_t *process);
    void cmd_lld(vm_t *vm, process_t *process);
    void cmd_lldi(vm_t *vm, process_t *process);
    void cmd_lfork(vm_t *vm, process_t *process);
    void cmd_aff(vm_t *vm, process_t *process);

#endif /* !INSTRUCTIONS_H_ */
