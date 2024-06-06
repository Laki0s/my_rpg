/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s9
*/

#include "my.h"

void init_s9(global_t *glob)
{
    glob->game->all[8].entity = malloc(sizeof(sprites_t));
    glob->game->all[8].map = malloc(sizeof(sprites_t));
    glob->game->all[8].mobs.b3 = malloc(sizeof(mob_t));
    glob->game->all[8].mobs.b3 = NULL;
    add_b3(&glob->game->all[8].mobs.b3, (V2F){900, 100});
    add_b3(&glob->game->all[8].mobs.b3, (V2F){500, 400});
    create_animation("assets/maps/boss5.png", 0, (V2F){1.92, 1.674}, glob->game->all[8].map);
    create_animation("assets/maps/boss5c.png", 0, (V2F){1.92, 1.674}, glob->game->all[8].entity);
    glob->game->all[8].colision = sfImage_createFromFile("assets/maps/boss5c.png");
}

void handle_s9(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s9(global_t *glob)
{
    if (test_entity(glob->game->all[8].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 3;
        glob->game->pos = (V2F){915, 821};
        }
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    update_b3(glob, glob->game->all[8].mobs.b3, glob->delta_time);
}

void draw_s9(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[8].map->sprite, NULL);
    draw_mob(glob, glob->game->all[8].mobs.b3);
}

void destroy_s9(global_t *glob)
{
    delete_mob(glob->game->all[8].mobs.b3);
    free(glob->game->all[8].entity);
    free(glob->game->all[8].map);
}
