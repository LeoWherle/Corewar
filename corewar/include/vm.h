/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** vm
*/

#ifndef VM_H_
    #define VM_H_

    #include <types.h>
    #include "clist.h"
    #include "cbuffer.h"
    #include "op.h"

    typedef void (*command_t)(vm_t *, process_t *self);

    typedef struct process_s {
        // pointer to the champion
        champion_t *champion;
        // program counter (pc) => index of the current instruction
        size_t index;
        // number of cycles to wait before executing instruction
        uint cycle_to_wait;
        // carry flag
        bool carry;
        // instruction can be NULL if no instruction is running
        command_t instruction;
        char options[MAX_ARGS_NUMBER]; /* still unclear if necessary */
        // registers
        char registr[REG_NUMBER];
    } process_t;

    typedef struct champion_s {
        // id of the champion (1, 2, 3, 4, etc.)
        size_t id;
        // name of the champion
        char *name[PROG_NAME_LENGTH];
        // if the champion is alive => if false kill all children
        bool alive;
    } champion_t;

    typedef struct vm_s {
        cbuffer_t *arena;
        // list of champions
        list_t *champions;
        // list of processes (champions)
        list_t *process;
        // number of cycles since the beginning
        uint cycle_to_die;
        // current number of total "live" in curr_period
        uint local_live;
        // number of decreased CYCLES_TO_DIE by CYCLE_DELTA
        uint curr_period;
    } vm_t;


    /*
    ** vm
    */
    vm_t *vm_create(void);
    void vm_destroy(vm_t *vm);

    /*
    ** champions
    */
    champion_t *champion_create(void);
    void champion_destroy(void *champion);

    /*
    ** process
    */
    process_t *process_create(champion_t *champion);
    void process_destroy(void *process);


#endif /* !VM_H_ */
