/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** dsiplay champions names in vs screen
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "program.h"
#include "intro.h"
#include "vm.h"

void two_champ_pos(intro_t *intro)
{
    sfVector2f pos[2] = {
        {230, 500},
        {1720, 500},
    };

    for (int i = 0; i < 2; i++) {
        sfText_setPosition(intro->champions[i], pos[i]);
    }
}

void three_champ_pos(intro_t *intro)
{
    sfVector2f pos[3] = {
        {230, 500},
        {1500, 130},
        {1500, 920},
    };

    for (int i = 0; i < 3; i++) {
        sfText_setPosition(intro->champions[i], pos[i]);
    }
}

void four_champ_pos(intro_t *intro)
{
    sfVector2f pos[4] = {
        {370, 100},
        {370, 920},
        {1500, 100},
        {1500, 920},
    };

    for (int i = 0; i < 4; i++) {
        sfText_setPosition(intro->champions[i], pos[i]);
    }
}

static const champ_count_t CHAMP_POS[] = {
    {2, two_champ_pos},
    {3, three_champ_pos},
    {4, four_champ_pos},
};

char *format_string(char *str)
{
    char *new = malloc(sizeof(char) * (strlen(str) + 10));
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '_') {
            new[i] = '\n';
        }
        else
            new[i] = str[i];
    }
    new[i] = '\0';
    return (new);
}

void set_text(intro_t *intro, vm_t *vm)
{
    node_t *tmp = vm->champions->head;
    champion_t *champ = tmp->data;
    sfFloatRect rect;

    intro->font = sfFont_createFromFile("bonus/ressources/Apache.ttf");
    for (int i = 0; i < vm->champions->size; i++) {
        champ = tmp->data;
        intro->champions[i] = sfText_create();
        sfText_setFont(intro->champions[i], intro->font);
        sfText_setString(intro->champions[i], format_string(champ->header.prog_name));
        if (strlen(champ->header.prog_name) > 13)
            sfText_setCharacterSize(intro->champions[i], 70);
        else if (strlen(champ->header.prog_name) > 10)
            sfText_setCharacterSize(intro->champions[i], 100);
        else
            sfText_setCharacterSize(intro->champions[i], 120);
        rect = sfText_getLocalBounds(intro->champions[i]);
        sfText_setOrigin(intro->champions[i], (sfVector2f){rect.width / 2, 
        rect.height / 2});
        sfText_setColor(intro->champions[i], sfWhite);
        tmp = tmp->next;
    }
    for (int i = 0; i < 3; i++) {
        if (vm->champions->size == CHAMP_POS[i].size)
            CHAMP_POS[i].func(intro);
    }
}