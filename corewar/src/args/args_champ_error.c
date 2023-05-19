/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check champ errors in args
*/

#include <unistd.h>
#include <fcntl.h>
#include "args.h"
#include "mystr.h"

/**
 * @brief check champion nb and integrity
 *
 * @param champions list of champions
 * @param nb_champions number of champions
 * @return int 0 on success, 84 on failure
 */
int check_all_champ(champ_arg_t *champions, int nb_champions)
{
    int index = 0;

    if (nb_champions < 2) {
        write(2, "Error: 2 champions minimum are required.\n", 41);
        return (84);
    }
    for (;champions[index].name != NULL; index++);
    if (champions[index].load_address || champions[index].prog_number) {
        write(2, "Error: missing champion name.\n", 30);
        return (84);
    }
    return (0);
}

/**
 * @brief check the champion name by trying to open it
 *
 * @param champion current champion
 * @param arg potential name of the champion
 * @return int 0 on success, 84 on failure
 */
int check_champ_name(champ_arg_t *champion, const char *arg)
{
    int fd = 0;

    fd = open(arg, O_RDONLY);
    if (fd == -1) {
        write(2, "Error: can't open file : '", 26);
        write(2, arg, my_strlen(arg));
        write(2, "'\n", 2);
        return (84);
    }
    close(fd);
    champion->name = arg;
    return (0);
}
