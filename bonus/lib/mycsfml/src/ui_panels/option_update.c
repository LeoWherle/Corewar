/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#include "program.h"
#include "ui_panels/draggable.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "ui_panels/empty.h"
#include "tools.h"
#include "theme.h"
#include "ui_panels/button.h"
#include "ui_panels/options.h"
#include "ui_panels/dropdown.h"
#include "ui_panels/slider.h"

void update_music_volume(void *in, float value)
{
    program_t *prog = (program_t *)in;
    prog->params.music_volume = value;
    sfMusic_setVolume(prog->music,
        value * VOLRANGE + MUSICVOLUME - VOLRANGE / 2);
}

void update_sound_volume(void *in, float value)
{
    program_t *prog = (program_t *)in;
    canvas_t *c = prog->scenes[prog->current_scene]->canvas;

    prog->params.sound_volume = value;
    sfSound_setVolume(c->soundppress,
        value * VOLRANGE + SOUNDVOLUME - VOLRANGE / 2);
    sfSound_setVolume(c->soundprelease,
        value * VOLRANGE + SOUNDVOLUME - VOLRANGE / 2);
}

void option_esc_pressed(scene_t *s)
{
    panel_t *mainp = s->canvas->panels[0];
    panel_t *escp = mainp->childs[1];

    s->content->state = CONTENT_STATE_PAUSE;
    if (s->content->on_pause)
        s->content->on_pause(s->content);
    if (escp->state == PANEL_STATE_ACTIVE) {
        mainp->childs[0]->state = PANEL_STATE_ACTIVE;
        escp->state = PANEL_STATE_INACTIVE;
    } else {
        mainp->childs[0]->state = PANEL_STATE_INACTIVE;
        escp->state = PANEL_STATE_ACTIVE;
    }
    mainp->childs[2]->state = PANEL_STATE_INACTIVE; 
    if (mainp->childs[0]->state == PANEL_STATE_ACTIVE)
        s->content->state = CONTENT_STATE_PLAY;
}
