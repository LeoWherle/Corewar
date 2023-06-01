/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for program object
*/

#ifndef PROGRAM_H
    #define PROGRAM_H
    #define WRULE sfClose | sfResize | sfTitlebar
    #define WNAME "Libmycsfml"
    #define WDEPTH 32
    #define WFPS 60
    #define HRESOL 1920, 1080
    #define STRHRESOL "1920x1080"
    #define MRESOL 1280, 720
    #define STRMRESOL "1280x720"
    #define LRESOL 800, 600
    #define STRLRESOL "800x600"
    #define XSRESOL 400, 300
    #define STRXSRESOL "400x300"
    #include <SFML/Audio.h>
    #include "scene.h"
    #include "cursor.h"
    #include "param.h"
    #define INVENTORYX 8
    #define INVENTORYY 5
    #define ITEMSIZEX 16
    #define ITEMSIZEY 14
    #define ITEMMARGIN 1
    #define HANDLEX 12.5
    #define ELEMX 150
    #define ELEMY 30
    #define ELEMMARGIN 10
    #define MAXNUMLEN 4
    #define MAXSTRLEN 10
    #define MAPSIZE 200
    #define UNUSED __attribute__((unused))
    #define PATHTOASSETS "bonus/ressources/"

enum program_state {
    Created,
    Started,
    Paused,
    End,
    Quit
};

typedef struct user_s {
    int credit;
    int score;
    int level;
    float walk_speed;
    float reload_speed;
    float life;
    int inventory[INVENTORYX][INVENTORYY][2];
} user_t;

typedef struct program_s {
    prog_param_t params;
    enum program_state pstate;
    sfRenderWindow *window;
    cursor_t *cursor;
    scene_t **scenes;
    int current_scene;
    sfFont *font;
    sfFont *font2;
    sfFont *font3;
    sfMusic *music;
    sfClock *clock;
    float dt;
    float last_time;
} program_t;

typedef scene_t **(*program_maker_t)(program_t *);

program_t *create_program(program_maker_t maker);
void destroy_program(program_t *p);
int start_program(program_t *p);
int start_scene(program_t *p, int i);
int execute_program(program_t *prog);
int loop_events(program_t *p);
void resize_event(program_t *p, sfSizeEvent e);
void auto_resize(program_t *p);
panel_t *paramenuflex(program_t *p);
#endif /* PROGRAM_H */
