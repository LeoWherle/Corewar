/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** champion_load
*/

#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "args.h"
#include "herror.h"
#include "serrorh.h"
#include "ansi_colors.h"
#include "mystr.h"

static int load_champion(vm_t *vm, champion_t *champion, size_t pos)
{
    FILE *filestream = NULL;
    char *buffer = NULL;

    filestream = fopen(champion->file_path, "r");
    if (filestream == NULL) {
        err_print("Invalid file path %s\n", champion->file_path);
        return 1;
    }
    buffer = malloc(sizeof(char) * champion->header.prog_size);
    if (buffer == NULL) {
        err_print("Malloc failed\n");
        return 1;
    }
    fseek(filestream, sizeof(header_t), SEEK_SET);
    fread(buffer, sizeof(char), champion->header.prog_size, filestream);
    cbuffer_set(vm->arena, buffer, champion->header.prog_size, pos);
    cbuffer_setbforn(vm->arena_ownership, champion->id, pos, champion->header.prog_size);
    free(buffer);
    fclose(filestream);
    return 0;
}

// check if the champion is overlapping all other champions
static bool is_valid_pos(vm_t *vm, champion_t *champion, size_t pos, int ch_am)
{
    node_t *node = NULL;
    champion_t *chm = NULL;
    size_t load_address = 0;

    node = vm->champions->head;
    for (int i = 0; i < ch_am; i++) {
        chm = node->data;
        load_address = chm->laddress_value;
        if (IS_OVERLAPPING(pos, load_address, chm->header.prog_size)) {
            err_print("Champion %s is overlapping champion %s\n",
                champion->header.prog_name, chm->header.prog_name);
            return false;
        }
        node = node->next;
    }
    return true;
}

static void champ_asign_address(args_t *arg, champion_t *champion, int i)
{
    size_t pos = 0;

    if (!champion->has_adress) {
        pos = i * ((MEM_SIZE) / arg->nb_champions);
        champion->laddress_value = pos;
    }
    DEBUGF("Champion "BLU"%s"CRESET" is loaded at "CYN"%d"CRESET,
        champion->header.prog_name, champion->laddress_value);
    DEBUGF(" with id "GRN"%d"CRESET" and size "YEL"%d"CRESET"\n",
        champion->id, champion->header.prog_size);
}

/**
 * @brief load the programm into vm memory
 * @return return 1 or error else 0;
 */
int champion_load_into_arena(vm_t *vm, args_t *args)
{
    node_t *node = NULL;
    champion_t *champion = NULL;

    node = vm->champions->head;
    for (int i = 0; i < vm->champions->size; i++) {
        champion = node->data;
        champ_asign_address(args, champion, i);
        if (!is_valid_pos(vm, champion, champion->laddress_value, i))
            return 1;
        if (load_champion(vm, champion, champion->laddress_value))
            return 1;
        node = node->next;
    }
    return 0;
}
