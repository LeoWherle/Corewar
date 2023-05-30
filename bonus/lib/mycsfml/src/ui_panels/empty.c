/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for empty panels
*/

#include <stdlib.h>
#include "ui_panels/empty.h"
#include "tools.h"

panel_t *panel_image_create(rectransform_t *rect, sfTexture *texture)
{
    panel_empty_t *ipanel = malloc(sizeof(panel_empty_t));
    panel_t *panel = NULL;

    if (!ipanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_IMAGE, ipanel);
    if (!panel)
        return NULL;
    init_sprite(&(panel->sprite), texture, rect);
    return panel;
}

panel_t *panel_empty_create(rectransform_t *rect, sfColor color)
{
    panel_empty_t *epanel = malloc(sizeof(panel_empty_t));
    panel_t *panel = NULL;

    if (!epanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_EMPTY, epanel);
    if (!panel)
        return NULL;
    init_rshape(&(panel->shape), color);
    epanel->color = color;
    return panel;
}

void panel_empty_destroy(panel_t *panel)
{
    panel_empty_t *epanel;

    if (!panel)
        return;
    if (panel->data) {
        epanel = panel->data;
        free(epanel);
    }
    panel_destroy(panel);
}
