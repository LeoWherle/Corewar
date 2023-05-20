/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** vm
*/

#ifndef VM_H_
    #define VM_H_

    #include <stdbool.h>
    #include "clist.h"
    #include "cbuffer.h"
    #include "args.h"
    #include "op.h"

    // check if nbr(index) is between index and index + size
    #define TRUE_MAGIC      -209458688
    #define SWAP_INT32(x) (((x) >> 24) | (((x) << 8) & 0x00FF0000) \
| (((x) >> 8) & 0x0000FF00) | ((x) << 24))

    #define SWAP_INT32_SAFE(x) (((x & 0xFF000000) >> 24) \
| ((x & 0x00FF0000) >> 8) \
| ((x & 0x0000FF00) << 8) \
| ((x & 0x000000FF) << 24))

    #define IS_OVERLAPPING(nbr, indx, size) (nbr >= indx && nbr < indx + size)

    typedef struct vm_s vm_t;
    typedef struct process_s process_t;
    typedef void (*command_t)(vm_t *, process_t *self);

    typedef struct champion_s {
        // id of the champion (1, 2, 3, 4, etc.)
        size_t id;
        // header
        struct header_s header;
        // if the champion is alive => if false kill all children
        bool alive;
        char *file_path;
        // if has set adress
        bool has_adress;
        // if has set adress -> the adress
        size_t laddress_value;
        // registers
        char registr[REG_NUMBER];
    } champion_t;

    typedef struct process_s {
        // pointer to the champion
        champion_t *champion;
        // program counter (pc) => index of the current instruction
        size_t index;
        // number of cycles to wait before executing instruction
        unsigned int cycle_to_wait;
        // carry flag
        bool carry;
        // instruction can be NULL if no instruction is running
        command_t instruction;
    } process_t;

    typedef struct vm_s {
        cbuffer_t *arena;
        // list of champions
        list_t *champions;
        // list of processes (champions)
        list_t *process;
        // number of cycles since the beginning
        unsigned int cycle_to_die;
        // current number of total "live" in curr_period
        unsigned int local_live;
        // number of decreased CYCLES_TO_DIE by CYCLE_DELTA
        unsigned int curr_period;
    } vm_t;

    /*
    ** corewar specific functions
    */
    int champion_load_into_arena(vm_t *vm, args_t *args);
    int init_champs_into_vm(args_t *args, vm_t *vm);
    int init_champion_processes(vm_t *vm);

    /*
    ** Display functions
    */
    void print_string_byte_per_byte(char *str, size_t size);

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
