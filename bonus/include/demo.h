/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for demo
*/

#ifndef DEMO_H
    #define DEMO_H
    #define TIME_SCALE_MAX 2
    #define CYCLE_PER_SEC 50
    #define HELP_TEXT "BONUS\nUSAGE\n\t./bonus\nInfo:\n\tLaunch the corewar bonus\n"
    #include "theme.h"
    #include "program.h"
    #include "vm.h"

typedef struct vm_container_s {
    vm_t *vm;
    float seconds;
    float timescale;
    sfText *cycleText;
    sfText *totalcycleText;
    sfText *timescaleText;
    sfText *nblivetext;
    sfText *champ1text;
    sfText *champ2text;
    sfText *champ3text;
    sfText *champ4text;
    panel_t *vmflex;
    panel_t *winpanel;
} vm_container_t;

vm_container_t *vm_container_create(program_t *p, vm_t *vm);
int vm_container_update(vm_container_t *vmc, float seconds);
panel_t *demogame(program_t *p);
content_t *demo_content_maker(program_t *prog, int ac, const char **av);
panel_t *game_interface(program_t *p);
#endif /* DEMO_H */
