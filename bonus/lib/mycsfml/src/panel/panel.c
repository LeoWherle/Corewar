/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for panels
*/

#include <stdlib.h>
#include "panel.h"

void panel_draw(sfRenderWindow *window, panel_t *panel)
{
    if (!panel || !window)
        return;
    if (panel->state == PANEL_STATE_INACTIVE)
        return;
    if (panel->shape)
        sfRenderWindow_drawRectangleShape(window, panel->shape, NULL);
    if (panel->sprite)
        sfRenderWindow_drawSprite(window, panel->sprite, NULL);
    if (panel->text)
        sfRenderWindow_drawText(window, panel->text, NULL);
    for (int i = panel->childs_count - 1; i >= 0; i--)
        panel_draw(window, panel->childs[i]);
}

static panel_t *get_hovered_of(panel_t *panel, sfVector2i *pos)
{
    panel_t *hovered = NULL;
    sfFloatRect rect = {0, 0, 0, 0};

    if (!panel || !pos || panel->state == PANEL_STATE_INACTIVE)
        return NULL;
    rect = (sfFloatRect) {
        (int)(panel->pos.x - panel->size.x / 2),
        (int)(panel->pos.y - panel->size.y / 2),
        (int)panel->size.x,
        (int)panel->size.y};
    for (int i = 0; i < panel->childs_count; i++) {
        hovered = get_hovered_of(panel->childs[i], pos);
        if (hovered)
            break;
    }
    if (!hovered && sfFloatRect_contains(&rect, pos->x, pos->y))
        hovered = panel;
    return hovered;
}

panel_t *get_hovered_panel(panel_t **panels, sfVector2i *pos)
{
    panel_t *hovered = NULL;

    if (!panels || !pos)
        return NULL;
    for (int i = 0; panels[i]; i++) {
        hovered = get_hovered_of(panels[i], pos);
        if (hovered)
            break;
    }
    return hovered;
}
