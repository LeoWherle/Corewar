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

    for (i = 0; line[i] != '"'; i++);
    i++;
    if (line[i] == '\0')
        return false;
    for (int j = 0; line[i] != '"'; i++, j++)
        header->prog_name[j] = line[i];
    if (line[i] != '"')
        return false;
    return true;
}

static bool get_comment(header_t *header, char *line)
{
    int i = 0;

    for (i = 0; line[i] != '"'; i++);
    i++;
    if (line[i] == '\0')
        return false;
    for (int j = 0; line[i] != '"' && line[i]; i++, j++)
        header->comment[j] = line[i];
    if (line[i] != '"')
        return false;
    return true;
}
bool check_instruction(char *line, int *got_name, int *got_comment,
                        header_t *header)
{
    if (line[0] == '\n' || line[0] == COMMENT_CHAR)
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
    int in = 0;

    new_line = malloc(sizeof(char) * strlen(line) + 1);
    ASSERT_MALLOC(new_line, NULL);
    while (line[in] == ' ' || line[in] == '\t' || line[in] == '\0')
        in++;
    for (int i = 0; line[in] != '\0'; i++, in++)
        new_line[i] = line[in];
    free(line);
    return new_line;
}

int header_parser(header_t *header, FILE *fd)
{
    size_t size = 0;
    char *line = NULL;
    int got_name = false;
    int got_comment = false;

    header->magic = COREWAR_EXEC_MAGIC;
    while (getline(&line, &size, fd) != -1) {
        line = clear_line(line);
        if (line[0] != COMMENT_CHAR && line[0] != '.' && line[0] != '\n')
            break;
        if (!check_instruction(line, &got_name, &got_comment, header))
            return 84;
    }
    if (!got_name || !got_comment)
        return 84;
    return 0;
}
