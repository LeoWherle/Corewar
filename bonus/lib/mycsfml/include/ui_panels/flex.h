/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for empty panels
*/

#ifndef PANEL_FLEX_H
    #define PANEL_FLEX_H
    #include "panel.h"

typedef struct panel_flex_s {
    sfVector2i counts;
    sfVector2f elem_size;
} panel_flex_t;
panel_t *make_flex(sfVector2i counts, sfVector2f elem_size);
panel_t *panel_flex_create(
    rectransform_t *rect, sfVector2i counts, sfVector2f elem_size);
void panel_flex_destroy(panel_t *panel);
void panel_flex_repos(panel_t *panel, float scale);
void panel_flex_update(panel_t *panel);
#endif /* PANEL_FLEX_H */
