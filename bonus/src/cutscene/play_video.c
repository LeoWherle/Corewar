/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Video_Player
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intro.h"
#include "vm.h"

static const char intros[2][70] = {
    "bonus/ressources/intros/DeeCam/image-",
    "bonus/ressources/intros/ManMar/image-",
};

static const char vsscreens[3][70] = {
    "bonus/ressources/intros/2VSscreen/image-",
    "bonus/ressources/intros/3VSscreen/image-",
    "bonus/ressources/intros/4VSscreen/image-",
};

void initial_preload(intro_t *intro)
{
    for (int i = 0; i < FRAME_PRELOAD; i++) {
        sprintf(intro->nb_str, "%d.png", intro->frame_nb + i);
        intro->path = strcpy(intro->path, intros[intro->intro_index]);
        intro->path = strcat(intro->path, intro->nb_str);
        intro->images[i] = sfImage_createFromFile(intro->path);
    }
}

int set_frame(intro_t *intro, const char *folder)
{
    sfImage *next_frame = NULL;

    sprintf(intro->nb_str, "%d.png", intro->frame_nb);
    intro->path = strcpy(intro->path, folder);
    intro->path = strcat(intro->path, intro->nb_str);
    next_frame = sfImage_createFromFile(intro->path);
    if (!next_frame)
        return 84;
    intro->images[intro->preload_index] = next_frame;
    intro->preload_index++;
    if (intro->preload_index == FRAME_PRELOAD) {
        for (int i = 0; i < FRAME_PRELOAD; i++)
            sfImage_destroy(intro->images[i]);
        intro->preload_index = 0;
    }
    sfTexture_updateFromImage(intro->frame, next_frame, 0, 0);
    intro->frame_nb++;
    return 0;
}

int play_walkout(intro_t *intro, vm_t *vm)
{
    int keep = intro->intro_index;

    if (set_frame(intro, intros[intro->intro_index]) == 84) {
        intro->frame_nb = 1;
        if (vm->champions->size > 2 && !intro->second_walkout) {
            intro->second_walkout = true;
            intro->intro_index = rand() % NB_DUOS;
            while (intro->intro_index == keep)
                intro->intro_index = rand() % NB_DUOS;
            return 0;
        }
        sfMusic_stop(intro->music);
        sfMusic_play(intro->vssound);
        intro->walkout = false;
        intro->versus = true;
    }
    return 0;
}

int play_versus(intro_t *intro, vm_t *vm)
{
    if (set_frame(intro, vsscreens[vm->champions->size - 2]) == 84) {
        intro->frame_nb = 1;
        intro->versus = false;
        intro->end = true;
    }
    return 0;
}