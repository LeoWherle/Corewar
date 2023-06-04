/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** intro main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "program.h"
#include "intro.h"
#include "vm.h"

void skip_into(intro_t *intro)
{
    if (intro->versus == true) {
        sfMusic_stop(intro->vssound);
        intro->versus = false;
        intro->end = true;
    }
    if (intro->walkout == true) {
        intro->frame_nb = 1;
        sfMusic_stop(intro->music);
        sfMusic_play(intro->vssound);
        intro->walkout = false;
        intro->versus = true;
    }
}

intro_t *intro_init()
{
    intro_t *intro = malloc(sizeof(intro_t));

    //TMP WINDOW
    intro->window = sfRenderWindow_create(
        (sfVideoMode){1920, 1080, 32}, "Corewar", sfFullscreen, NULL);
    //TMP WINDOW
    sfRenderWindow_setFramerateLimit(intro->window, 30);
    intro->frame = sfTexture_createFromFile("bonus/ressources/intros/DeeCam/image-1.png", NULL);
    intro->sprite = sfSprite_create();
    sfSprite_setTexture(intro->sprite, intro->frame, sfTrue);
    sfSprite_setScale(intro->sprite, (sfVector2f){1.5, 1.5});
    intro->frame_nb = 1;
    memset(intro->path, 0, 70);
    intro->walkout = true;
    intro->versus = false;
    intro->end = false;
    intro->intro_index = rand() % 9;
    intro->preload_index = 0;
    intro->no_frame = false;
    intro->music = sfMusic_createFromFile("bonus/ressources/intro_theme.ogg");
    intro->vssound = sfMusic_createFromFile("bonus/ressources/versus_sound.ogg");
    sfMusic_play(intro->music);
    return intro;
}

int detroy_intro(intro_t *intro, int champs_nb)
{
    sfSprite_destroy(intro->sprite);
    sfTexture_destroy(intro->frame);
    sfMusic_destroy(intro->music);
    sfMusic_destroy(intro->vssound);
    for (int i = 0; i < intro->preload_index; i++)
        sfImage_destroy(intro->images[i]);
    sfFont_destroy(intro->font);
    for (int i = 0; i < champs_nb; i++)
        sfText_destroy(intro->champions[i]);
    sfRenderWindow_destroy(intro->window);
    free(intro);
    return 0;
}

int intro_main(UNUSED program_t *prog, vm_t *vm)
{
    intro_t *intro = NULL;

    srand(time(NULL));
    intro = intro_init();
    set_text(intro, vm);
    while (!intro->end) {
        sfRenderWindow_clear(intro->window, sfBlack);
        while (sfRenderWindow_pollEvent(intro->window, &intro->event))
            if (intro->event.type == sfEvtMouseButtonPressed)
                skip_into(intro);
        if (intro->walkout)
            play_walkout(intro, vm);
        sfRenderWindow_drawSprite(intro->window, intro->sprite, NULL);
        if (intro->versus) {
            play_versus(intro, vm);
            for (int i = 0; i < vm->champions->size; i++)
                sfRenderWindow_drawText(intro->window, intro->champions[i], NULL);
        }
        sfRenderWindow_display(intro->window);
    }
    detroy_intro(intro, vm->champions->size);
    return 0;
}