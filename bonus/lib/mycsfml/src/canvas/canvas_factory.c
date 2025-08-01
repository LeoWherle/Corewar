/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Factory foos for canvases
*/

#include <SFML/Audio.h>
#include "stdlib.h"
#include "canvas.h"
#include "theme.h"
#include "program.h"

static void load_canvas_sounds(canvas_t *canvas)
{
    canvas->spbuf = sfSoundBuffer_createFromFile(PATHTOASSETS PRESS_SOUND);
    canvas->soundppress = sfSound_create();
    sfSound_setBuffer(canvas->soundppress, canvas->spbuf);
    sfSound_setVolume(canvas->soundppress, SOUNDVOLUME);
    canvas->srbuf = sfSoundBuffer_createFromFile(PATHTOASSETS RELEASE_SOUND);
    canvas->soundprelease = sfSound_create();
    sfSound_setBuffer(canvas->soundprelease, canvas->srbuf);
    sfSound_setVolume(canvas->soundprelease, SOUNDVOLUME);
}

canvas_t *canvas_create(panel_t **panels, float scale)
{
    canvas_t *canvas = NULL;

    if (!panels || !panels[0])
        return NULL;
    canvas = malloc(sizeof(canvas_t));
    if (!canvas)
        return NULL;
    canvas->panels = panels;
    canvas->hovered = NULL;
    canvas->pressed = NULL;
    canvas->selected = NULL;
    canvas->scale = scale;
    load_canvas_sounds(canvas);
    return canvas;
}

void canvas_destroy(canvas_t *canvas)
{
    for (int i = 0; canvas->panels[i]; i++)
        panel_destroy(canvas->panels[i]);
    sfSoundBuffer_destroy(canvas->spbuf);
    sfSoundBuffer_destroy(canvas->srbuf);
    sfSound_destroy(canvas->soundppress);
    sfSound_destroy(canvas->soundprelease);
    free(canvas);
}
