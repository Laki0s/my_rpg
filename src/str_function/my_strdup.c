/*
** EPITECH PROJECT, 2023
** rgnuoz
** File description:
** rgnuoz
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src)));

    my_strcpy(dest, src);
    return dest;
}
