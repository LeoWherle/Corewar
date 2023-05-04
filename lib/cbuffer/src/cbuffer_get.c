/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** cbuffer_get
*/

#include "cbuffer.h"

char cbuffer_getb(cbuffer_t *buffer, size_t pos)
{
    return buffer->data[pos % buffer->size];
}

void cbuffer_get(cbuffer_t *buffer, char *data, size_t size, size_t pos)
{
    size_t i = 0;

    for (; i < size; i++) {
        data[i] = buffer->data[(pos + i) % buffer->size];
    }
}
