/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** nbtostr
*/

#include <stdio.h>
#include <stdlib.h>

void number(int nb, char *str, int *i)
{
    if (nb > 9) {
        number(nb / 10, str, i);
    }
    str[*i] = '0' + nb % 10;
    (*i)++;
}

char *nbtostr(float nb)
{
    int integer = (int)nb;
    int decimal = (int)((nb - integer) * 100);
    int i = 0;
    char *str = malloc(sizeof(char) * (1024));

    if (integer == 0) {
        str[i] = '0';
        i++;
    } else
        number(integer, str, &i);
    str[i] = '.';
    i++;
    number(decimal, str, &i);
    str[i] = '\0';
    return str;
}

char *inttostr(int nb)
{
    int integer = nb;
    int i = 0;
    char *str = malloc(sizeof(char) * (1024));

    if (integer == 0) {
        str[i] = '0';
        i++;
    } else
        number(integer, str, &i);
    str[i] = '\0';
    return str;
}