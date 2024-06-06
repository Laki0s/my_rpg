/*
** EPITECH PROJECT, 2023
** mimi
** File description:
** mimi
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
