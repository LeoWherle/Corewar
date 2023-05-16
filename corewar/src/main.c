/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stdlib.h>
#include "vm.h"
#include "args.h"
#include "herror.h"

static void free_corewar(vm_t *vm)
{
    free(vm);
}

static int init_corewar(vm_t *vm, int ac, const char *av[])
{
    args_t *args = NULL;

    args = malloc(sizeof(args_t));
    ASSERT_MALLOC(args, 84);
    args = get_args(ac, av, args);
    ASSERT_PTR(args, 84);
    vm = malloc(sizeof(vm_t));
    ASSERT_MALLOC(vm, 84);
    free_args_struct(args);
    return (0);
}

int main(int ac, const char *av[])
{
    vm_t *vm = NULL;
    int ret = 0;

    ret = init_corewar(vm, ac, av);
    if (ret != 0)
        return (ret);
    free_corewar(vm);
    return (ret);
}
