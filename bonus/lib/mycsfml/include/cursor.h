/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for cursor object
*/

#ifndef CURSOR_H
    #define CURSOR_H
    #include <SFML/Graphics.h>

typedef struct cursor_s {
    sfVector2i pos;
    sfSprite *sprite;
    sfTexture *texture;
} cursor_t;

cursor_t *cursor_create(void);
void cursor_draw(sfRenderWindow *w, cursor_t *c);
void cursor_destroy(cursor_t *c);
#endif /* CURSOR_H */
