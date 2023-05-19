/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** champion_list_create
*/

#include <fcntl.h>
#include <unistd.h>
#include "herror.h"
#include "ansi_colors.h"
#include "serrorh.h"
#include "mystr.h"
#include "args.h"
#include "vm.h"

static int is_valid_cor(champion_t *champion, const char *file_path)
{
    if (champion->header.magic != (int)SWAP_INT32_SAFE(COREWAR_EXEC_MAGIC)) {
        err_print(RED"Error:"CRESET" File %s, not valid .cor\n", file_path);
        return 0;
    }
    if (champion->header.prog_size < 0
    || champion->header.prog_size > MEM_SIZE) {
        err_print(RED"Error:"CRESET" File %s, champion size : %d is invalid\n",
        file_path, champion->header.prog_size);
        return 0;
    }
    return 1;
}

static champion_t *load_header_into_champion(champion_t *champion,
    const char *file_path)
{
    int fd = 0;

    fd = open(file_path, O_RDONLY);
    if (read(fd, &champion->header, sizeof(header_t)) != sizeof(header_t)) {
        err_print(RED"Error:"CRESET" Failed to read %s\n", file_path);
        close(fd);
        return NULL;
    }
    champion->header.prog_size = SWAP_INT32_SAFE(champion->header.prog_size);
    if (!is_valid_cor(champion, file_path)) {
        close(fd);
        return NULL;
    }
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
    new_champ->id = argchamp.prog_number_value;
    new_champ->has_adress = argchamp.load_address;
    if (new_champ->has_adress) {
        new_champ->laddress_value = argchamp.load_address_value % (MEM_SIZE);
    }
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
