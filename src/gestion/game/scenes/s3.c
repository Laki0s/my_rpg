/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s3
*/

#include "my.h"

void init_s3(global_t *glob)
{
    glob->game->all[2].entity = malloc(sizeof(sprites_t));
    glob->game->all[2].map = malloc(sizeof(sprites_t));
    glob->game->all[2].mobs.dinga = malloc(sizeof(mob_t));
    glob->game->all[2].mobs.dinga = NULL;
    add_mob(&glob->game->all[2].mobs.dinga, (V2F){200, 400});
    add_mob(&glob->game->all[2].mobs.dinga, (V2F){500, 800});
    add_mob(&glob->game->all[2].mobs.dinga, (V2F){900, 100});
    add_mob(&glob->game->all[2].mobs.dinga, (V2F){950, 700});
    add_mob(&glob->game->all[2].mobs.dinga, (V2F){350, 400});
    create_animation("assets/maps/r1.png", 0, (V2F){1.92, 1.674}, glob->game->all[2].map);
    create_animation("assets/maps/r1s.png", 0, (V2F){1.92, 1.674}, glob->game->all[2].entity);
    glob->game->all[2].colision = sfImage_createFromFile("assets/maps/r1s.png");

}

void handle_s3(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s3(global_t *glob)
{
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    if (test_entity(glob->game->all[2].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 0;
        glob->game->pos = (V2F){931, 191};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[2].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 7;
        glob->game->pos = (V2F){924, 191};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[2].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 11;
        glob->game->pos = (V2F){922, 826};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[2].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 255)) == 0) {
        glob->game->index = 10;
        glob->game->pos = (V2F){922, 125};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    update_mob(glob, glob->game->all[2].mobs.dinga, glob->delta_time);
}

void draw_s3(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[2].map->sprite, NULL);
    draw_mob(glob, glob->game->all[2].mobs.dinga);
}

void destroy_s3(global_t *glob)
{
    delete_mob(glob->game->all[2].mobs.dinga);
    free(glob->game->all[2].entity);
    free(glob->game->all[2].map);
}
