/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for input panels
*/

#include <stdlib.h>
#include "program.h"
#include "ui_panels/input.h"
#include "tools.h"
#include "theme.h"

panel_t *make_name_input(sfFont *font, char **trgt)
{
    rectransform_t *rect = rtrans_create_flexelem((sfVector2f){ELEMX, ELEMY});
    panel_t *panel = panel_input_create(rect, font, EntryTypeLetter, *trgt);
    panel_input_t *input = (panel_input_t *) panel->data;

    input->trgt_str = trgt;
    return panel;
}

static void init_ipanel(
    panel_input_t *ipanel, entry_type_t type, const char *initstr)
{
    int i = 0;
    if (!ipanel)
        return;
    ipanel->type = type;
    switch (type) {
        case EntryTypeNumber: ipanel->max_size = MAXNUMLEN; break;
        case EntryTypeLetter: ipanel->max_size = MAXSTRLEN; break;
        default: ipanel->max_size = 0; break;
    }
    ipanel->left = ipanel->max_size;
    ipanel->text = malloc(sizeof(char) * (ipanel->max_size + 1));
    if (!ipanel->text)
        return;
    for (; initstr[i] && i < ipanel->max_size; i++)
        ipanel->text[i] = initstr[i];
    for (; i < ipanel->max_size; i++)
        ipanel->text[i] = '\0';
    ipanel->text[ipanel->max_size] = '\0';
}

panel_t *panel_input_create(
    rectransform_t *rect, sfFont *font,
    entry_type_t type, const char *initstr)
{
    panel_input_t *ipanel = malloc(sizeof(panel_input_t));
    panel_t *panel = NULL;

    if (!ipanel)
        return NULL;
    panel = panel_create(rect, PANEL_TYPE_INPUT, ipanel);
    if (!panel)
        return NULL;
    init_ipanel(ipanel, type, "");
    init_rshape(&panel->shape, INPUT_COLOR);
    init_text(&panel->text, font, initstr, 20);
    sfText_setColor(panel->text, INPUT_TEXT_COLOR);
    return panel;
}
