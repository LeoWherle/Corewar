/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for scene object
*/

#ifndef SCENE_H
    #define SCENE_H
    #include "canvas.h"
    #include "content.h"

typedef struct scene_s {
    canvas_t *canvas;
    content_t *content;
} scene_t;

scene_t *scene_create(panel_t **panels, content_t *content, float scale);
void scenes_destroy(scene_t **scenes);

void scene_hover(scene_t *s, sfVector2i e);
void scene_pressed(scene_t *s, sfMouseButtonEvent e);
void scene_released(scene_t *s, sfMouseButtonEvent e);
void scene_key_pressed(scene_t *s, sfKeyEvent e);
void scene_key_released(scene_t *s, sfKeyEvent e);
void scene_event(scene_t *s, sfEvent e);
void scene_draw(sfRenderWindow *window, scene_t *scene);
void scene_loop(sfRenderWindow *window, scene_t *scene, float dt);
#endif /* SCENE_H */
