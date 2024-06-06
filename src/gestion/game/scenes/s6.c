/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s2
*/

#include "my.h"

void init_s6(global_t *glob)
{
    glob->game->all[5].entity = malloc(sizeof(sprites_t));
    glob->game->all[5].map = malloc(sizeof(sprites_t));
    glob->game->all[5].mobs.b1 = malloc(sizeof(mob_t));
    glob->game->all[5].mobs.dinga = malloc(sizeof(mob_t));
    glob->game->all[5].mobs.dinga = NULL;
    glob->game->all[5].mobs.b1 = NULL;
    add_b1(&glob->game->all[5].mobs.b1, (V2F){900, 100});
    add_mob(&glob->game->all[5].mobs.dinga, (V2F){200, 400});
    add_mob(&glob->game->all[5].mobs.dinga, (V2F){500, 800});
    create_animation("assets/maps/boss5.png", 0, (V2F){1.92, 1.674}, glob->game->all[5].map);
    create_animation("assets/maps/boss5c.png", 0, (V2F){1.92, 1.674}, glob->game->all[5].entity);
    glob->game->all[5].colision = sfImage_createFromFile("assets/maps/boss5c.png");
}

void handle_s6(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s6(global_t *glob)
{
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    if (test_entity(glob->game->all[5].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 1;
        glob->game->pos = (V2F){137, 483};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    update_b1(glob, glob->game->all[5].mobs.b1, glob->delta_time);
    update_mob(glob, glob->game->all[5].mobs.dinga, glob->delta_time);
}

void draw_s6(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[5].map->sprite, NULL);
    draw_mob(glob, glob->game->all[5].mobs.dinga);
    draw_mob(glob, glob->game->all[5].mobs.b1);
}

void destroy_s6(global_t *glob)
{
    delete_mob(glob->game->all[5].mobs.b1);
    delete_mob(glob->game->all[5].mobs.dinga);
    free(glob->game->all[5].entity);
    free(glob->game->all[5].map);
}
