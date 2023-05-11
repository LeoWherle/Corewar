/*
** EPITECH PROJECT, 2023
** Corewar asm
** File description:
** header
*/

#include <stdbool.h>
#include <stddef.h>
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

int header_parser(header_t *header, FILE *fd)
{
    size_t size = 0;
    char *line = NULL;
    int got_name = false;
    int got_comment = false;

    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    while (getline(&line, &size, fd) != -1 && (!got_comment || !got_name)) {
        if (line[0] != '\n' && line[0] != COMMENT_CHAR && line[0] != '.')
            return 84;
        if (strncmp(line, NAME_CMD_STRING, 5) == 0)
            got_name = get_name(header, line);
        if (strncmp(line, COMMENT_CMD_STRING, 8) == 0 &&
            !got_comment && got_name)
            got_comment = get_comment(header, line);
    }
    if (!got_name || !got_comment)
        return 84;
    return 0;
}
