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

    typedef struct ldi_s {
        int pos;
        int value;
        int to_add;
        int tot;
        int s;
    } ldi_t;

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

    /*
    **parameters
    */
    int param_getter(process_t *process, vm_t *vm, char type, int size);
    bool get_param_value(process_t *process, char type, int *param);
    int *get_size(unsigned char *type, int index);
    unsigned char *get_coding_byte(unsigned char coding_byte);
    bool param_checker(unsigned char *type, int index);
    int set_reg(process_t *process, vm_t *vm, int new);
    void set_mem(vm_t *vm, int pos, int new, int size, char champid);

#endif /* !INSTRUCTIONS_H_ */
