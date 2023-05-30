/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#include "program.h"
#include "ui_panels/draggable.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "ui_panels/empty.h"
#include "tools.h"
#include "theme.h"
#include "ui_panels/button.h"
#include "ui_panels/options.h"
#include "ui_panels/dropdown.h"
#include "ui_panels/slider.h"
#include "ui_panels/buttallfoos.h"

void decrease_scale(void *trgt)
{
    program_t *prog = trgt;
    canvas_t *canvas = prog->scenes[prog->current_scene]->canvas;

    if (canvas->scale > 0.5)
        canvas->scale /= 1.5;
    auto_resize(prog);
    auto_resize(prog);
}

void increase_scale(void *trgt)
{
    program_t *prog = trgt;
    canvas_t *canvas = prog->scenes[prog->current_scene]->canvas;

    if (canvas->scale < 2)
        canvas->scale *= 1.5;
    auto_resize(prog);
    auto_resize(prog);
}

panel_t *make_scale_control(sfFont *font, void *trgt)
{
    panel_t *epanel = make_flex((sfVector2i){3, 1},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN) / 3, ELEMY + ELEMMARGIN});
    panel_add_childs(epanel, 3, make_butt("-", trgt, decrease_scale, font),
        make_label(font, "ui scale", 20),
        make_butt("+", trgt, increase_scale, font));
    epanel->childs[0]->rect->size.x = ELEMY;
    epanel->childs[1]->rect->size.x = 2 * ELEMX / 3;
    epanel->childs[2]->rect->size.x = ELEMY;
    epanel->rect->xanchor = ANCHOR_START;
    epanel->rect->yanchor = ANCHOR_START;
    return epanel;
}
