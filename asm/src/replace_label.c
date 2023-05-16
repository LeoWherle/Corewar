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
    int x = 0;

    if (nbr < 0) {
        new[i] = '-';
        i++;
    }
    hold = order;
    for (; order > 0; order--) {
        x = nbr % 10;
        if (x < 0)
            x *= -1;
        new[i + order - 1] = '0' + x;
        nbr /= 10;
    }
    new[i + hold] = '\0';
}

char *replace_label(long int abs_pos, long int goal)
{
    long int relative_pos = 0;
    char *new = NULL;
    int order = 0;
    int hold = 0;
    int i = 1;
    int neg = 0;

    relative_pos = goal - abs_pos;
    hold = relative_pos;
    if (hold <= 0) neg++;
    while (hold != 0) {
        order++;
        hold /= 10;
    }
    new = malloc((order + neg + 2) * sizeof(char));
    ASSERT_MALLOC(new, NULL);
    new[0] = DIRECT_CHAR;
    concat_nbr(relative_pos, order, new, i);
    return new;
}

bool find_label(char **line, label_t *label, long int pos)
{
    for (int i = 1; line[i]; i++) {
        if (line[i][0] == DIRECT_CHAR && line[i][1] == LABEL_CHAR &&
            my_strcmp(&line[i][2], label->name) == 0) {
            line[i] = replace_label(pos, label->ad);
            ASSERT_MALLOC(line[i], false);
        }
    }
    return true;
}

bool search_in_command(list_t *commands, list_t *labels)
{
    command_t *command = NULL;
    long int command_pos = 0;
    label_t *label = NULL;
    bool keep = true;
    int size = 0;

    if (labels->size <= 0) return true;
    for (node_t *node = commands->head; node && keep; node = node->next) {
        command = node->data;
        for (node_t *node = labels->head; node && keep; node = node->next) {
            label = node->data;
            keep = find_label(command->line, label, command_pos);
        }
        for (int i = 0; i < op_tab[(int)command->code_command].nbr_args; i++)
            size += command->param_size[i];
        command_pos += size + 2;
    }
    return keep;
}
