/*
** EPITECH PROJECT, 2023
** corewar [WSL: fedora]
** File description:
** vm_init
*/

#include <stdlib.h>
#include "vm.h"
#include "serrorh.h"
#include "herror.h"

static void champion_init(champion_t *champion)
{
    champion->id = 0;
    champion->alive = false;
    champion->file_path = NULL;
    champion->has_adress = 0;
    champion->laddress_value = 0;
    champion->dead = false;
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

int count_champion_alive(vm_t *vm)
{
    int count = 0;
    node_t *node = NULL;
    champion_t *champion = NULL;

    node = vm->champions->head;
    while (node != NULL) {
        champion = node->data;
        if (champion->alive)
            count++;
        node = node->next;
    }
    return count;
}

champion_t *get_champion_alive(list_t *champions)
{
    node_t *node = NULL;
    champion_t *champion = NULL;

    node = champions->head;
    while (node != NULL) {
        champion = node->data;
        if (champion->alive)
            return champion;
        node = node->next;
    }
    return NULL;
}

void champion_destroy(void *champ)
{
    champion_t *champion = champ;

    free(champion->file_path);
    free(champion);
}
