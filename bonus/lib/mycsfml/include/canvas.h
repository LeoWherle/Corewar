/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for canvas struct
*/

#ifndef CANVAS_H
    #define CANVAS_H
    #include <SFML/Audio.h>
    #include "panel.h"

typedef struct canvas_s {
    panel_t **panels;
    panel_t *hovered;
    panel_t *pressed;
    panel_t *selected;
    sfSoundBuffer *spbuf;
    sfSound *soundppress;
    sfSoundBuffer *srbuf;
    sfSound *soundprelease;
    float scale;
} canvas_t;

canvas_t *canvas_create(panel_t **panels, float scale);
void canvas_destroy(canvas_t *canvas);
void canvas_resize(canvas_t *c, sfVector2f *pos, sfVector2f *size);
void canvas_hover(canvas_t *c, sfVector2i *pos);
void canvas_pressed(canvas_t *c, sfMouseButtonEvent e);
void canvas_released(canvas_t *c, sfMouseButtonEvent e);
void canvas_draw(sfRenderWindow *window, canvas_t *canvas);
#endif /* CANVAS_H */
