/*
** EPITECH PROJECT, 2022
** str
** File description:
** to word array
*/

#include <stdlib.h>
#include <stdio.h>

int is_sep(char check, char *sep)
{
    for (int i = 0; sep[i] != '\0'; i++)
        if (check == sep[i])
            return 1;
    return 0;
}

int str_len(char *str, char *sep, int index)
{
    int len = 0;
    int in = index;

    while (is_sep(str[in], sep) == 0 && str[in]) {
        in++;
        len++;
    }
    return len;
}

int nb_words(char *str, char *sep)
{
    int len = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (is_sep(str[i], sep) == 1 && str[i] != '\0')
            i++;
        if (is_sep(str[i], sep) == 0 && str[i] != '\0')
            len++;
        while (is_sep(str[i], sep) == 0 && str[i] != '\0')
            i++;
    }
    return len;
}

int array_loop(char **array, int len, char *str, char *sep)
{
    int i = 0;
    int j = 0;
    int in = 0;

    while (is_sep(str[in], sep) == 1)
        in++;
    for (i = 0; i < len; i++) {
        array[i] = malloc(sizeof(char) * str_len(str, sep, in) + 1);
        if (array[i] == NULL)
            return 0;
        for (j = 0; is_sep(str[in], sep) == 0 && str[in]; j++) {
            array[i][j] = str[in];
            in++;
        }
        array[i][j] = '\0';
        while (is_sep(str[in], sep) == 1)
            in++;
    }
    array[i] = NULL;
    return 1;
}

char **my_str_to_word_array(char *str, char *sep)
{
    int len = 0;
    char** final = NULL;

    len = nb_words(str, sep);
    final = malloc(sizeof(char *) * (len + 1));
    if (final == NULL)
        return NULL;
    if (!array_loop(final, len, str, sep))
        return NULL;
    return final;
}
