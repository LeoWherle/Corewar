/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** SF intro cutscene
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include "vm.h"

#ifndef INTRO_H
    #define INTRO_H

    #define FRAME_PRELOAD 20

    typedef struct intro_s {
        //TMP WINDOW
        sfRenderWindow *window;
        //TMP WINDOW
        sfEvent event;
        sfTexture *frame;
        sfSprite *sprite;
        sfMusic *music;
        sfMusic *vssound;
        sfImage *images[FRAME_PRELOAD];
        sfFont *font;
        sfText *champions[4];
        int preload_index;
        int frame_nb;
        char nb_str[10];
        char *path;
        int intro_index;
        bool no_frame;
        bool walkout;
        bool second_walkout;
        bool versus;
        bool end;
    } intro_t;

    typedef struct champ_count_s {
        int size;
        void (*func)(intro_t *);
    } champ_count_t;

    int play_walkout(intro_t *intro, vm_t *vm);
    int play_versus(intro_t *intro, vm_t *vm);
    void set_text(intro_t *intro, vm_t *vm);

#endif /* !INTRO_H */
