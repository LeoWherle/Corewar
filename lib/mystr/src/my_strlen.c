/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** return the length of a string
*/

int my_strlen(char const *str)
{
    char const *start = str;

    if (!str)
        return (0);
    while (*str)
        str++;
    return (str - start);
}
