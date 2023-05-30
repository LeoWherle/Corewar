/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program start
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "program.h"

int start_first_scene(program_t *p)
{
    sfVideoMode mode = {p->params.width, p->params.height, WDEPTH};

    p->current_scene = 0;
    p->window = sfRenderWindow_create(mode,
        WNAME, WRULE | (p->params.fullscreen ? sfFullscreen : 0), NULL);
    if (!(p->window))
        return 1;
    sfRenderWindow_setFramerateLimit(p->window, 60);
    resize_event(p, (sfSizeEvent)
        {.width = p->params.width, .height = p->params.height});
    return EXIT_SUCCESS;
}

int start_scene(program_t *p, int i)
{
    scene_t *s = p->scenes[p->current_scene];
    float scale = s->canvas->scale;

    on_panel_unselect(s->canvas->selected);
    s->canvas->selected = NULL;
    s = p->scenes[i];
    s->canvas->scale = scale;
    on_panel_unselect(s->canvas->selected);
    s->canvas->selected = NULL;
    p->current_scene = i;
    if (!(p->window))
        return 1;
    canvas_resize(p->scenes[p->current_scene]->canvas,
        &(sfVector2f){p->params.width / 2, p->params.height / 2},
        &(sfVector2f){p->params.width, p->params.height});
    resize_event(p, (sfSizeEvent)
        {.width = p->params.width, .height = p->params.height});
    auto_resize(p);
    return EXIT_SUCCESS;
}

int start_program(program_t *p)
{
    if (p->pstate != Created)
        return 1;
    if (start_first_scene(p) == 1)
        return 1;
    p->pstate = Started;
    sfMusic_play(p->music);
    return EXIT_SUCCESS;
}
