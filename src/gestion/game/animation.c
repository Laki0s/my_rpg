/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** animation
*/

#include "my.h"

void rigth_animation(const char *texture_path, float duration,
    sfVector2f scale, sprites_t *animation)
{
    sfVector2u size = {0, 0};

    animation->sprite = sfSprite_create();
    animation->texture = sfTexture_createFromFile(texture_path, NULL);
    size = sfTexture_getSize(animation->texture);
    animation->bounds = (sfIntRect){0, 0, size.y - 30, size.y};
    animation->frame_duration = duration;
    animation->seconds = 0;
    animation->end_frame = size.x;
    animation->frame_size = 310;
    animation->update = &update_animation;
    animation->scale = (sfVector2f){scale.x, scale.y};
    sfSprite_setScale(animation->sprite, animation->scale);
    sfSprite_setTexture(animation->sprite, animation->texture, sfTrue);
}
