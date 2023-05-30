/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <unistd.h>
#include <stdlib.h>
#include "demo.h"
#include "ui_panels/start.h"

scene_t **demo_scenes(program_t *p)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 3);
    panel_t **panels = malloc(sizeof(panel_t *) * 2);

    if (!scenes || !panels)
        return NULL;
    panels[0] = demogame(p);
    panels[1] = NULL;
    scenes[0] = start_menu_scene(p);
    scenes[1] = scene_create(panels, NULL, p->params.scale);
    scenes[2] = NULL;
    return scenes;
}

int show_help(void)
{
    write(1, HELP_TEXT, sizeof(HELP_TEXT));
    return 0;
}

int main(int ac, const char **av)
{
    program_t *prog = NULL;
    prog = create_program(demo_scenes);
    prog->scenes[1]->content = demo_content_maker(prog, ac, av);
    if (!prog->scenes[1]->content) {
        destroy_program(prog);
        return 84;
    }
    return execute_program(prog);
}
