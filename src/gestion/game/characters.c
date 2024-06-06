/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** characters
*/

#include "my.h"

static int check_collision(global_t *glob, sfImage* map, sfVector2f pos, float velocity)
{
    sfColor color_x1 = sfImage_getPixel(map, pos.x + velocity + 100, pos.y);
    sfColor color_x2 = sfImage_getPixel(map, pos.x - velocity, pos.y);
    sfColor color_y1 = sfImage_getPixel(map, pos.x, pos.y + velocity + 130);
    sfColor color_y2 = sfImage_getPixel(map, pos.x, pos.y - velocity);

    if (glob->game->stat.left == true)
        if (color_x2.r == 0 && color_x2.g == 0 && color_x2.b == 0)
            return 1;
    if (glob->game->stat.rigth == true)
        if (color_x1.r == 0 && color_x1.g == 0 && color_x1.b == 0)
            return 1;
    if (glob->game->stat.top == true)
        if (color_y2.r == 0 && color_y2.g == 0 && color_y2.b == 0)
            return 1;
    if (glob->game->stat.bot == true)
        if (color_y1.r == 0 && color_y1.g == 0 && color_y1.b == 0)
            return 1;
    return 0;
}

static void left(global_t *glob)
{
    glob->game->stat.left = true;
    glob->game->stat.rigth = false;
    glob->game->stat.top = false;
    glob->game->stat.bot = false;
    STATE = 3;
}

static void rigth(global_t *glob)
{
    glob->game->stat.left = false;
    glob->game->stat.rigth = true;
    glob->game->stat.top = false;
    glob->game->stat.bot = false;
    STATE = 2;
}

static void top(global_t *glob)
{
    glob->game->stat.left = false;
    glob->game->stat.rigth = false;
    glob->game->stat.top = true;
    glob->game->stat.bot = false;
    STATE = 1;
}

static void bot(global_t *glob)
{
    glob->game->stat.left = false;
    glob->game->stat.rigth = false;
    glob->game->stat.top = false;
    glob->game->stat.bot = true;
    STATE = 0;
}

static void isaac(global_t *glob, sfEvent evt, sfVector2f new)
{
    if (evt.type == sfEvtMouseButtonPressed &&
        sfMouse_isButtonPressed(glob->binding.melee) &&
        glob->game->stat.delay_a == false) {
            glob->game->battle_mode = true;
            add_bullet(glob);
            glob->game->stat.delay_a = true;
        }
    if (evt.type == sfEvtMouseButtonPressed &&
        sfMouse_isButtonPressed(glob->binding.secondary)) {
            //fouiller
    }
    if (evt.type == sfEvtKeyPressed) {
        if (evt.key.code == glob->binding.forward - 2) {
            new.y += (1.2 * glob->game->stat.value_speed);
            bot(glob);
        }
        if (evt.key.code == glob->binding.backward - 2) {
            new.y -= (1.2 * glob->game->stat.value_speed);
            top(glob);
        }
        if (evt.key.code == glob->binding.right - 2) {
            new.x += (1.2 * glob->game->stat.value_speed);
            rigth(glob);
        }
        if (evt.key.code == glob->binding.left - 2) {
            new.x -= (1.2 * glob->game->stat.value_speed);
            left(glob);
        }
        if (check_collision(glob, glob->game->all[glob->game->index].colision, glob->game->pos, (1.2 * glob->game->stat.value_speed)) == 0)
            glob->game->pos = new;
    } else {
        if (STATE < 4)
            STATE += 4;
    }
}

void characters(global_t *glob, sfEvent event, sfVector2f new)
{
    if (glob->charac.class == 0)
        isaac(glob, event, new);
}