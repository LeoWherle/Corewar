/*
** EPITECH PROJECT, 2023
** corwar
** File description:
** print the compiled code
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "clist.h"
#include "op.h"
#include "mystr.h"

static char *get_cor(char *name)
{
    char *new_name = NULL;
    int i = 0;

    new_name = malloc((my_strlen(name) + 3) * sizeof(char));
    ASSERT_MALLOC(new_name, NULL);
    new_name[0] = '\0';
    for (i = 0; my_strncmp(&name[i], ".s", 1); i++)
        new_name[i] = name[i];
    new_name[i] = '\0';
    my_strcat(new_name, ".cor");
    return new_name;
}

static void print_command(int fd, command_t *com)
{
    int size = 0;

    write(fd, &com->code_command, 1);
    if (op_tab[com->code_command - 1].nbr_args != 1 ||
        com->code_command - 1 == 15)
        write(fd, &com->coding_byte, 1);
    size = 0;
    for (int i = 0; i < op_tab[com->code_command - 1].nbr_args; i++)
        size += com->param_size[i];
    write(fd, com->parameters, size);
}

bool print_comp(list_t *command, header_t *head, char *name)
{
    command_t *com = NULL;
    int fd = 0;
    char *new_name = NULL;

    new_name = get_cor(name);
    ASSERT_MALLOC(new_name, false);
    fd = open(new_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
        return false;
    head->prog_size = SWAP_INT32(head->prog_size);
    head->magic = SWAP_INT32(head->magic);
    write(fd, head, sizeof(header_t));
    for (node_t *node = command->head; node; node = node->next) {
        com = node->data;
        print_command(fd, com);
    }
    close(fd);
    free(new_name);
    return true;
}
