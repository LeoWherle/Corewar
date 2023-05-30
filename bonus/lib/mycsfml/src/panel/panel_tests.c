/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Testing foo for panels
*/

#include <stdlib.h>
#include "panel.h"

int is_interactable(ptype_t t)
{
    if (t == PTYPE_DDBUTT ||
        t == PTYPE_EVBUTT ||
        t == PANEL_TYPE_INPUT)
        return 1;
    return 0;
}
