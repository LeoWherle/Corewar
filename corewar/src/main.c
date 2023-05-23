/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stdlib.h>
#include "vm.h"
#include "mystr.h"
#include "args.h"
#include "herror.h"

static void free_corewar(vm_t *vm)
{
    free(vm->champions->interface);
    vm_destroy(vm);
}

static int init_corewar(vm_t **vm, int ac, const char *av[])
{
    args_t *args = NULL;

    args = malloc(sizeof(args_t));
    ASSERT_MALLOC(args, 84);
    args = get_args(ac, av, args);
    ASSERT_PTR(args, 84);
    *vm = vm_create();
    ASSERT_MALLOC(*vm, 84);
    (*vm)->has_dump = args->dump;
    (*vm)->dump_cycle = args->dump_cycle;
    if (init_champs_into_vm(args, *vm))
        return (84);
    if (champion_load_into_arena(*vm, args))
        return (84);
    if (init_champion_processes(*vm))
        return (84);
    free_args_struct(args);
    return (0);
}

int main(int ac, const char *av[])
{
    vm_t *vm = NULL;
    int ret = 0;

    if (detect_helper_flag(av) != 0)
        return (0);
    ret = init_corewar(&vm, ac, av);
    if (ret != 0)
        return (ret);
    core_loop(vm);
    debug_print_process_status(vm);
    free_corewar(vm);
    return (ret);
}
