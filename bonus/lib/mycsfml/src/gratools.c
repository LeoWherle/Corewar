/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** General foos for button panels
*/

#include <SFML/Graphics.h>
#include "rectransform.h"
#include "program.h"
#include "theme.h"

void init_text(sfText **text, sfFont *font, const char *str, unsigned int size)
{
    sfFloatRect trect;

    if (!text || !font || !str)
        return;
    *text = sfText_create();
    if (!*text)
        return;
    sfText_setFont(*text, font);
    sfText_setColor(*text, TEXT_COLOR);
    sfText_setString(*text, str);
    sfText_setCharacterSize(*text, size);
    trect = sfText_getLocalBounds(*text);
    sfText_setOrigin(*text, (sfVector2f){
        trect.left + trect.width / 2.0f, trect.top + trect.height / 2.0f});
}

void init_rshape(sfRectangleShape **shape, sfColor color)
{
    if (!shape)
        return;
    *shape = sfRectangleShape_create();
    if (!*shape)
        return;
    sfRectangleShape_setFillColor(*shape, color);
}

void init_sprite(sfSprite **sprite, sfTexture *texture, rectransform_t *r)
{
    if (!sprite || !texture || !r)
        return;
    *sprite = sfSprite_create();
    if (!*sprite)
        return;
    sfSprite_setTexture(*sprite, texture, sfTrue);
    sfSprite_setOrigin(*sprite,
        (sfVector2f){r->size.x / 2, r->size.y / 2});
}
