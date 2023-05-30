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

static void load_int_param(const char *line, void *trgt)
{
    int *itrgt = NULL;

    if (!line || !trgt)
        return;
    itrgt = (int *)trgt;
    *itrgt = atoi(line);
}

static void load_float_param(const char *line, void *trgt)
{
    float *ftrgt = NULL;

    if (!line || !trgt)
        return;
    ftrgt = (float *)trgt;
    *ftrgt = atof(line);
}

static void load_string_param(const char *line, void *trgt)
{
    char **strtrgt = NULL;

    if (!line || !trgt)
        return;
    strtrgt = (char **)trgt;
    *strtrgt = strdup(line);
}

int load_param(
        const char *key, const char *line, param_type_t type, void *trgt)
{
    char *vline = NULL;

    if (strstr(line, key) == NULL) {
        return 0;
    }
    vline = strstr(line, "=") + 2;
    if (vline == NULL) {
        return 0;
    }
    switch (type) {
        case PARAM_INT: load_int_param(vline, trgt); break;
        case PARAM_FLOAT: load_float_param(vline, trgt); break;
        case PARAM_STRING: load_string_param(vline, trgt); break;
        default: return 0;
    }
    return 1;
}
