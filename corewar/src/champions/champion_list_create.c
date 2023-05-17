/*
** EPITECH PROJECT, 2023
** µ
** File description:
** champion_list_create
*/

#include <fcntl.h>
#include <unistd.h>
#include "herror.h"
#include "serrorh.h"
#include "mystr.h"
#include "args.h"
#include "vm.h"

static champion_t *load_header_into_champion(champion_t *champion,
    const char *file_path)
{
    header_t header;
    int fd = 0;

    fd = open(file_path, O_RDONLY);
    ASSERT(fd != -1, NULL);
    if (read(fd, &header, sizeof(header_t)) != sizeof(header_t)) {
        err_put("Error: File not valid or failed to read\n");
        close(fd);
        return NULL;
    }
    if (header.magic != COREWAR_EXEC_MAGIC) {
        err_put("Error: File not valid\n");
        close(fd);
        return NULL;
    }
    champion->header = header;
    close(fd);
    return champion;
}

static champion_t *arg_champt_to_championt(champ_arg_t argchamp)
{
    champion_t *new_champ = NULL;

    new_champ = champion_create();
    ASSERT_PTR(new_champ, NULL);
    new_champ = load_header_into_champion(new_champ, argchamp.name);
    ASSERT_PTR(new_champ, NULL);
    if (argchamp.prog_number)
        new_champ->id = argchamp.prog_number_value;
    if (argchamp.load_address)
        new_champ->load_address = argchamp.load_address_value;
    new_champ->file_path = my_strdup(argchamp.name);
    ASSERT_PTR(new_champ->file_path, NULL);
    return new_champ;
}

int init_champs_into_vm(args_t *args, vm_t *vm)
{
    champion_t *new_champ = NULL;
    int i = 0;

    while (i < args->nb_champions) {
        new_champ = arg_champt_to_championt(args->champions[i]);
        ASSERT_PTR(new_champ, 1);
        node_append(vm->champions, new_champ);
        i++;
    }
    return 0;
}
