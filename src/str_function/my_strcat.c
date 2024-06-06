/*
** EPITECH PROJECT, 2023
** mimi
** File description:
** mimi
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int lien = my_strlen(dest);

    for (; src[i] != '\0'; i++)
        dest[lien + i] = src[i];
    dest[lien + i] = '\0';
    return dest;
}
