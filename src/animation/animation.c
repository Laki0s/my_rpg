/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** animation
*/

#include "my.h"

sfFloatRect rec(sfVector2f max, sfVector2f min, global_t *glob)
{
    sfFloatRect rect = {max.x, max.y, min.x - max.x, min.y - max.y};
    (void)glob;
    return rect;
}

void draw_text(global_t *glob, char *str, int scale, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, glob->font);
    sfText_setCharacterSize(text, scale);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(WINDOW, text, NULL);
    sfText_destroy(text);
}

void create_animation(const char *texture_path, float duration,
    sfVector2f scale, sprites_t *animation)
{
    sfVector2u size = {0, 0};

    animation->sprite = sfSprite_create();
    animation->texture = sfTexture_createFromFile(texture_path, NULL);
    size = sfTexture_getSize(animation->texture);
    animation->bounds = (sfIntRect){0, 0, size.y - 18, size.y};
    animation->frame_duration = duration;
    animation->seconds = 0;
    animation->end_frame = size.x;
    animation->frame_size = 80;
    animation->update = &update_animation;
    animation->scale = (sfVector2f){scale.x, scale.y};
    sfSprite_setScale(animation->sprite, animation->scale);
    sfSprite_setTexture(animation->sprite, animation->texture, sfTrue);
}

void update_animation(sprites_t *animation, float delta_time)
{
    animation->seconds += delta_time;
    while (animation->seconds >= animation->frame_duration) {
        animation->bounds.left += animation->frame_size;
        if (animation->bounds.left >= animation->end_frame)
            animation->bounds.left = 0;
        animation->seconds -= delta_time;
        if (animation->seconds < animation->frame_duration)
            animation->seconds = 0;
    }
    sfSprite_setTextureRect(animation->sprite, animation->bounds);
}

void sprite_position(sfVector2f pos, sprites_t *animation)
{
    animation->pos = (sfVector2f){pos.x, pos.y};
    sfSprite_setPosition(animation->sprite, animation->pos);
}
