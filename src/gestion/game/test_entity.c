/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** check_entity
*/

#include "my.h"

int test_entity(sfImage* map, sfVector2f pos, sfColor entity)
{
    sfColor color_x1 = sfImage_getPixel(map, pos.x + 100, pos.y);
    sfColor color_x2 = sfImage_getPixel(map, pos.x, pos.y);
    sfColor color_y1 = sfImage_getPixel(map, pos.x, pos.y + 130);
    sfColor color_y2 = sfImage_getPixel(map, pos.x, pos.y);

    if (color_x2.r == entity.r && color_x2.g == entity.g && color_x2.b == entity.b)
        return 0;
    if (color_x1.r == entity.r && color_x1.g == entity.g && color_x1.b == entity.b)
        return 0;
    if (color_y2.r == entity.r && color_y2.g == entity.g && color_y2.b == entity.b)
        return 0;
    if (color_y1.r == entity.r && color_y1.g == entity.g && color_y1.b == entity.b)
        return 0;
    return 1;
}
