/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** term_bff_print
*/

#include <unistd.h>
#include "mystr.h"
#include "ansi_colors.h"
#include "serrorh.h"
#include "vm.h"

void put_byte_as_hex(char byte, char *arena)
{
    const char hex_digits[] = "0123456789ABCDEF";

    arena[0] = hex_digits[(byte >> 4) & 0x0F];
    arena[1] = hex_digits[byte & 0x0F];
    arena[2] = ' ';
}

void print_string_byte_per_byte(char *str, size_t size)
{
    char arena[(MEM_SIZE * 3) + (MEM_SIZE / 32)];
    char *arena_ptr = NULL;

    arena_ptr = arena;
    for (size_t i = 0; i < size; i++) {
        if (i % 32 == 0 && i != 0) {
            *arena_ptr++ = '\n';
        }
        put_byte_as_hex(*str++, arena_ptr);
        arena_ptr += 3;
    }
    *arena_ptr++ = '\n';
    write(1, arena, sizeof(arena));
}
