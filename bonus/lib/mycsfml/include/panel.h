/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for panels
*/

#ifndef PANEL_H
    #define PANEL_H
    #include "rectransform.h"

typedef enum panel_type {
    PANEL_TYPE_NONE,
    PANEL_TYPE_EMPTY,
    PANEL_TYPE_CONTENT,
    PANEL_TYPE_FLEX,
    PANEL_TYPE_INPUT,
    PANEL_TYPE_BOARD,
    PANEL_TYPE_TEXT,
    PTYPE_DDBUTT,
    PTYPE_EVBUTT,
    PANEL_TYPE_IMAGE,
    PANEL_TYPE_DRAG,
    PANEL_TYPE_SLIDER
} ptype_t;

typedef enum panel_state {
    PANEL_STATE_NONE,
    PANEL_STATE_ACTIVE,
    PANEL_STATE_INACTIVE
} pstate_t;

typedef struct panel_s panel_t;
struct panel_s {
    sfRectangleShape *shape;
    sfSprite *sprite;
    sfText *text;
    ptype_t type;
    pstate_t state;
    void *data;
    rectransform_t *rect;
    sfVector2f pos;
    sfVector2f size;
    panel_t **childs;
    int childs_count;
};

panel_t *panel_create(rectransform_t *rect, ptype_t type, void *data);
void panel_add_childs(panel_t *parent, size_t n, ...);

void panel_destroy(panel_t *panel);
void on_panel_enter(panel_t *panel);
void on_panel_leave(panel_t *panel);
void on_panel_pressed(panel_t *panel);
void on_panel_released(panel_t *panel);
void on_panel_select(panel_t *panel);
void on_panel_unselect(panel_t *panel);
void panel_resize(
    panel_t *panel, sfVector2f *pos, sfVector2f *size, float scale);
void panel_draw(sfRenderWindow *window, panel_t *panel);

panel_t *get_hovered_panel(panel_t **panels, sfVector2i *pos);

#endif /* PANEL_H */
