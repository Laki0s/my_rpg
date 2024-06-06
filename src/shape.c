/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shape
*/

#include "my.h"

sfRectangleShape *rectancle(sfVector2f size, sfVector2f pos, sfColor color)
{
    sfRectangleShape *square = sfRectangleShape_create();

    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setFillColor(square, color);
    sfRectangleShape_setPosition(square, pos);
    sfRectangleShape_setOutlineThickness(square, 5);
    sfRectangleShape_setOutlineColor(square, sfRed);
    return square;
}