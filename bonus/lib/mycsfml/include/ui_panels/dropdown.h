/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for dropdown buttons
*/

#ifndef DROPDOWN_H
    #define DROPDOWN_H
    #include "program.h"

panel_t *make_dd(size_t count, sfVector2f size);
panel_t *make_ddbutt(sfFont *font, const char *str);
void dds_select(void *data);
void dds_unselect(void *data);

#endif /* DROPDOWN_H */
