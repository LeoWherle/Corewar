/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Selcting foos for panels
*/

#include "ui_panels/button.h"
#include "program.h"
#include "theme.h"
#include "tools.h"

void on_panel_select(panel_t *panel)
{
    if (!panel)
        return;
    if (is_interactable(panel->type)) {
        if (panel->shape)
            sfRectangleShape_setFillColor(panel->shape, BUTTON_SELECT);
    }
    if (panel->type == PTYPE_DDBUTT) {
        panel_button_t *bpanel = (panel_button_t *)panel->data;
        if (bpanel->on_select)
            bpanel->on_select(bpanel->trgt);
    }
    if (panel->type == PTYPE_EVBUTT) {
        panel_button_t *bpanel = (panel_button_t *)panel->data;
        if (bpanel && bpanel->on_select)
            bpanel->on_select(bpanel->trgt);
    }
}

void on_panel_unselect(panel_t *panel)
{
    if (!panel)
        return;
    if (is_interactable(panel->type)) {
        if (!panel->shape)
            return;
        if (panel->type == PANEL_TYPE_INPUT)
            sfRectangleShape_setFillColor(panel->shape, INPUT_COLOR);
        else
            sfRectangleShape_setFillColor(panel->shape, BUTTON_BASE);
    }
    if (panel->type == PTYPE_DDBUTT) {
        panel_button_t *bpanel = (panel_button_t *)panel->data;
        if (bpanel->on_unselect)
            bpanel->on_unselect(bpanel->trgt);
    }
}
