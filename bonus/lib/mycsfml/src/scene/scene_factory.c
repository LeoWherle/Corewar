/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Factory foos for scenes
*/

#include <stdlib.h>
#include "scene.h"
#include "canvas.h"

scene_t *scene_create(panel_t **panels, content_t *content, float scale)
{
    scene_t *scene = NULL;
    canvas_t *canvas = NULL;

    canvas = canvas_create(panels, scale);
    if (!canvas)
        return NULL;
    scene = malloc(sizeof(scene_t));
    if (!scene)
        return NULL;
    scene->canvas = canvas;
    scene->content = content;
    return scene;
}

static void scene_destroy(scene_t *scene)
{
    if (!scene)
        return;
    canvas_destroy(scene->canvas);
    free(scene);
}

void scenes_destroy(scene_t **scenes)
{
    for (int i = 0; scenes[i]; i++)
        scene_destroy(scenes[i]);
    free(scenes);
}
