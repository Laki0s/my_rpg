/*
** EPITECH PROJECT, 2023
** epnf
** File description:
** frn
*/

#include "my.h"

static int alpha(char c)
{
    if (c == '=')
        return 0;
    else
        return 1;
}

int size(char const *str)
{
    int i = 0;
    int size = 1;

    while (str[i] != '\0') {
        if ((alpha(str[i]) == 1) && (alpha(str[i + 1]) == 0))
            size += 1;
        i++;
    }
    return size;
}

static int my_strlen_modify(char const *str, int k)
{
    int i = 0;

    while (str[k] != '\0' && (alpha(str[k]) == 1)) {
        k++;
        i++;
    }
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int size_c = 0;
    char **tab = malloc(sizeof(char *) * (size(str) + 1));

    for (int k = 0; str[k] != '\0' && size_c < (size(str) + 1); k++) {
        if (alpha(str[k]) == 0)
            k++;
        tab[size_c] = malloc(sizeof(char) * (my_strlen_modify(str, k) + 1));
        for (; alpha(str[k]) == 1 && str[k] != '\0' && str[k] != '\n'; j++) {
            tab[size_c][j] = str[k];
            k++;
        }
        tab[size_c][j] = '\0';
        if (j > 0) {
            j = 0;
            size_c = size_c + 1;
        }
    }
    tab[size_c] = NULL;
    return tab;
}
