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

panel_t *resolution_dd(sfFont *font, program_t *prog)
{
    panel_t *panel = make_dd(4,
        (sfVector2f){ELEMX + ELEMMARGIN, ELEMY + ELEMMARGIN});
    panel_add_childs(panel, 4,
        make_butt(STRHRESOL, prog, set_high_resol, font),
        make_butt(STRMRESOL, prog, set_medium_resol, font),
        make_butt(STRLRESOL, prog, set_low_resol, font),
        make_butt(STRXSRESOL, prog, set_mini_resol, font));
    return panel;
}

static panel_t *resol_dd_butt(sfFont *font, program_t *prog)
{
    panel_t *panel = make_ddbutt(font, "pick");
    panel_add_childs(panel, 1, resolution_dd(font, prog));
    return panel;
}

panel_t *paramenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 8},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN), ELEMY + ELEMMARGIN});
    panel_add_childs(fmain, 8,
        make_label(p->font, "video", 20),
        make_label_pair(p->font, "fullscreen",
            make_butt("toggle", p, toggle_fullscreen, p->font), 20),
        make_label_pair(p->font, "resolution", resol_dd_butt(p->font, p), 20),
        make_scale_control(p->font, p),
        make_none(),
        make_label(p->font, "audio", 20),
        make_label_pair(p->font, "music", make_slider(p, update_music_volume,
            p->params.music_volume, p->params.scale), 20),
        make_label_pair(p->font, "sound", make_slider(p, update_sound_volume,
            p->params.sound_volume, p->params.scale), 20));
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}

panel_t *escmenuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 3},
        (sfVector2f){ELEMX + ELEMMARGIN, ELEMY + ELEMMARGIN});
    panel_add_childs(fmain, 3,
        make_butt("continue", p, continue_program, p->font),
        make_butt("options", p, open_options, p->font),
        make_butt("main menu", p, quit_game, p->font)
    );
    init_rshape(&(fmain->shape), MENU);
    fmain->state = PANEL_STATE_INACTIVE;
    return fmain;
}
