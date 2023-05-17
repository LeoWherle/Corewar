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
        load_address = chm->load_address_value;
        if (IS_OVERLAPPING(pos, load_address, chm->header.prog_size)) {
            err_print("Champion %s is overlapping champion %s\n",
                champion->header.prog_name, chm->header.prog_name);
            return false;
        }
        node = node->next;
    }
    return true;
}

static void print_byte_as_hex(char byte) {
    const char hex_digits[] = "0123456789ABCDEF";
    char hex[3];

    hex[0] = hex_digits[(byte >> 4) & 0x0F];
    hex[1] = hex_digits[byte & 0x0F];
    hex[2] = '\0';
    my_fprintf(1, "%s ", hex);
}

static void print_string_byte_per_byte(char *str, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (i % 32 == 0)
            my_fprintf(1, "\n");
        print_byte_as_hex(str[i]);
    }
    my_fprintf(1, "\n");
}

/**
 * @brief load the programm into vm memory
 * @return return 1 or error else 0;
 */
int champion_load_into_arena(vm_t *vm, args_t *args)
{
    node_t *node = NULL;
    champion_t *champion = NULL;
    size_t pos = 0;

    node = vm->champions->head;
    for (int i = 0; i < vm->champions->size; i++) {
        champion = node->data;
        if (!champion->load_address)
            pos = i * (MEM_SIZE / args->nb_champions);
        champion->load_address_value = pos;
        if (!is_valid_pos(vm, champion, pos, i))
            return 1;
        if (load_champion(vm, champion, pos))
            return 1;
        node = node->next;
    }
    print_string_byte_per_byte(vm->arena->data, vm->arena->size);
    return 0;
}
