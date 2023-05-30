/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Generic tools
*/

#include <stdlib.h>

int fast_atoi(const char *str)
{
    int val = 0;
    while (*str) {
        val = val * 10 + *str - '0';
        str++;
    }
    return val;
}

char *str(const char *str, int i)
{
    char *new = malloc(sizeof(char) * (i + 1));
    int j = 0;

    while (j < i) {
        new[j] = str[j];
        j++;
    }
    new[j] = '\0';
    return new;
}

void clamp(float *trgt, float min, float max)
{
    if (*trgt < min)
        *trgt = min;
    if (*trgt > max)
        *trgt = max;
}
