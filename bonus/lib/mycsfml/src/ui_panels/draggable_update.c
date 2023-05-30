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

void on_drag_update(panel_t *panel, float scale)
{
    panel_slider_t *spanel;
    panel_drag_t *dpanel = (panel_drag_t *)panel->data;
    float percent = (dpanel->offset.x - dpanel->bounds.left * scale)
        / (dpanel->bounds.width * scale);
    if (dpanel->parent && dpanel->parent->type == PANEL_TYPE_SLIDER) {
        spanel = (panel_slider_t *)dpanel->parent->data;
        if (spanel && spanel->foo)
            spanel->foo(spanel->trgt, percent);
    }
}

void drag_repos(panel_t *panel, float scale)
{
    panel_drag_t *d = NULL;

    if (!panel)
        return;
    d = (panel_drag_t *)panel->data;
    if (!d)
        return;
    clamp(&(d->offset.x), d->bounds.left * scale,
        d->bounds.left * scale + d->bounds.width * scale);
    clamp(&(d->offset.y), d->bounds.top * scale,
        d->bounds.top * scale + d->bounds.height * scale);
    panel->rect->pos = (sfVector2f){
        d->offset.x, d->offset.y};
}

void on_drag_move(panel_t *panel, sfVector2f newoffset, float scale)
{
    panel_drag_t *d = NULL;

    if (!panel)
        return;
    d = (panel_drag_t *)panel->data;
    if (!panel)
        return;
    d->offset = (sfVector2f){newoffset.x - d->parent->pos.x,
        newoffset.y - d->parent->pos.y};
    drag_repos(panel, scale);
    panel_resize(panel, &(d->parent->pos), &(d->parent->size), scale);
    on_drag_update(panel, scale);
}
