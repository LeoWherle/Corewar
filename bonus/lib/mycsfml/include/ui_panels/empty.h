/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for empty panels
*/

#ifndef PANEL_EMPTY_H
    #define PANEL_EMPTY_H
    #include "panel.h"

typedef struct panel_empty_s {
    sfColor color;
} panel_empty_t;

panel_t *panel_image_create(rectransform_t *rect, sfTexture *texture);
panel_t *panel_empty_create(rectransform_t *rect, sfColor color);
void panel_empty_destroy(panel_t *panel);

typedef struct panel_none_s {
    sfColor color;
} panel_none_t;

panel_t *panel_none_create(rectransform_t *rect);
void panel_none_destroy(panel_t *panel);
panel_t *make_none(void);

#endif /* PANEL_EMPTY_H */
