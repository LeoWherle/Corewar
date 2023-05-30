/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Header for content object
*/

#ifndef CONTENT_H
    #define CONTENT_H
    #include "canvas.h"

typedef enum content_state_e {
    CONTENT_STATE_PLAY,
    CONTENT_STATE_PAUSE,
    CONTENT_STATE_STOP
} content_state_t;

typedef void (*content_destroyer_t)(void *);
typedef void (*content_drawer_t)(sfRenderWindow *, void *);
typedef void (*content_looper_t)(void *, float);
typedef void (*content_eventer_t)(void *, sfEvent);
typedef void (*content_on_enter_t)(void *);
typedef void (*content_on_leave_t)(void *);
typedef void (*content_on_press_t)(void *, sfMouseButtonEvent);
typedef void (*content_on_release_t)(void *, sfMouseButtonEvent);
typedef void (*content_on_select_t)(void *);
typedef void (*content_on_deselect_t)(void *);
typedef void (*content_on_hover_t)(void *, sfVector2i *);
typedef void (*content_on_key_press_t)(void *, sfKeyEvent);
typedef void (*content_on_key_release_t)(void *, sfKeyEvent);
typedef void (*content_on_start_t)(void *);
typedef void (*content_on_pause_t)(void *);
typedef void (*content_on_resume_t)(void *);
typedef void (*content_on_stop_t)(void *);
typedef void (*content_on_save_t)(void *, const char *);
typedef void (*content_on_load_t)(void *, const char *);

typedef struct content_s content_t;
typedef content_t *(*content_maker_t)(void);

struct content_s {
    void *content;
    content_state_t state;
    content_maker_t maker;
    content_destroyer_t destroyer;
    content_drawer_t drawer;
    content_looper_t looper;
    content_eventer_t eventer;
    content_on_enter_t on_enter;
    content_on_leave_t on_leave;
    content_on_press_t on_press;
    content_on_release_t on_release;
    content_on_select_t on_select;
    content_on_deselect_t on_deselect;
    content_on_hover_t on_hover;
    content_on_key_press_t on_key_press;
    content_on_key_release_t on_key_release;
    content_on_start_t on_start;
    content_on_pause_t on_pause;
    content_on_resume_t on_resume;
    content_on_stop_t on_stop;
    content_on_save_t saver;
    content_on_load_t loader;
};

#endif /* CONTENT_H */
