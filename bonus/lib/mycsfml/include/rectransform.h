/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for the rectangle transform
*/

#ifndef RECTRANSFORM_H
    #define RECTRANSFORM_H
    #include <SFML/Graphics.h>

typedef enum anchor_type {
    ANCHOR_NONE,
    ANCHOR_START,
    ANCHOR_MIDDLE,
    ANCHOR_END
} anchor_type_t;

typedef enum resize_type {
    RESIZE_NONE,
    RESIZE_X,
    RESIZE_Y,
    RESIZE_XY
} resize_type_t;

typedef struct rectransform_s {
    sfVector2f pos;
    sfVector2f size;
    anchor_type_t xanchor;
    anchor_type_t yanchor;
    resize_type_t resize;
} rectransform_t;

rectransform_t *rtrans_create_free(sfVector2f pos, sfVector2f size);
rectransform_t *rtrans_create_centered(sfVector2f pos, sfVector2f size);
rectransform_t *rtrans_create_flexelem(sfVector2f size);
rectransform_t *rtrans_create_resize(void);
rectransform_t *rtrans_create_barup(sfVector2f pos, sfVector2f size);
rectransform_t *rtrans_create_bardown(sfVector2f pos, sfVector2f size);
rectransform_t *rtrans_create_barleft(sfVector2f pos, sfVector2f size);
rectransform_t *rtrans_create_barright(sfVector2f pos, sfVector2f size);
void rectransform_destroy(rectransform_t *);

sfVector2f rtrans_pos_update(rectransform_t *, sfVector2f *, sfVector2f *);
sfVector2f rtrans_size_update(rectransform_t *, sfVector2f *, float);

#endif /* RECTRANSFORM_H */
