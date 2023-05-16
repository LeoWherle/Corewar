/*
** EPITECH PROJECT, 2023
** Corewar asm
** File description:
** header
*/

#include <stdbool.h>
#include <stddef.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
>>>>>>> 2f3b66f ([FIX] resolve confilcts)
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

<<<<<<< HEAD
<<<<<<< HEAD
bool check_instruction(char *line, int got_name, int got_comment)
=======
bool check_instruction(char *line, int *got_name, int *got_comment,
                        header_t *header)
>>>>>>> 79edd03 ([FIX] error handling header parser)
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

=======
>>>>>>> 2f3b66f ([FIX] resolve confilcts)
int header_parser(header_t *header, FILE *fd)
{
    size_t size = 0;
    char *line = NULL;
    int got_name = false;
    int got_comment = false;

    header->magic = COREWAR_EXEC_MAGIC;
<<<<<<< HEAD
    while (getline(&line, &size, fd) != -1) {
        line = clear_line(line);
        if (line[0] != COMMENT_CHAR && line[0] != '.' && line[0] != '\n')
            break;
        if (!check_instruction(line, &got_name, &got_comment, header))
            return 84;
<<<<<<< HEAD
        if (my_strncmp(line, NAME_CMD_STRING, 4) == 0)
            got_name = get_name(header, line);
        if (my_strncmp(line, COMMENT_CMD_STRING, 7) == 0 && got_name)
=======
    header->prog_size = 0;
    while (getline(&line, &size, fd) != -1 && (!got_comment || !got_name)) {
        if (line[0] != '\n' && line[0] != COMMENT_CHAR && line[0] != '.')
            return 84;
        if (strncmp(line, NAME_CMD_STRING, 5) == 0)
            got_name = get_name(header, line);
        if (strncmp(line, COMMENT_CMD_STRING, 8) == 0 &&
            !got_comment && got_name)
>>>>>>> 2f3b66f ([FIX] resolve confilcts)
            got_comment = get_comment(header, line);
=======
>>>>>>> 79edd03 ([FIX] error handling header parser)
    }
    if (!got_name || !got_comment)
        return 84;
    return 0;
}
