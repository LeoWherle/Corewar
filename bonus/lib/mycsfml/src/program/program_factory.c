/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include "program.h"
#include "theme.h"

program_t *create_program(program_maker_t maker)
{
    program_t *prog = malloc(sizeof(program_t));

    if (!prog)
        return NULL;
    load_hyperparams(&(prog->params), PATHTOASSETS "hyperprog.txt");
    prog->pstate = Created;
    prog->window = NULL;
    prog->cursor = cursor_create();
    prog->current_scene = -1;
    prog->font = sfFont_createFromFile(PATHTOASSETS FONT_TEXT);
    prog->font2 = sfFont_createFromFile(PATHTOASSETS FONT_MEM);
    prog->font3 = sfFont_createFromFile(PATHTOASSETS FONT_CHAMP);
    prog->music = sfMusic_createFromFile(PATHTOASSETS MUSIC);
    prog->clock = sfClock_create();
    sfMusic_setLoop(prog->music, sfTrue);
    sfMusic_setVolume(prog->music,
        prog->params.music_volume * VOLRANGE + MUSICVOLUME - VOLRANGE / 2);
    prog->scenes = maker(prog);
    return prog;
}

void destroy_program(program_t *p)
{
    if (!p)
        return;
    if (p->window)
        sfRenderWindow_destroy(p->window);
    if (p->cursor)
        cursor_destroy(p->cursor);
    if (p->scenes)
        scenes_destroy(p->scenes);
    sfFont_destroy(p->font);
    sfFont_destroy(p->font2);
    sfFont_destroy(p->font3);
    save_hyperparams(&(p->params), PATHTOASSETS "hyperprog.txt");
    sfMusic_destroy(p->music);
    free(p);
}
