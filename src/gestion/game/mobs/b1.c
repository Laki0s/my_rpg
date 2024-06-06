/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-quentin.gehin
** File description:
** poop_mob
*/

#include "my.h"

static void animation_mob(const char *texture_path, float duration,
    sfVector2f scale, sprites_t *animation)
{
    sfVector2u size = {0, 0};

    animation->sprite = sfSprite_create();
    animation->texture = sfTexture_createFromFile(texture_path, NULL);
    size = sfTexture_getSize(animation->texture);
    animation->bounds = (sfIntRect){0, 0, size.y, size.y};
    animation->frame_duration = duration;
    animation->seconds = 0;
    animation->end_frame = size.x;
    animation->frame_size = size.y * 2 + 40;
    animation->update = &update_animation;
    animation->scale = (sfVector2f){scale.x, scale.y};
    sfSprite_setScale(animation->sprite, animation->scale);
    sfSprite_setTexture(animation->sprite, animation->texture, sfTrue);
}

mob_t *new_b1mob(sfVector2f pos)
{
    mob_t* new_node = malloc(sizeof(mob_t));

    new_node->mob = malloc(sizeof(sprites_t));
    animation_mob("assets/mobs/b1.png", 0.15, (V2F){1.5, 1.5}, new_node->mob);
    sprite_position(pos, new_node->mob);
    new_node->position = pos;
    new_node->hitbox = rectancle((V2F){120, 120}, (V2F){pos.x, pos.y + 10}, sfColor_fromRGBA(0, 0, 0, 0));
    new_node->hp = 30;
    new_node->speed = 200;
    new_node->damage = 2;
    new_node->shot_speed = 0;
    new_node->range = 0;
    new_node->delay = 0;
    new_node->delay_a = false;
    new_node->finish = false;
    new_node->next = NULL;
    return new_node;
}

void add_b1(mob_t **mob, sfVector2f pos)
{
    mob_t *tmp = *mob;

    if (tmp == NULL) {
        *mob = new_b1mob(pos);
    } else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_b1mob(pos);
    }
}

static void check_hit(global_t *glob, mob_t *tmp, float delta_time)
{
    sfFloatRect rect1Bounds = sfRectangleShape_getGlobalBounds(glob->game->hitbox);
    sfFloatRect rect2Bounds = sfRectangleShape_getGlobalBounds(tmp->hitbox);
    bullet_t *temp = glob->game->shot;
    sfFloatRect rect3Bounds;

    while (temp) {
        rect3Bounds = sfRectangleShape_getGlobalBounds(temp->hitbox);
        if (temp->finish == false &&
            sfFloatRect_intersects(&rect2Bounds, &rect3Bounds, NULL)) {
            tmp->hp -= glob->game->stat.value_damage;
            temp->finish = true;
        }
        temp = temp->next;
    }
    if (tmp->delay_a == true) {
        tmp->delay += delta_time;
        if (tmp->delay >= 2) {
            tmp->delay_a = false;
            tmp->delay = 0;
        }
    } else {
        if (sfFloatRect_intersects(&rect1Bounds, &rect2Bounds, NULL)) {
            glob->game->life -= tmp->damage;
            tmp->delay_a = true;
        }
    }
    if (tmp->hp <= 0)
        glob->game->stat.xp += 60;
}

void update_b1(global_t* global, mob_t *mob, float delta_time)
{
    mob_t *tmp = mob;
    sfVector2f direction;
    float length = 0;

    while (tmp != NULL) {
        if (tmp->hp <= 0) {
            tmp->finish = true;
            tmp = tmp->next;
            continue;
        }
        direction.x = global->game->pos.x - tmp->position.x;
        direction.y = global->game->pos.y - tmp->position.y;
        length = sqrtf(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) {
            direction.x /= length;
            direction.y /= length;
        }
        tmp->position.x += direction.x * tmp->speed * delta_time;
        tmp->position.y += direction.y * tmp->speed * delta_time;
        sprite_position(tmp->position, tmp->mob);
        sfRectangleShape_setPosition(tmp->hitbox, (V2F){tmp->position.x, tmp->position.y + 10});
        update_animation(tmp->mob, delta_time);
        check_hit(global, tmp, delta_time);
        tmp = tmp->next;
    }
}
