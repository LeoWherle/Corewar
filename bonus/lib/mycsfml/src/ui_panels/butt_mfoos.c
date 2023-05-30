/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdio.h>
#include "program.h"

void change_scene(void *data)
{
    program_t *program = (program_t *) data;
    (void) start_scene(program, program->current_scene + 1);
}

void quit_program(void *data)
{
    program_t *program = (program_t *) data;
    program->pstate = Quit;
}

void open_options(void *data)
{
    program_t *p = (program_t *) data;
    panel_t **panels = p->scenes[p->current_scene]->canvas->panels[0]->childs;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[2]->state = PANEL_STATE_ACTIVE;
}

void open_cmds(void *data)
{
    program_t *p = (program_t *) data;
    panel_t **panels = p->scenes[p->current_scene]->canvas->panels[0]->childs;

    panels[1]->state = PANEL_STATE_INACTIVE;
    panels[5]->state = PANEL_STATE_ACTIVE;
}
