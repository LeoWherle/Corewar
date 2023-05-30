/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for program object
*/

#ifndef PARAM_H
    #define PARAM_H

typedef enum param_type_e {
    PARAM_INT,
    PARAM_FLOAT,
    PARAM_STRING
} param_type_t;

typedef struct prog_param_s {
    int width;
    int height;
    int fullscreen;
    float scale;
    char *user;
    float music_volume;
    float sound_volume;
} prog_param_t;

int load_param(
        const char *key, const char *line, param_type_t type, void *trgt);

void load_hyperparams(prog_param_t *params, const char* path);
void save_hyperparams(prog_param_t *params, const char* path);
#endif /* PARAM_H */
