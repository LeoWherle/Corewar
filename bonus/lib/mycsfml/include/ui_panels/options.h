/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for empty panels
*/

#ifndef PANEL_OPTION_H
    #define PANEL_OPTION_H
    #include "program.h"

typedef void (*slider_target)(void *, float);
panel_t *escmenuflex(program_t *p);
panel_t *paramenuflex(program_t *p);
void toggle_fullscreen(void *data);
void set_high_resol(void *p);
void set_medium_resol(void *p);
void set_low_resol(void *p);
void set_mini_resol(void *p);
void option_esc_pressed(scene_t *s);
void update_music_volume(void *in, float value);
void update_sound_volume(void *in, float value);
#endif /* PANEL_OPTION_H */
