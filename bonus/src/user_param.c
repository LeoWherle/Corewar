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
#include "program.h"

static int load_userparam(user_t *params, const char *line)
{
    param_type_t types[6] = {PARAM_INT, PARAM_INT, PARAM_INT,
        PARAM_FLOAT, PARAM_FLOAT, PARAM_FLOAT};
    const char *keys[6] = {"CREDIT", "SCORE", "LEVEL",
        "WALK_SPEED", "RELOAD_SPEED", "LIFE"};
    void *trgts[6] = {&params->credit, &params->score, &params->level,
        &params->walk_speed, &params->reload_speed, &params->life};

    for (int i = 0; i < 6; i++) {
        if (load_param(keys[i], line, types[i], trgts[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

void load_userparams(user_t *params, const char* path)
{
    char* line = NULL;
    size_t len = 0;
    FILE* file = NULL;

    file = fopen(path, "r");
    if (file == NULL)
        return;
    while (getline(&line, &len, file) != -1) {
        if (load_userparam(params, line) == 0)
            break;
    }
    while (getline(&line, &len, file) != -1) {
        if (strstr(line, "INVENTORY") != NULL) {
            params->inventory[atoi(strstr(line, "[") + 1)]
            [atoi(strstr(line, ",") + 2)]
            [atoi(strstr(line, "]") + 1)] = atoi(strstr(line, "=") + 2);
        }
    }
    fclose(file);
}

void save_userparams(user_t *params, const char* path)
{
    FILE* file = NULL;

    file = fopen(path, "w");
    if (file == NULL)
        return;
    fprintf(file, "CREDIT = %d\n", params->credit);
    fprintf(file, "SCORE = %d\n", params->score);
    fprintf(file, "LEVEL = %d\n", params->level);
    fprintf(file, "WALK_SPEED = %f\n", params->walk_speed);
    fprintf(file, "RELOAD_SPEED = %f\n", params->reload_speed);
    fprintf(file, "LIFE = %f\n\n", params->life);
}
