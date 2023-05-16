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
    ASSERT_MALLOC(buffer, 1);
    fseek(filestream, sizeof(header_t), SEEK_SET);
    fread(buffer, sizeof(char), champion->header.prog_size, filestream);
    cbuffer_set(vm->arena, buffer, champion->header.prog_size, pos);
    free(buffer);
    fclose(filestream);
}

/**
 * @brief load the programm into vm memory
 * @return return 1 or error else 0;
 */
int arena_load(vm_t *vm)
{
    unsigned int sum_of_size = 0;

    sum_of_size = get_sum_prg_size(vm);
    if (sum_of_size > MEM_SIZE)
        return 1;
    return 0;
}
