/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for rectransform
*/

#include <stdlib.h>
#include "rectransform.h"

rectransform_t *rtrans_create_free(sfVector2f pos, sfVector2f size)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = pos;
    rect->size = size;
    rect->xanchor = ANCHOR_NONE;
    rect->yanchor = ANCHOR_NONE;
    rect->resize = RESIZE_NONE;
    return rect;
}

rectransform_t *rtrans_create_centered(sfVector2f pos, sfVector2f size)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = pos;
    rect->size = size;
    rect->xanchor = ANCHOR_MIDDLE;
    rect->yanchor = ANCHOR_MIDDLE;
    rect->resize = RESIZE_NONE;
    return rect;
}

rectransform_t *rtrans_create_flexelem(sfVector2f size)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = (sfVector2f){0, 0};
    rect->size = size;
    rect->xanchor = ANCHOR_START;
    rect->yanchor = ANCHOR_START;
    rect->resize = RESIZE_NONE;
    return rect;
}

rectransform_t *rtrans_create_resize(void)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = (sfVector2f){0, 0};
    rect->size = (sfVector2f){0, 0};
    rect->xanchor = ANCHOR_MIDDLE;
    rect->yanchor = ANCHOR_MIDDLE;
    rect->resize = RESIZE_XY;
    return rect;
}

void rectransform_destroy(rectransform_t *rect)
{
    if (rect)
        free(rect);
}
