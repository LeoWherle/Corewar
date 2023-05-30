/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdlib.h>
#include <string.h>
#include "ui_panels/draggable.h"
#include "ui_panels/slider.h"
#include "theme.h"
#include "tools.h"
#include "program.h"

panel_t *make_handle_drag(sfVector2f pos, panel_t *parent)
{
    sfVector2f size = {HANDLEX, ELEMY - ELEMY / 5};
    rectransform_t *sb_rect = rtrans_create_centered(pos, size);
    sb_rect->xanchor = ANCHOR_START;
    sb_rect->yanchor = ANCHOR_START;
    panel_t *drag = panel_handle_drag_create(sb_rect, parent);

    return drag;
}

panel_drag_t *drag_create(void)
{
    panel_drag_t *dpanel = malloc(sizeof(panel_drag_t));

    if (!dpanel)
        return NULL;
    dpanel->offset = (sfVector2f){0, 0};
    dpanel->bounds = (sfFloatRect){0, 0, 0, 0};
    dpanel->parent = NULL;
    return dpanel;
}

panel_t *panel_handle_drag_create(
    rectransform_t *rect,
    panel_t *parent)
{
    panel_drag_t *bpanel = drag_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_DRAG, bpanel);
    if (!panel)
        return NULL;
    init_rshape(&(panel->shape), HANDLES);
    bpanel->bounds = (sfFloatRect){
        -ELEMX / 2.0 + ELEMMARGIN, 0, ELEMX - 2 * ELEMMARGIN, 0};
    bpanel->parent = parent;
    return panel;
}

void panel_drag_destroy(panel_t *panel)
{
    panel_drag_t *dpanel = NULL;

    if (!panel)
        return;
    dpanel = (panel_drag_t *)panel->data;
    if (!dpanel)
        return;
    free(dpanel);
    panel_destroy(panel);
}
