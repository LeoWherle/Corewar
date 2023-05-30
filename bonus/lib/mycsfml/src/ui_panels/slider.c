/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdlib.h>
#include <string.h>
#include "ui_panels/slider.h"
#include "ui_panels/empty.h"
#include "ui_panels/draggable.h"
#include "theme.h"
#include "tools.h"
#include "program.h"

static void init_handle_pos_at_value(panel_t *dpanel, float value, float scale)
{
    panel_drag_t *dpanel_data = (panel_drag_t *)dpanel->data;

    dpanel->rect->pos = (sfVector2f){value * dpanel_data->bounds.width
        * scale + dpanel_data->bounds.left * scale, 0};
    dpanel_data->offset = dpanel->rect->pos;
}

panel_t *make_slider(
    void *trgt, slider_foo_t foo, float init_value, float scale)
{
    panel_slider_t *spanel = NULL;
    rectransform_t *rect = rtrans_create_flexelem((sfVector2f){ELEMX, ELEMY});
    panel_t *epanel = panel_slider_create(rect);

    panel_add_childs(epanel, 2, make_handle_drag((sfVector2f){0, 0}, epanel),
        panel_empty_create(rtrans_create_flexelem(
            (sfVector2f){ELEMX - 2 * ELEMMARGIN, ELEMY / 5}), ITEM_BG));
    spanel = (panel_slider_t *)epanel->data;
    spanel->trgt = trgt;
    spanel->foo = foo;
    init_handle_pos_at_value(epanel->childs[0], init_value, scale);
    return epanel;
}

static panel_slider_t *slider_create(void)
{
    panel_slider_t *bpanel = malloc(sizeof(panel_slider_t));

    if (!bpanel)
        return NULL;
    bpanel->trgt = NULL;
    bpanel->foo = NULL;
    return bpanel;
}

panel_t *panel_slider_create(rectransform_t *rect)
{
    panel_slider_t *bpanel = slider_create();
    panel_t *panel = NULL;

    if (!bpanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_SLIDER, bpanel);
    if (!panel)
        return NULL;
    init_rshape(&(panel->shape), BUTTON_BASE);
    return panel;
}

void panel_slider_destroy(panel_t *panel)
{
    panel_slider_t *bpanel = NULL;

    if (!panel)
        return;
    bpanel = (panel_slider_t *)panel->data;
    if (!bpanel)
        return;
    free(bpanel);
    panel_destroy(panel);
}
