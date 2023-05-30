/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Event foos for canvases
*/

#include "ui_panels/draggable.h"
#include "canvas.h"
#include "panel.h"

void canvas_resize(canvas_t *c, sfVector2f *pos, sfVector2f *size)
{
    sfVector2f pos_scaled = {pos->x * c->scale, pos->y * c->scale};
    if (!c || !pos || !size)
        return;
    for (int i = 0; c->panels[i]; i++)
        panel_resize(c->panels[i], &pos_scaled, size, c->scale);
    on_panel_unselect(c->selected);
    c->selected = NULL;
}

void canvas_hover(canvas_t *c, sfVector2i *pos)
{
    panel_t *hovered = NULL;

    if (!c)
        return;
    hovered = get_hovered_panel(c->panels, pos);
    if (hovered != c->hovered) {
        on_panel_leave(c->hovered);
        if (hovered != c->selected)
            on_panel_enter(hovered);
        if (!hovered || hovered->type != PANEL_TYPE_NONE)
            c->hovered = hovered;
    }
    if (c->pressed && c->pressed->type == PANEL_TYPE_DRAG) {
        on_drag_move(c->pressed, (sfVector2f){pos->x, pos->y}, c->scale);
    }
}

void canvas_pressed(canvas_t *c, sfMouseButtonEvent e)
{
    sfVector2i *pos = &(sfVector2i){e.x, e.y};
    canvas_hover(c, pos);
    c->pressed = c->hovered;
    if (c->pressed != c->selected) {
        on_panel_pressed(c->pressed);
    }
}

void canvas_released(canvas_t *c, sfMouseButtonEvent e)
{
    canvas_hover(c, &(sfVector2i){e.x, e.y});
    if (c->selected && c->pressed != c->selected
        && c->selected->type == PTYPE_DDBUTT)
        on_panel_unselect(c->selected);
    if (c->pressed != c->selected) {
        on_panel_released(c->pressed);
    }
    if (c->pressed == c->hovered && c->pressed != c->selected) {
        on_panel_select(c->pressed);
        on_panel_unselect(c->selected);
        c->selected = c->pressed;
    }
    if (c->selected && c->selected->type == PTYPE_EVBUTT) {
        on_panel_unselect(c->selected);
        c->selected = NULL;
    }
    c->pressed = NULL;
}
