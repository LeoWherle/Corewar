/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Base functions for video options
*/

#include "program.h"

void set_high_resol(void *p)
{
    program_t *prog = (program_t *)p;

    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){HRESOL, WDEPTH},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, WFPS);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){HRESOL});
    auto_resize(prog);
}

void set_medium_resol(void *p)
{
    program_t *prog = (program_t *)p;

    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){MRESOL, WDEPTH},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, WFPS);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){MRESOL});
    auto_resize(prog);
}

void set_low_resol(void *p)
{
    program_t *prog = (program_t *)p;

    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){LRESOL, WDEPTH},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, WFPS);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){LRESOL});
    auto_resize(prog);
}

void set_mini_resol(void *p)
{
    program_t *prog = (program_t *)p;

    if (prog->params.fullscreen) {
        prog->params.fullscreen = 0;
        sfRenderWindow_close(prog->window);
        prog->window = sfRenderWindow_create((sfVideoMode){XSRESOL, WDEPTH},
            WNAME, WRULE, NULL);
        sfRenderWindow_setFramerateLimit(prog->window, WFPS);
        return;
    }
    sfRenderWindow_setSize(prog->window, (sfVector2u){XSRESOL});
    auto_resize(prog);
}

void toggle_fullscreen(void *data)
{
    program_t *p = (program_t *)data;
    p->params.fullscreen = !p->params.fullscreen;
    sfRenderWindow_destroy(p->window);
    p->window = sfRenderWindow_create(
        (sfVideoMode){p->params.width, p->params.height, WDEPTH},
        WNAME, WRULE | (p->params.fullscreen ? sfFullscreen : 0), NULL);
    sfRenderWindow_setFramerateLimit(p->window, WFPS);
    auto_resize(p);
}
