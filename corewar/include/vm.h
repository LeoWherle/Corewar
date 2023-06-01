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
    #define SWAP_CHAR(x) (x >> 8 | x << 8)
    #define SWAP_INT32(x) (((x) >> 24) | (((x) << 8) & 0x00FF0000) \
| (((x) >> 8) & 0x0000FF00) | ((x) << 24))

    #define SWAP_INT32_SAFE(x) (((x & 0xFF000000) >> 24) \
| ((x & 0x00FF0000) >> 8) \
| ((x & 0x0000FF00) << 8) \
| ((x & 0x000000FF) << 24))

    //coding byte code of each type of argument
    #define REG_CODE 0b01
    #define DIR_CODE 0b10
    #define IND_CODE 0b11

    #define IS_OVERLAPPING(nbr, indx, size) (nbr >= indx && nbr < indx + size)

    typedef struct vm_s vm_t;
    typedef struct process_s process_t;
    typedef void (*command_t)(vm_t *, process_t *self);

    typedef struct champion_s {
        // id of the champion (1, 2, 3, 4, etc.)
        size_t id;
        // amount of process
        int process_count;
        // if the champion is alive
        bool alive;
        // if has set adress
        bool has_adress;
        // if has set adress -> the adress
        size_t laddress_value;
        char *file_path;
        // header
        struct header_s header;
        bool dead;
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
        // registers
        int registr[REG_NUMBER];
        bool exec;
    } process_t;

    typedef struct vm_s {
        cbuffer_t *arena;
        cbuffer_t *arena_ownership;
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
        // cycles in the current period
        unsigned int cycle_amount;
        // number of cycles since the beginning
        unsigned int total_cycle;
        bool has_dump;
        unsigned int dump_cycle;
        champion_t *last_live;
    } vm_t;

    /*
    ** corewar specific functions
    */
    int champion_load_into_arena(vm_t *vm, args_t *args);
    int init_champs_into_vm(args_t *args, vm_t *vm);
    int init_champion_processes(vm_t *vm);
    void champion_reset_live(any_t data, UNUSED void *vm_ptr,
    UNUSED void *none);

    /*
    ** game loop
    */
    void core_loop(vm_t *vm);
    void instruction_exec(vm_t *vm);
    void instruction_get(vm_t *vm);
    void core_cleanup(vm_t *vm);
    int core_check(vm_t *vm);
    /*
    ** Display functions
    */
    void put_byte_as_hex(char byte, char *arena);
    void print_string_byte_per_byte(char *str, size_t size);
    void debug_print_process_status(vm_t *vm);

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
    int count_champion_alive(vm_t *vm);
    champion_t *get_champion_alive(list_t *champions);

    /*
    ** process
    */
    process_t *process_create(champion_t *champion);
    void process_destroy(void *process);
    void kill_process(process_t *process, vm_t *vm);
    process_t *process_duplicate(process_t *process, int index);

#endif /* !VM_H_ */
