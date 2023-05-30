/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Factory foos for panels
*/

#include <stdlib.h>
#include <stdarg.h>
#include "panel.h"

panel_t *panel_create(rectransform_t *rect, ptype_t type, void *data)
{
    panel_t *panel = malloc(sizeof(panel_t));
    if (!panel)
        return NULL;
    panel->shape = NULL;
    panel->sprite = NULL;
    panel->text = NULL;
    panel->type = type;
    panel->state = PANEL_STATE_ACTIVE;
    panel->data = data;
    panel->rect = rect;
    panel->pos = (sfVector2f){0, 0};
    panel->size = (sfVector2f){0, 0};
    panel->childs = NULL;
    panel->childs_count = 0;
    return panel;
}

void panel_destroy(panel_t *panel)
{
    if (!panel)
        return;
    for (int i = 0; i < panel->childs_count; i++)
        panel_destroy(panel->childs[i]);
    free(panel);
}

void panel_add_childs(panel_t *parent, size_t n, ...)
{
    va_list ap;
    panel_t **childs = malloc(sizeof(panel_t *) * n + 1);

    if (!parent || !childs)
        return;
    va_start(ap, n);
    for (size_t i = 0; i < n; i++)
        childs[i] = va_arg(ap, panel_t *);
    va_end(ap);
    parent->childs = childs;
    parent->childs_count = n;
    parent->childs[n] = NULL;
}
