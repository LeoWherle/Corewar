/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** replace the label by relative address
*/

#include <stddef.h>
#include <stdlib.h>
#include "asm.h"
#include "clist.h"
#include "mystr.h"
#include "op.h"

void concat_nbr(long int nbr, int order, char *new, int i)
{
    int hold = 0;

    if (nbr < 0) {
        new[i] = '-';
        i++;
    }
    hold = order;
    for (; order >= 0; order--) {
        new[i + order] = nbr % 10;
        nbr /= 10;
    }
    new[i + hold] = '\0';
}

char *replace_label(char *line, long int abs_pos, long int goal)
{
    long int relative_pos = 0;
    char *new = NULL;
    int order = 1;
    int hold = 0;
    int i = 1;

    relative_pos = goal - abs_pos;
    hold = relative_pos;
    if (hold <= 0) order++;
    while (hold != 0) {
        order++;
        hold /= 10;
    }
    new = malloc(order * sizeof(char));
    ASSERT_MALLOC(new, NULL);
    new[0] = '%';
    concat_nbr(relative_pos, order, new, i);
    return new;
}

bool find_label(char **line, label_t *label, long int pos)
{
    long int abs_pos = 0;

    abs_pos = pos + 2;
    for (int i = 1; line[i]; i++) {
        if (my_strncmp(line[i], "%:", 2) == 0 &&
            my_strcmp(&line[i][2], label->name) == 0) {
            line[i] = replace_label(line[i], abs_pos, label->ad);
            ASSERT_MALLOC(line[i], false);
        }
        if (line[i][0] == 'r')
            abs_pos += REG_SIZE;
        if (line[i][0] == DIRECT_CHAR)
            abs_pos += DIR_SIZE;
        if (line[i][0] >= '0' && line[i][0] <= '9')
            abs_pos += IND_SIZE;
    }
    return true;
}

bool search_in_command(list_t *commands, list_t *labels)
{
    command_t *command = NULL;
    long int command_pos = 0;
    label_t *label = NULL;
    bool keep = true;

    if (labels->size <= 0) return;
    for (node_t *node = commands->head; node && keep; node = node->next) {
        command = node->data;
        for (node_t *node = labels->head; node && keep; node = node->next) {
            label = node->data;
            keep = find_label(command->line, label, command_pos);
        }
        command_pos += command->param_size + 2;
    }
    return keep;
}
