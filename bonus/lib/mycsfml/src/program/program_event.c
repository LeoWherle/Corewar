/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Foos for program events
*/

#include "program.h"
#include "ui_panels/input.h"

void auto_resize(program_t *p)
{
    sfVector2u size = sfRenderWindow_getSize(p->window);
    sfVector2f pos = { -size.x / 2, -size.y / 2};

    canvas_resize(p->scenes[p->current_scene]->canvas, &pos, &(sfVector2f) {
        size.x, size.y });
}

void resize_event(program_t *p, sfSizeEvent e)
{
    sfView *view = NULL;
    sfVector2f size = { e.width, e.height };
    sfVector2f pos = { -size.x / 2, -size.y / 2};

    if (!p->params.fullscreen) {
        p->params.width = e.width;
        p->params.height = e.height;
        view = sfView_createFromRect((sfFloatRect) {0, 0, e.width, e.height });
        sfRenderWindow_setView(p->window, view);
    }
    canvas_resize(p->scenes[p->current_scene]->canvas, &pos, &(size));
}

int switch_program_event(program_t *p, sfEvent e)
{
    canvas_t *c = NULL;

    switch (e.type) {
    case sfEvtClosed: sfRenderWindow_close(p->window); return -1;
    case sfEvtResized: resize_event(p, e.size); break;
    case sfEvtTextEntered:
        c = p->scenes[p->current_scene]->canvas;
        if (c->selected && c->selected->type == PANEL_TYPE_INPUT)
            on_text_entered(e.text, c->selected);
        break;
    default: scene_event(p->scenes[p->current_scene], e); break;
    }
    return 0;
}

int loop_events(program_t *p)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(p->window, &e))
        if (switch_program_event(p, e) == -1)
            return -1;
    return 0;
}
