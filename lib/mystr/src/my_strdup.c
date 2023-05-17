/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "mystr.h"

char *my_strdup(char const *src)
{
    char *dest = NULL;
    char *temp = NULL;

    if (!src)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (!dest)
        return NULL;
    temp = dest;
    while (*src) {
        *temp = *src;
        ++temp;
        ++src;
    }
    *temp = '\0';
    return dest;
}
