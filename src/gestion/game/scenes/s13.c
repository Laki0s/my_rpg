/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** 13
*/

#include "my.h"

void init_s13(global_t *glob)
{
    glob->game->all[12].entity = malloc(sizeof(sprites_t));
    glob->game->all[12].map = malloc(sizeof(sprites_t));
    glob->game->all[12].mobs.b2 = malloc(sizeof(mob_t));
    glob->game->all[12].mobs.b2 = NULL;
    add_b2(&glob->game->all[12].mobs.b2, (V2F){900, 100});
    add_b2(&glob->game->all[12].mobs.b2, (V2F){500, 400});
    create_animation("assets/maps/boss5.png", 0, (V2F){1.92, 1.674}, glob->game->all[12].map);
    create_animation("assets/maps/boss5c.png", 0, (V2F){1.92, 1.674}, glob->game->all[12].entity);
    glob->game->all[12].colision = sfImage_createFromFile("assets/maps/boss5c.png");
}

void handle_s13(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s13(global_t *glob)
{
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    if (test_entity(glob->game->all[12].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 0;
        glob->game->pos = (V2F){500, 500};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    update_b2(glob, glob->game->all[12].mobs.b2, glob->delta_time);
}

void draw_s13(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[12].map->sprite, NULL);
    draw_mob(glob, glob->game->all[12].mobs.b2);
}

void destroy_s13(global_t *glob)
{
    delete_mob(glob->game->all[12].mobs.b2);
    free(glob->game->all[12].entity);
    free(glob->game->all[12].map);
}
