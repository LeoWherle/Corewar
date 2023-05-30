/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for empty panels
*/

#include <stdio.h>
#include <stdlib.h>
#include "ui_panels/flex.h"
#include "tools.h"

panel_t *make_flex(sfVector2i counts, sfVector2f elem_size)
{
    rectransform_t *mrect = rtrans_create_centered((sfVector2f){0, 0},
        (sfVector2f){counts.x * elem_size.x, counts.y * elem_size.y});
    panel_t *pmain = panel_flex_create(mrect, counts, elem_size);
    return pmain;
}

panel_t *panel_flex_create(
    rectransform_t *rect, sfVector2i counts, sfVector2f elem_size)
{
    panel_flex_t *fpanel = malloc(sizeof(panel_flex_t));
    panel_t *panel = NULL;

    if (!fpanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_FLEX, fpanel);
    if (!panel)
        return NULL;
    fpanel->counts = counts;
    fpanel->elem_size = elem_size;
    return panel;
}

void panel_flex_destroy(panel_t *panel)
{
    panel_flex_t *fpanel;

    if (!panel)
        return;
    if (panel->data) {
        fpanel = panel->data;
        free(fpanel);
    }
    panel_destroy(panel);
}

void panel_flex_update(panel_t *panel)
{
    panel_flex_t *fpanel = panel->data;

    if (!panel)
        return;

    panel->rect->size.x = fpanel->counts.x * fpanel->elem_size.x;
    panel->rect->size.y = fpanel->counts.y * fpanel->elem_size.y;
}

void panel_flex_repos(panel_t *panel, float scale)
{
    panel_flex_t *fpanel = panel->data;
    int i = 0, j = 0;
    float x = 0, y = 0;
    float xelem = fpanel->elem_size.x * scale;
    float yelem = fpanel->elem_size.y * scale;
    float xrect = panel->rect->size.x * scale;
    float yrect = panel->rect->size.y * scale;

    if (!panel)
        return;
    for (int ptr = 0; ptr < panel->childs_count; ptr++) {
        x = (float) j * xelem;
        y = (float) i * yelem;
        panel->childs[ptr]->rect->pos = (sfVector2f){
            x - (xrect / 2) + (xelem / 2), y - (yrect / 2) + (yelem / 2)};
        if (++j >= fpanel->counts.x) {
            j = 0;
            i++;
        }
    }
}
