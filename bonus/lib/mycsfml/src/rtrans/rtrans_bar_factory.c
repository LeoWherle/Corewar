/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for rectransform
*/

#include <stdlib.h>
#include "rectransform.h"

rectransform_t *rtrans_create_barup(sfVector2f pos, sfVector2f size)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = pos;
    rect->size = size;
    rect->xanchor = ANCHOR_MIDDLE;
    rect->yanchor = ANCHOR_START;
    rect->resize = RESIZE_X;
    return rect;
}

rectransform_t *rtrans_create_bardown(sfVector2f pos, sfVector2f size)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = pos;
    rect->size = size;
    rect->xanchor = ANCHOR_MIDDLE;
    rect->yanchor = ANCHOR_END;
    rect->resize = RESIZE_X;
    return rect;
}

rectransform_t *rtrans_create_barleft(sfVector2f pos, sfVector2f size)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = pos;
    rect->size = size;
    rect->xanchor = ANCHOR_START;
    rect->yanchor = ANCHOR_MIDDLE;
    rect->resize = RESIZE_Y;
    return rect;
}

rectransform_t *rtrans_create_barright(sfVector2f pos, sfVector2f size)
{
    rectransform_t *rect = malloc(sizeof(rectransform_t));

    if (!rect)
        return NULL;
    rect->pos = pos;
    rect->size = size;
    rect->xanchor = ANCHOR_END;
    rect->yanchor = ANCHOR_MIDDLE;
    rect->resize = RESIZE_Y;
    return rect;
}
