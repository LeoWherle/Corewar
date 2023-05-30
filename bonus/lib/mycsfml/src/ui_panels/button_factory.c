/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdlib.h>
#include <string.h>
#include "ui_panels/button.h"
#include "theme.h"
#include "tools.h"

static panel_button_t *button_create(void)
{
    panel_button_t *bpanel = malloc(sizeof(panel_button_t));

    if (!bpanel)
        return NULL;
    bpanel->text = NULL;
    bpanel->texture = NULL;
    bpanel->on_enter = NULL;
    bpanel->on_exit = NULL;
    bpanel->on_press = NULL;
    bpanel->on_release = NULL;
    bpanel->on_select = NULL;
    bpanel->on_unselect = NULL;
    return bpanel;
}

panel_t *panel_text_button_create(
    rectransform_t *rect, const char *str, sfFont *font, ptype_t type)
{
    panel_button_t *bpanel = button_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, type, bpanel);
    if (!panel)
        return NULL;
    init_text(&(panel->text), font, str, 20);
    init_rshape(&(panel->shape), BUTTON_BASE);
    bpanel->text = str;
    return panel;

}

panel_t *panel_image_button_create(
    rectransform_t *rect, sfTexture *texture, ptype_t type)
{
    panel_button_t *bpanel = button_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, type, bpanel);
    if (!panel)
        return NULL;
    init_sprite(&(panel->sprite), texture, rect);
    init_rshape(&(panel->shape), BUTTON_BASE);
    bpanel->texture = texture;
    return panel;
}

void panel_button_destroy(panel_t *panel)
{
    panel_button_t *bpanel = NULL;

    if (!panel)
        return;
    bpanel = (panel_button_t *)panel->data;
    if (!bpanel)
        return;
    if (bpanel->text)
        free((void *)bpanel->text);
    if (bpanel->texture)
        sfTexture_destroy(bpanel->texture);
    free(bpanel);
    panel_destroy(panel);
}
