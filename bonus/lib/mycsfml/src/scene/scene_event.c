/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Event foos for scenes
*/

#include "ui_panels/options.h"
#include "ui_panels/start.h"
#include "program.h"

void scene_hover(scene_t *s, sfVector2i e)
{
    if (!s)
        return;
    if (!s->content || s->content->state == CONTENT_STATE_PAUSE) {
        canvas_hover(s->canvas, &e);
        return;
    }
    if (s->canvas->hovered == NULL) {
        canvas_hover(s->canvas, &e);
        if (s->canvas->hovered != NULL && s->content->on_leave)
            s->content->on_leave(s->content->content);
    } else {
        canvas_hover(s->canvas, &e);
        if (s->canvas->hovered == NULL && s->content->on_enter)
            s->content->on_enter(s->content->content);
    }
    if (s->content->on_hover)
        s->content->on_hover(s->content->content, &e);
}

void scene_pressed(scene_t *s, sfMouseButtonEvent e)
{
    if (!s)
        return;
    sfSound_play(s->canvas->soundppress);
    if (e.button == sfMouseLeft)
        canvas_pressed(s->canvas, e);
    if (s->canvas->hovered == NULL && s->content && s->content->on_press)
        s->content->on_press(s->content, e);
}

void scene_released(scene_t *s, sfMouseButtonEvent e)
{
    if (!s)
        return;
    sfSound_play(s->canvas->soundprelease);
    if (e.button == sfMouseLeft)
        canvas_released(s->canvas, e);
    if (s->content && s->content->on_release)
        s->content->on_release(s->content, e);
}

void scene_key_pressed(scene_t *s, sfKeyEvent e)
{
    content_t *c = NULL;

    if (!s)
        return;
    c = s->content;
    if (e.code == sfKeyEscape) {
        on_panel_unselect(s->canvas->selected);
        s->canvas->selected = NULL;
        if (c)
            option_esc_pressed(s);
        else
            start_esc_pressed(s);
    }
    if ( c && c->on_key_press)
        c->on_key_press(c, e);
}

void scene_key_released(scene_t *s, sfKeyEvent e)
{
    if (!s)
        return;
    if (s->content && s->content->on_key_release)
        s->content->on_key_release(s->content, e);
}
