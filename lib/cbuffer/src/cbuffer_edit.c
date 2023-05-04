/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** cbuffer_edit
*/

#include "cbuffer.h"

void cbuffer_setb(cbuffer_t *buffer, char data, size_t pos)
{
    buffer->data[(pos) % buffer->size] = data;
}

void cbuffer_set(cbuffer_t *buffer, char *data, size_t size, size_t pos)
{
    size_t i = 0;
    size_t data_len = 0;

    for (; data[data_len]; data_len++);
    for (; i < size; i++) {
        buffer->data[(pos + i) % buffer->size] = data[i];
    }
}

void cbuffer_fill(cbuffer_t *buffer, char data)
{
    size_t i = 0;

    for (; i < buffer->size; i++) {
        buffer->data[i] = data;
    }
}
