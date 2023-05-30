/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Foos for dropdowns
*/

#include "program.h"
#include "ui_panels/dropdown.h"
#include "ui_panels/button.h"
#include "ui_panels/flex.h"
#include "tools.h"
#include "theme.h"

panel_t *make_dd(size_t count, sfVector2f size)
{
    panel_t *panel = make_flex((sfVector2i){1, count}, size);
    init_rshape(&(panel->shape), DROPDOWNCOLOR);
    panel->rect->xanchor = ANCHOR_START;
    panel->rect->yanchor = ANCHOR_END;
    panel->rect->pos.y = size.y;
    panel->state = PANEL_STATE_INACTIVE;
    return panel;
}

panel_t *make_ddbutt(sfFont *font, const char *str)
{
    rectransform_t *rect = rtrans_create_flexelem((sfVector2f){ELEMX, ELEMY});
    panel_t *panel = panel_text_button_create(
        rect, str, font, PTYPE_DDBUTT);
    butt_set_foos(panel, dds_select, dds_unselect);
    ((panel_button_t *)(panel->data))->trgt = panel;
    return panel;
}

void dds_select(void *data)
{
    if (!data)
        return;
    panel_t *panel = (panel_t *)data;
    if (!panel->childs || !panel->childs[0])
        return;
    panel->childs[0]->state = PANEL_STATE_ACTIVE;
}

void dds_unselect(void *data)
{
    if (!data)
        return;
    panel_t *panel = (panel_t *)data;
    if (!panel->childs || !panel->childs[0])
        return;
    panel->childs[0]->state = PANEL_STATE_INACTIVE;
}
