/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Update foos for scenes
*/

#include "scene.h"

void scene_draw(sfRenderWindow *window, scene_t *scene)
{
    if (!window || !scene)
        return;
    if (scene->content && scene->content->drawer)
        scene->content->drawer(window, scene->content->content);
    canvas_draw(window, scene->canvas);
}

void scene_loop(sfRenderWindow *window, scene_t *scene, float dt)
{
    if (!window || !scene || !scene->content || !scene->content->looper)
        return;
    if (scene->content->state == CONTENT_STATE_PLAY)
        scene->content->looper(scene->content->content, dt);
}

void scene_event(scene_t *s, sfEvent e)
{
    switch (e.type) {
    case sfEvtMouseMoved:
        scene_hover(s, (sfVector2i){e.mouseMove.x, e.mouseMove.y}); break;
    case sfEvtMouseButtonPressed:
        scene_pressed(s, e.mouseButton); break;
    case sfEvtMouseButtonReleased:
        scene_released(s, e.mouseButton); break;
    case sfEvtKeyPressed:
        scene_key_pressed(s, e.key); break;
    case sfEvtKeyReleased:
        scene_key_released(s, e.key); break;
    default: break;
    }
}
