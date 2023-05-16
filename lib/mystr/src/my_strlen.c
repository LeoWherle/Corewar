/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** return the length of a string
*/

int my_strlen(char const *str)
{
    int index = 0;

    if (!str)
        return (0);
    while (str[index] != '\0')
        index++;
    return (index);
}
