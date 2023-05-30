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
#include "program.h"

panel_t *make_ibutt(
    const char *label, void *trgt, button_foo_t foo, sfFont *font)
{
    sfVector2f size = {ITEMSIZEX, ITEMSIZEY};
    rectransform_t *sb_rect = rtrans_create_flexelem(size);
    panel_t *butt = panel_text_button_create(
        sb_rect, strdup(label), font, PTYPE_EVBUTT);

    ((panel_button_t *)butt->data)->trgt = trgt;
    butt_set_foos(butt, foo, NULL);
    return butt;
}

panel_t *make_butt(
    const char *label, void *trgt, button_foo_t foo, sfFont *font)
{
    sfVector2f size = {ELEMX, ELEMY};
    rectransform_t *sb_rect = rtrans_create_flexelem(size);
    panel_t *butt = panel_text_button_create(
        sb_rect, strdup(label), font, PTYPE_EVBUTT);

    ((panel_button_t *)butt->data)->trgt = trgt;
    butt_set_foos(butt, foo, NULL);
    return butt;
}

void butt_set_foos(panel_t *p, button_foo_t select, button_foo_t unselect)
{
    panel_button_t *bpanel = NULL;

    if (!p)
        return;
    bpanel = (panel_button_t *)p->data;
    bpanel->on_select = select;
    bpanel->on_unselect = unselect;
}
