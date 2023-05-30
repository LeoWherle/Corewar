/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for button panels
*/

#ifndef SLIDER_H
    #define SLIDER_H
    #include "panel.h"

typedef void (*slider_foo_t)(void *, float);

typedef struct panel_slider_s {
    void *trgt;
    slider_foo_t foo;
} panel_slider_t;

panel_t *make_slider(
    void *trgt, slider_foo_t foo, float init_value, float scale);
panel_t *panel_slider_create(rectransform_t *);
void panel_slider_destroy(panel_t *);

#endif /* SLIDER_H */
