/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for button panels
*/

#ifndef BUTTON_H
    #define BUTTON_H
    #include "panel.h"

typedef void (*button_foo_t)(void *);

typedef struct panel_button_s {
    const char *text;
    sfTexture *texture;
    void *trgt;
    void (*on_enter)(void *);
    void (*on_exit)(void *);
    void (*on_press)(void *);
    void (*on_release)(void *);
    void (*on_select)(void *);
    void (*on_unselect)(void *);
} panel_button_t;

panel_t *make_ibutt(
    const char *label, void *trgt, button_foo_t foo, sfFont *font);
panel_t *make_butt(
    const char *label, void *trgt, button_foo_t foo, sfFont *font);
panel_t *panel_text_button_create(
    rectransform_t *, const char *, sfFont *, ptype_t);
panel_t *panel_image_button_create(rectransform_t *, sfTexture *, ptype_t);
void panel_button_destroy(panel_t *);

void butt_set_foos(panel_t *, button_foo_t, button_foo_t);
panel_t *make_scale_control(sfFont *font, void *trgt);
#endif /* BUTTON_H */
