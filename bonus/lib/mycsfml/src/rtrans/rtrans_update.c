/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for rectransform
*/

#include <stdlib.h>
#include "rectransform.h"

sfVector2f rtrans_pos_update(
    rectransform_t *rect, sfVector2f *parentpos, sfVector2f *parentsize)
{
    sfVector2f pos = (sfVector2f){0, 0};

    if (!rect || !parentpos || !parentsize)
        return pos;
    pos = rect->pos;
    if (rect->xanchor == ANCHOR_START)
        pos.x += parentpos->x;
    if (rect->xanchor == ANCHOR_MIDDLE)
        pos.x += parentpos->x + parentsize->x / 2;
    if (rect->xanchor == ANCHOR_END)
        pos.x += parentpos->x + parentsize->x;
    if (rect->yanchor == ANCHOR_START)
        pos.y += parentpos->y;
    if (rect->yanchor == ANCHOR_MIDDLE)
        pos.y += parentpos->y + parentsize->y / 2;
    if (rect->yanchor == ANCHOR_END)
        pos.y += parentpos->y + parentsize->y;
    return pos;
}

sfVector2f rtrans_size_update(
    rectransform_t *rect, sfVector2f *psize, float scale)
{
    sfVector2f size;

    if (!rect || !psize)
        return (sfVector2f){0, 0};
    size = (sfVector2f){rect->size.x * scale, rect->size.y * scale};
    if (rect->resize == RESIZE_X || rect->resize == RESIZE_XY)
        size.x = psize->x - rect->size.x * scale;
    if (rect->resize == RESIZE_Y || rect->resize == RESIZE_XY)
        size.y = psize->y - rect->size.y * scale;
    return size;
}
