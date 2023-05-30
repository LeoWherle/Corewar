/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** functions for csfml program
*/

#include <stdlib.h>
#include "program.h"
#include "theme.h"

static void loop_program(program_t *p)
{
    scene_t *scene = NULL;
    if (loop_events(p) == -1)
        return;
    p->dt = sfTime_asSeconds(sfClock_getElapsedTime(p->clock)) - p->last_time;
    p->last_time += p->dt;
    sfRenderWindow_clear(p->window, CLEAR_COLOR);
    scene = p->scenes[p->current_scene];
    scene_loop(p->window, scene, p->dt);
    scene_draw(p->window, scene);
    sfRenderWindow_display(p->window);
}

static void switch_program_state(program_t *p)
{
    switch (p->pstate) {
    case Created: break;
    case Started: loop_program(p); break;
    case Paused: break;
    case End: p->pstate = Quit; break;
    case Quit: sfRenderWindow_close(p->window); break;
    default: break;
    }
}

int execute_program(program_t *prog)
{
    if (!prog)
        return 1;
    if (start_program(prog) == 1) {
        destroy_program(prog);
        return 1;
    }
    sfClock_restart(prog->clock);
    while (sfRenderWindow_isOpen(prog->window))
        switch_program_state(prog);
    destroy_program(prog);
    return EXIT_SUCCESS;
}
