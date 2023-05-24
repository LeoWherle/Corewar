/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check labels
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "clist.h"
#include "mystr.h"
#include "op.h"
#include "asm.h"

int is_valid_label_char(char label_char)
{
    for (int i = 0; LABEL_CHARS[i]; i++) {
        if (label_char == LABEL_CHARS[i])
            return 1;
    }
    return 0;
}

int is_valid_label(char *label)
{
    if (label[0] == '\0')
        return 0;
    for (int i = 0; label[i] && label[i] != LABEL_CHAR; i++) {
        if (!is_valid_label_char(label[i]))
            return 0;
    }
    return 1;
}

int is_label_matrix(char **args)
{
    for (int i = 0; args[i]; i++) {
        if (args[i][0] == LABEL_CHAR || args[i][1] == LABEL_CHAR)
            return 0;
    }
    return 1;
}

int put_label_in_list(char **args, list_t *label_list, int prog_size)
{
    label_t *lab = NULL;

    if (args[0][my_strlen(args[0]) - 1] == LABEL_CHAR) {
        if (!is_valid_label(args[0]))
            return 84;
        lab = malloc(sizeof(label_t));
        ASSERT_MALLOC(lab, 84);
        lab->name = NULL;
        lab->ad = 0;
        lab->name = malloc(sizeof(char) * my_strlen(args[0]) + 1);
        ASSERT_MALLOC(lab->name, 84);
        lab->name[0] = '\0';
        args[0][my_strlen(args[0]) - 1] = '\0';
        my_strcpy(lab->name, args[0]);
        lab->ad = prog_size;
        node_append(label_list, lab);
        return 1;
    }
    return 0;
}
