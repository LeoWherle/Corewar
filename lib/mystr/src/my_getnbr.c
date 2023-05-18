/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** transform a number that was in a tring into an int
*/

#include "mystr.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int o = 0;

    for (o = o; str[o] == '-'; o++);
    for (o = o; IS_NUM(str[o]); o++) {
        nb *= 10;
        nb += str[o] - '0';
    }
    if (str[0] == '-')
        nb = nb * (-1);
    return (nb);
}
