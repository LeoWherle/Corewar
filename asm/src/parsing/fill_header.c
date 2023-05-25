/*
** EPITECH PROJECT, 2023
** Corewar asm
** File description:
** header
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "clist.h"
#include "mystr.h"
#include "op.h"
#include <string.h>

static bool get_name(header_t *header, char *line)
{
    int i = 0;
    int j = 0;

    for (i = 0; line[i] != '"' && line[i]; i++);
    if (line[i] == '\0')
        return false;
    i++;
    for (j = 0; line[i] && line[i] != '"'; i++, j++)
        header->prog_name[j] = line[i];
    if (j > PROG_NAME_LENGTH)
        return false;
    if (line[i] != '"')
        return false;
    return true;
}

static bool get_comment(header_t *header, char *line)
{
    int i = 0;
    int j = 0;

    for (i = 0; line[i] != '"' && line[i]; i++);
    if (line[i] == '\0')
        return false;
    i++;
    for (j = 0; line[i] != '"' && line[i]; i++, j++)
        header->comment[j] = line[i];
    if (j > COMMENT_LENGTH)
        return false;
    if (line[i] != '"')
        return false;
    return true;
}

bool check_valid_instruction(char *line, int *got_name, int *got_comment,
                        header_t *header)
{
    if (line[0] == '\0' || line[0] == '\n')
        return true;
    if (my_strncmp(line, NAME_CMD_STRING, 4) != 0 && my_strncmp(line,
        COMMENT_CMD_STRING, 7) != 0)
        return false;
    if (my_strncmp(line, NAME_CMD_STRING, 4) == 0) {
        if (*got_name)
            return false;
        *got_name = get_name(header, line);
        if (!*got_name)
            return false;
    }
    if (my_strncmp(line, COMMENT_CMD_STRING, 7) == 0 && *got_name) {
        if (*got_comment)
            return false;
        *got_comment = get_comment(header, line);
        if (!*got_comment)
            return false;
    }
    return true;
}

char *clear_line(char *line)
{
    char *new_line = NULL;
    char **comment_tab = NULL;
    int in = 0;
    int i = 0;

    comment_tab = my_str_to_word_array(line, "#");
    ASSERT_PTR(comment_tab, NULL);
    new_line = malloc(sizeof(char) * my_strlen(comment_tab[0]) + 1);
    ASSERT_MALLOC(new_line, NULL);
    while ((comment_tab[0][in] == ' ' || comment_tab[0][in] == '\t')
        && comment_tab[0][in] != '\0')
        in++;
    for (i = 0; comment_tab[0][in]; i++, in++)
        new_line[i] = comment_tab[0][in];
    new_line[i] = '\0';
    free(line);
    free_matrix(comment_tab);
    return new_line;
}

int header_parser(header_t *header, FILE *fd)
{
    size_t size = 0;
    char *line = NULL;
    int got_name = false;
    int got_comment = false;

    while (getline(&line, &size, fd) != -1 && line[0] != '\0') {
        if (line[0] == COMMENT_CHAR)
            continue;
        line = clear_line(line);
        ASSERT_PTR(line, 84);
        if (line[0] != '.' && line[0] != '\0' && line[0] != '\n')
            break;
        if (!check_valid_instruction(line, &got_name, &got_comment, header))
            return 84;
        free(line);
        line = NULL;
    }
    free(line);
    if (!got_name || !got_comment) return 84;
    return 0;
}
