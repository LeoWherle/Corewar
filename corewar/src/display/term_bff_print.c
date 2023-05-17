/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** term_bff_print
*/

#include "mystr.h"
#include "vm.h"

static void print_byte_as_hex(char byte)
{
    const char hex_digits[] = "0123456789ABCDEF";
    char hex[3];

    hex[0] = hex_digits[(byte >> 4) & 0x0F];
    hex[1] = hex_digits[byte & 0x0F];
    hex[2] = '\0';
    my_fprintf(1, "%s ", hex);
}

void print_string_byte_per_byte(char *str, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (i % 32 == 0 && i != 0)
            my_fprintf(1, "\n");
        print_byte_as_hex(str[i]);
    }
    my_fprintf(1, "\n");
}
