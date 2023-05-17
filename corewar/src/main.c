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

static champion_t *arg_champt_to_championt(champ_arg_t argchamp)
{
    champion_t *new_champ = NULL;

    new_champ = champion_create();
    ASSERT_PTR(new_champ, NULL);
    if (argchamp.prog_number)
        new_champ->id = argchamp.prog_number_value;
    if (argchamp.load_address)
        new_champ->load_address = argchamp.load_address_value;
    new_champ->file_path = argchamp.name;
    return new_champ;
}

static int init_champs_into_vm(args_t *args, vm_t *vm)
{
    champion_t *new_champ = NULL;
    unsigned int i = 0;

    while (i < args->nb_champions) {
        new_champ = arg_champt_to_championt(args->champions[i]);
        ASSERT_PTR(new_champ, 1);
        list_append(vm->champions, new_champ);
        i++;
    }
    return 0;
}

static int init_corewar(vm_t *vm, int ac, const char *av[])
{
    args_t *args = NULL;

    args = malloc(sizeof(args_t));
    ASSERT_MALLOC(args, 84);
    args = get_args(ac, av, args);
    ASSERT_PTR(args, 84);
    vm = vm_create();
    ASSERT_MALLOC(vm, 84);
    if(init_champs_into_vm(args, vm))
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
    ret = init_corewar(vm, ac, av);
    if (ret != 0)
        return (ret);
    free_corewar(vm);
    return (ret);
}
