/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for empty panels
*/

#include <stdlib.h>
#include "ui_panels/empty.h"
#include "program.h"
#include "tools.h"

panel_t *make_none(void)
{
    rectransform_t *rect = rtrans_create_flexelem((sfVector2f){ELEMX, ELEMY});
    panel_t *epanel = panel_none_create(rect);

    return epanel;
}

panel_t *panel_none_create(rectransform_t *rect)
{
    panel_none_t *epanel = malloc(sizeof(panel_empty_t));
    panel_t *panel = NULL;

    if (!epanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_NONE, epanel);
    if (!panel)
        return NULL;
    return panel;
}

void panel_none_destroy(panel_t *panel)
{
    panel_none_t *epanel;

    if (!panel)
        return;
    if (panel->data) {
        epanel = panel->data;
        free(epanel);
    }
    panel_destroy(panel);
}
