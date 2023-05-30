/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Hovering foos for panels
*/

#include "theme.h"
#include "content.h"
#include "tools.h"

void on_panel_enter(panel_t *panel)
{
    if (!panel)
        return;
    if (is_interactable(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_HOVER);
    }
}

void on_panel_leave(panel_t *panel)
{
    if (!panel)
        return;
    if (is_interactable(panel->type)) {
        if (!(panel->shape))
            return;
        if (panel->type == PANEL_TYPE_INPUT)
            sfRectangleShape_setFillColor(panel->shape, INPUT_COLOR);
        else
            sfRectangleShape_setFillColor(panel->shape, BUTTON_BASE);
    }
}

void on_panel_pressed(panel_t *panel)
{
    if (!panel)
        return;
    if (is_interactable(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_PRESS);
    }
}

void on_panel_released(panel_t *panel)
{
    if (!panel)
        return;
    if (is_interactable(panel->type)) {
        if (panel->shape)
            return;
        if (panel->type == PANEL_TYPE_INPUT)
            sfRectangleShape_setFillColor(panel->shape, INPUT_COLOR);
        else
            sfRectangleShape_setFillColor(panel->shape, BUTTON_BASE);
    }
}
