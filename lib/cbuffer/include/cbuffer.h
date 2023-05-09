/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** cbuffer
*/

#ifndef CBUFFER_H_
    #define CBUFFER_H_

    #include <stddef.h>

    typedef struct cbuffer_s {
        char *data;
        size_t size;
    } cbuffer_t;

    cbuffer_t *cbuffer_create(size_t size);
    void cbuffer_destroy(cbuffer_t *buffer);

    void cbuffer_setb(cbuffer_t *buffer, char data, size_t pos);
    void cbuffer_set(cbuffer_t *buffer, char *data, size_t size, size_t pos);

    char cbuffer_getb(cbuffer_t *buffer, size_t pos);
    void cbuffer_get(cbuffer_t *buffer, char *data, size_t size, size_t pos);

    void cbuffer_fill(cbuffer_t *buffer, char data);
#endif /* !CBUFFER_H_ */
