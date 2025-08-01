/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for cursor
*/

#include <stdlib.h>
#include "cursor.h"
#include "program.h"
#include "theme.h"

cursor_t *cursor_create(void)
{
    cursor_t *c = malloc(sizeof(cursor_t));

    if (!c)
        return NULL;
    c->pos = (sfVector2i){0, 0};
    c->texture = sfTexture_createFromFile(PATHTOASSETS CURSOR, NULL);
    c->sprite = sfSprite_create();
    sfSprite_setTexture(c->sprite, c->texture, sfTrue);
    sfSprite_setOrigin(c->sprite, (sfVector2f){8, 8});
    return c;
}

void cursor_draw(sfRenderWindow *w, cursor_t *c)
{
    sfSprite_setPosition(c->sprite, (sfVector2f){c->pos.x, c->pos.y});
    sfRenderWindow_drawSprite(w, c->sprite, NULL);
}

void cursor_destroy(cursor_t *c)
{
    sfSprite_destroy(c->sprite);
    sfTexture_destroy(c->texture);
    free(c);
}
