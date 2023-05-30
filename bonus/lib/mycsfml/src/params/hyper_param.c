/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "param.h"

static void load_hyperparam(prog_param_t *params, const char *line)
{
    param_type_t types[7] = {PARAM_INT, PARAM_INT, PARAM_INT, PARAM_FLOAT,
        PARAM_FLOAT, PARAM_FLOAT, PARAM_STRING};
    const char *keys[7] = {"WIDTH", "HEIGHT", "FULLSCREEN", "SCALE",
        "MUSIC_VOLUME", "SOUND_VOLUME", "USER"};
    void *trgts[7] = {&params->width, &params->height,
        &params->fullscreen, &params->scale,
        &params->music_volume, &params->sound_volume, &params->user};

    for (int i = 0; i < 7; i++) {
        if (load_param(keys[i], line, types[i], trgts[i])) {
            break;
        }
    }
}

void load_hyperparams(prog_param_t *params, const char* path)
{
    char* line = NULL;
    size_t len = 0;
    FILE* file = NULL;

    file = fopen(path, "r");
    if (file == NULL) {
        printf("File '%s' could not be opened\n", path);
    }
    while (getline(&line, &len, file) != -1) {
        load_hyperparam(params, line);
    }
    fclose(file);
}

void save_hyperparams(prog_param_t *params, const char* path)
{
    FILE* file = NULL;

    file = fopen(path, "w");
    if (file == NULL)
        return;
    fprintf(file, "WIDTH = %d\n", params->width);
    fprintf(file, "HEIGHT = %d\n", params->height);
    fprintf(file, "FULLSCREEN = %d\n", params->fullscreen);
    fprintf(file, "SCALE = %f\n", params->scale);
    fprintf(file, "MUSIC_VOLUME = %f\n", params->music_volume);
    fprintf(file, "SOUND_VOLUME = %f\n", params->sound_volume);
    fprintf(file, "USER = %s\n", params->user);
    fclose(file);
}
