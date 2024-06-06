/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** bullet
*/

#include "my.h"

static void check_direction(global_t *glob, bullet_t *new_node)
{
    if (glob->game->stat.top == true) {
        new_node->end = (V2F){glob->game->pos.x, glob->game->pos.y + (glob->charac.range)};
        new_node->a = 0;
    }
    if (glob->game->stat.bot == true) {
        new_node->end = (V2F){glob->game->pos.x, glob->game->pos.y - (glob->charac.range)};
        new_node->a = 1;
        }
    if (glob->game->stat.left == true) {
        new_node->end = (V2F){glob->game->pos.x + (glob->charac.range), glob->game->pos.y};
        new_node->a = 2;
        }
    if (glob->game->stat.rigth == true) {
        new_node->end = (V2F){glob->game->pos.x - (glob->charac.range), glob->game->pos.y};
        new_node->a = 3;
        }
    glob->game->stat.top = false;
    glob->game->stat.bot = false;
    glob->game->stat.left = false;
    glob->game->stat.rigth = false;
}

static bullet_t *new_bullet(global_t *glob)
{
    bullet_t *new_node = malloc(sizeof(bullet_t));
    sfVector2f pos = glob->game->pos;

    create_animation("assets/tear.png", 0, (V2F){1, 1}, &new_node->bullet);
    new_node->bullet.pos = pos;
    new_node->old = pos;
    sprite_position(new_node->bullet.pos, &new_node->bullet);
    new_node->a = 10;
    check_direction(glob, new_node);
    new_node->hitbox = rectancle((V2F){50, 50}, (V2F){pos.x + 10, pos.y + 5},
        sfColor_fromRGBA(0, 0, 0, 0));
    new_node->next = NULL;
    new_node->finish = false;
    return new_node;
}

void add_bullet(global_t *glob)
{
    bullet_t *tmp = glob->game->shot;

    if (tmp == NULL) {
        glob->game->shot = new_bullet(glob);
    } else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_bullet(glob);
    }
}

void update_bullet(global_t *glob)
{
    bullet_t *tmp = glob->game->shot;

    if (tmp == NULL)
        return;
    while (tmp) {
        if (tmp->a == 0) {
            tmp->bullet.pos.y += ((1000) * glob->delta_time);
            if (tmp->bullet.pos.y >= tmp->end.y)
                tmp->finish = true;
        }
        if (tmp->a == 1) {
            tmp->bullet.pos.y -= ((1000) * glob->delta_time);
            if (tmp->bullet.pos.y <= tmp->end.y)
                tmp->finish = true;
        }
        if (tmp->a == 3) {
            tmp->bullet.pos.x -= ((1000) * glob->delta_time);
            if (tmp->bullet.pos.x <= tmp->end.x)
                tmp->finish = true;
        }
        if (tmp->a == 2) {
            tmp->bullet.pos.x += ((1000) * glob->delta_time);
            if (tmp->bullet.pos.x >= tmp->end.x)
                tmp->finish = true;
        }
        sprite_position(tmp->bullet.pos, &tmp->bullet);
        sfRectangleShape_setPosition(tmp->hitbox, (V2F){tmp->bullet.pos.x + 10, tmp->bullet.pos.y + 5});
        tmp = tmp->next;
    }
}


void draw_bullet(global_t *glob)
{
    bullet_t *tmp = glob->game->shot;

    if (tmp == NULL)
        return;
    while (tmp) {
        if (tmp->finish == false) {
            sfRenderWindow_drawSprite(WINDOW, tmp->bullet.sprite, NULL);
        }
        tmp = tmp->next;
    }
}
