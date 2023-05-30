/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for button panels
*/

#ifndef DRAGGABLE_H
    #define DRAGGABLE_H
    #include "panel.h"

typedef struct panel_drag_s {
    sfVector2f offset;
    sfFloatRect bounds;
    panel_t *parent;
} panel_drag_t;

panel_t *make_handle_drag(sfVector2f pos, panel_t *parent);

panel_drag_t *drag_create(void);
panel_t *panel_handle_drag_create(rectransform_t *rect, panel_t *parent);
void panel_drag_destroy(panel_t *panel);

void on_drag_move(panel_t *panel, sfVector2f newoffset, float scale);
void drag_repos(panel_t *panel, float scale);
#endif /* DRAGGABLE_H */
