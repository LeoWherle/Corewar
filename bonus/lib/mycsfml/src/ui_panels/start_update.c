/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include "program.h"
#include "ui_panels/flex.h"
#include "ui_panels/text.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/empty.h"
#include "tools.h"
#include "ui_panels/buttallfoos.h"
#include "theme.h"

void start_esc_pressed(scene_t *s)
{
    panel_t *mainp = s->canvas->panels[0];
    panel_t *startp = mainp->childs[0];

    if (mainp->childs[1]->state == PANEL_STATE_INACTIVE) {
        return;
    }
    if (startp->state == PANEL_STATE_ACTIVE) {
        startp->state = PANEL_STATE_INACTIVE;
    } else {
        startp->state = PANEL_STATE_ACTIVE;
    }
    mainp->childs[1]->state = PANEL_STATE_INACTIVE;
}

void mopen_options(void *data)
{
    program_t *p = (program_t *) data;
    panel_t **panels = p->scenes[0]->canvas->panels[0]->childs;

    panels[0]->state = PANEL_STATE_INACTIVE;
    panels[1]->state = PANEL_STATE_ACTIVE;
}
