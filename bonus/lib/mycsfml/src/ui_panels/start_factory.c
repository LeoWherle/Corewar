/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Main function for the demo
*/

#include <stdlib.h>
#include "program.h"
#include "ui_panels/flex.h"
#include "ui_panels/text.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/empty.h"
#include "tools.h"
#include "ui_panels/buttallfoos.h"
#include "theme.h"
#include "ui_panels/start.h"

static panel_t *titleimg(void)
{
    panel_t *title = NULL;
    sfTexture *texture = sfTexture_createFromFile(
        PATHTOASSETS LOGO, NULL);

    if (!texture)
        return NULL;
    title = panel_image_create(
        rtrans_create_flexelem((sfVector2f){1, 1}), texture);
    if (!title)
        return NULL;
    return title;
}

static panel_t *menuflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 9},
        (sfVector2f){ELEMX + ELEMMARGIN, ELEMY + ELEMMARGIN});
    panel_add_childs(fmain, 9,
        titleimg(),
        make_none(), make_none(), make_none(), make_none(), make_none(),
        make_butt("start", p, change_scene, p->font),
        make_butt("options", p, mopen_options, p->font),
        make_butt("quit", p, quit_program, p->font)
    );
    init_rshape(&(fmain->shape), START_MENU_BG);
    return fmain;
}

static panel_t *startmenu(program_t *p)
{
    rectransform_t *mrect = rtrans_create_resize();
    panel_t *pmain = panel_none_create(mrect);

    panel_add_childs(pmain, 2, menuflex(p), paramenuflex(p));
    return pmain;
}

scene_t *start_menu_scene(program_t *p)
{
    panel_t **mpanels = malloc(sizeof(panel_t *) * 2);

    if (!mpanels)
        return NULL;
    mpanels[0] = startmenu(p);
    mpanels[1] = NULL;
    return scene_create(mpanels, NULL, p->params.scale);
}
