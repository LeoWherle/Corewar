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

void on_num_ipanel_entry(sfTextEvent t, panel_input_t *input)
{
    if (t.unicode >= '0' && t.unicode <= '9' && input->left > 0) {
        input->text[input->max_size - input->left] = t.unicode;
        input->left--;
    } else if (t.unicode == '\b' && input->left < 4) {
        input->left++;
        input->text[input->max_size - input->left] = '\0';
    }
    *(input->trgt_int) = fast_atoi(input->text);
}

void on_text_ipanel_entry(sfTextEvent t, panel_input_t *input)
{
    if (t.unicode >= 'a' && t.unicode <= 'z' && input->left > 0) {
        input->text[input->max_size - input->left] = t.unicode;
        input->left--;
    } else if (t.unicode == '\b' && input->left < 10) {
        input->left++;
        input->text[input->max_size - input->left] = '\0';
    }
    *(input->trgt_str) = input->text;
}

void on_text_entered(sfTextEvent t, panel_t *panel)
{
    panel_input_t *input = (panel_input_t *)panel->data;
    sfFloatRect trect;
    switch (input->type) {
        case EntryTypeNumber: on_num_ipanel_entry(t, input); break;
        case EntryTypeLetter: on_text_ipanel_entry(t, input); break;
        default: break;
    }
    sfText_setString(panel->text, input->text);
    trect = sfText_getLocalBounds(panel->text);
    sfText_setOrigin(panel->text, (sfVector2f){
        trect.left + trect.width / 2.0f, trect.top + trect.height / 2.0f});
}
