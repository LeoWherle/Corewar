/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Resizing foos for panel
*/

#include <stdio.h>
#include "panel.h"
#include "ui_panels/flex.h"
#include "ui_panels/draggable.h"

static void sprite_rect_set(panel_t *panel)
{
    sfVector2f sprite_pos = {0, 0};
    sfFloatRect sprite_size = sfSprite_getGlobalBounds(panel->sprite);

    sprite_pos.x = panel->pos.x + (panel->size.x - sprite_size.width) / 2;
    sprite_pos.y = panel->pos.y + (panel->size.y - sprite_size.height) / 2;
    sfSprite_setPosition(panel->sprite, sprite_pos);
    sfSprite_setScale(panel->sprite, (sfVector2f){
        panel->size.x,
        panel->size.y});
}

static void text_rect_set(panel_t *panel, float scale)
{
    sfFloatRect trect;

    sfText_setCharacterSize(panel->text, (unsigned int) 20.0 * scale);
    trect = sfText_getLocalBounds(panel->text);
    sfText_setOrigin(panel->text, (sfVector2f){
        trect.left + trect.width / 2.0f, trect.top + trect.height / 2.0f});
    sfText_setPosition(panel->text, panel->pos);
}

static void panel_rect_set(panel_t *panel, float scale)
{
    if (!panel)
        return;
    if (panel->shape) {
        sfRectangleShape_setSize(panel->shape, panel->size);
        sfRectangleShape_setOrigin(panel->shape,
            (sfVector2f){panel->size.x / 2, panel->size.y / 2});
        sfRectangleShape_setPosition(panel->shape, panel->pos);
    }
    if (panel->sprite) {
        sprite_rect_set(panel);
    }
    if (panel->text) {
        text_rect_set(panel, scale);
    }
}

void panel_resize(
    panel_t *panel, sfVector2f *pos, sfVector2f *size, float scale)
{
    if (!panel || !pos || !size)
        return;
    if (panel->type == PANEL_TYPE_DRAG)
        drag_repos(panel, scale);
    panel->pos = rtrans_pos_update(panel->rect, pos, size);
    if (panel->rect->resize == RESIZE_X || panel->rect->resize == RESIZE_XY)
        panel->pos.x = 0;
    if (panel->rect->resize == RESIZE_Y || panel->rect->resize == RESIZE_XY)
        panel->pos.y = 0;
    if (panel->type == PANEL_TYPE_FLEX)
        panel_flex_update(panel);
    panel->size = rtrans_size_update(panel->rect, size, scale);
    for (int i = 0; i < panel->childs_count; i++)
        panel_resize(panel->childs[i], &(panel->pos), &(panel->size), scale);
    panel_rect_set(panel, scale);
    if (panel->type == PANEL_TYPE_FLEX)
        panel_flex_repos(panel, scale);
}
