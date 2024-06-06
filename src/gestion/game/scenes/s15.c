/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s15
*/

#include "my.h"

void init_s15(global_t *glob)
{
    glob->game->all[14].entity = malloc(sizeof(sprites_t));
    glob->game->all[14].map = malloc(sizeof(sprites_t));
    create_animation("assets/maps/boss5.png", 0, (V2F){1.92, 1.674}, glob->game->all[14].map);
    create_animation("assets/maps/r3s.png", 0, (V2F){1.92, 1.674}, glob->game->all[14].entity);
    glob->game->all[14].colision = sfImage_createFromFile("assets/maps/r3s.png");
}

void handle_s15(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s15(global_t *glob)
{
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
}

void draw_s15(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[14].map->sprite, NULL);
}

void destroy_s15(global_t *glob)
{
    free(glob->game->all[14].entity);
    free(glob->game->all[14].map);
}