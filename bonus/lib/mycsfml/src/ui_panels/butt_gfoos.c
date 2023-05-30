/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "program.h"

void quit_game(void *data)
{
    program_t *program = (program_t *) data;
    scene_t *scene = program->scenes[program->current_scene];
    panel_t **panels = scene->canvas->panels[0]->childs;

    panels[0]->state = PANEL_STATE_ACTIVE;
    panels[1]->state = PANEL_STATE_INACTIVE;
    (void) start_scene(program, 0);
}

void continue_program(void *data)
{
    program_t *program = (program_t *) data;
    scene_t *scene = program->scenes[program->current_scene];
    panel_t **panels = scene->canvas->panels[0]->childs;

    panels[0]->state = PANEL_STATE_ACTIVE;
    panels[1]->state = PANEL_STATE_INACTIVE;
    scene->content->state = CONTENT_STATE_PLAY;
}

void open_inventory(void *data)
{
    program_t *p = (program_t *) data;
    panel_t **panels = p->scenes[p->current_scene]->canvas->panels[0]->childs;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[2]->state = PANEL_STATE_ACTIVE;
}

void open_stats(void *data)
{
    program_t *p = (program_t *) data;
    panel_t **panels = p->scenes[p->current_scene]->canvas->panels[0]->childs;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[3]->state = PANEL_STATE_ACTIVE;
}
