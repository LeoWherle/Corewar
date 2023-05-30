/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "program.h"

static char *path_from_user(const char *str)
{
    const char *prefix = PATHTOASSETS "users/";
    const char *suffix = ".save";
    unsigned int len = strlen(prefix) + strlen(str) + strlen(suffix) + 1;
    char *path = malloc(sizeof(char) * len);
    int i = 0;
    int j = 0;

    if (path == NULL)
        return NULL;
    for (; prefix[i] != '\0'; i++)
        path[i] = prefix[i];
    for (j = 0; str[j] != '\n'; j++, i++)
        path[i] = str[j];
    for (j = 0; suffix[j] != '\0'; j++, i++)
        path[i] = suffix[j];
    path[i] = '\0';
    return path;
}

void save_content(void *data)
{
    program_t *p = (program_t *) data;
    content_t *content = p->scenes[p->current_scene]->content;
    char *path = path_from_user(p->params.user);

    if (path == NULL)
        return;
    content->saver(content->content, path);
    free(path);
}

void load_content(void *data)
{
    program_t *p = (program_t *) data;
    content_t *content = p->scenes[p->current_scene]->content;
    char *path = path_from_user(p->params.user);

    if (path == NULL)
        return;
    content->loader(content->content, path);
    free(path);
}
