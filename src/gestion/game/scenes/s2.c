/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s2
*/

#include "my.h"

void init_s2(global_t *glob)
{
    glob->game->all[1].entity = malloc(sizeof(sprites_t));
    glob->game->all[1].map = malloc(sizeof(sprites_t));
    glob->game->all[1].mobs.dinga = malloc(sizeof(mob_t));
    glob->game->all[1].mobs.dinga = NULL;
    create_animation("assets/maps/r2.png", 0, (V2F){1.92, 1.674}, glob->game->all[1].map);
    create_animation("assets/maps/r2s.png", 0, (V2F){1.92, 1.674}, glob->game->all[1].entity);
    glob->game->all[1].colision = sfImage_createFromFile("assets/maps/r2s.png");
    add_mob(&glob->game->all[1].mobs.dinga, (V2F){200, 400});
    add_mob(&glob->game->all[1].mobs.dinga, (V2F){500, 800});
    add_mob(&glob->game->all[1].mobs.dinga, (V2F){900, 100});
    add_mob(&glob->game->all[1].mobs.dinga, (V2F){950, 700});
    add_mob(&glob->game->all[1].mobs.dinga, (V2F){350, 400});
}

void handle_s2(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s2(global_t *glob)
{
    if (test_entity(glob->game->all[1].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 255)) == 0) {
        glob->game->index = 0;
        glob->game->pos = (V2F){250, 500};
        }
    if (test_entity(glob->game->all[1].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 5;
        glob->game->pos = (V2F){1663, 454};
        }
    if (test_entity(glob->game->all[1].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 6;
        glob->game->pos = (V2F){1682, 463};
        }
    if (test_entity(glob->game->all[1].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 7;
        glob->game->pos = (V2F){922, 826};
        }
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    update_mob(glob, glob->game->all[1].mobs.dinga, glob->delta_time);
}

void draw_s2(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[1].map->sprite, NULL);
    draw_mob(glob, glob->game->all[1].mobs.dinga);
}

void destroy_s2(global_t *glob)
{
    delete_mob(glob->game->all[1].mobs.dinga);
    free(glob->game->all[1].entity);
    free(glob->game->all[1].map);
}
