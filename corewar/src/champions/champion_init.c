/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** vm_init
*/

#include <stdlib.h>
#include "vm.h"
#include "herror.h"

static void champion_init(champion_t *vm)
{
    return;
}

/**
 * @return NULL on failure else initialized champion
 */
WUR champion_t *champion_create(void)
{
    champion_t *champion = NULL;

    champion = malloc(sizeof(champion_t));
    ASSERT_MALLOC(champion, NULL);
    champion_init(champion);
    return champion;
}

void champion_destroy(void *champ)
{
    champion_t *champion = champ;

    free(champion);
}
