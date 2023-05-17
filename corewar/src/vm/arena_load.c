/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** champion_load
*/

#include <stdio.h>
#include "vm.h"
#include "args.h"
#include "herror.h"
#include "serrorh.h"

static unsigned int get_sum_prg_size(vm_t const *vm)
{
    unsigned int sumofsize = 0;
    node_t *node = NULL;

    node = vm->champions->head;
    for (int i; i < vm->champions->size; i++) {
        sumofsize += ((champion_t *)node->data)->header.prog_size;
        node = node->next;
    }
}

static int load_champion(vm_t *vm, champion_t *champion, size_t pos)
{
    FILE *filestream = NULL;
    char *buffer = NULL;

    filestream = fopen(champion->file_path, "r");
    if (filestream == NULL) {
        err_print("Invalid file path %s\n", champion->file_path);
        return 1;
    }
    buffer = malloc(sizeof(typeof(*buffer)) * champion->header.prog_size);
    if (buffer == NULL) {
        err_print("Malloc failed\n");
        return 1;
    }
    fseek(filestream, sizeof(header_t), SEEK_SET);
    fread(buffer, sizeof(char), champion->header.prog_size, filestream);
    cbuffer_set(vm->arena, buffer, champion->header.prog_size, pos);
    free(buffer);
    fclose(filestream);
}

// check if the champion is overlapping all other champions
static int is_valid_pos(vm_t *vm, champion_t *champion, size_t pos)
{
    node_t *node = NULL;
    champion_t *chm = NULL;
    size_t load_address = 0;

    node = vm->champions->head;
    while (node != NULL) {
        chm = node->data;
        if (chm->id != champion->id)
            return 1;
        load_address = chm->load_address_value;
        if (IS_OVERLAPPING(pos, load_address, chm->header.prog_size)) {
            err_print("Champion %s is overlapping champion %d\n",
                champion->header.prog_name, chm->header.prog_name);
            return 0;
        }
        node = node->next;
    }
    return 1;
}

/**
 * @brief load the programm into vm memory
 * @return return 1 or error else 0;
 */
// need to check if the champion is overlapping another champion
int arena_load(vm_t *vm, args_t *args)
{
    node_t *node = NULL;
    champion_t *champion = NULL;
    size_t pos = 0;

    node = vm->champions->head;
    for (int i; i < vm->champions->size; i++) {
        champion = node->data;
        if (!champion->load_address)
            pos = i * (MEM_SIZE / vm->champions->size);
        champion->load_address_value = pos;
        if (!is_valid_pos(vm, champion, pos))
            return 1;
        if (load_champion(vm, champion, pos))
            return 1;
        node = node->next;
    }
    return 0;
}
