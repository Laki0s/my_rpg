/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s4
*/

#include "my.h"

void init_s4(global_t *glob)
{
    glob->game->all[3].entity = malloc(sizeof(sprites_t));
    glob->game->all[3].map = malloc(sizeof(sprites_t));
    glob->game->all[3].mobs.dinga = malloc(sizeof(mob_t));
    glob->game->all[3].mobs.dinga = NULL;
    add_mob(&glob->game->all[3].mobs.dinga, (V2F){200, 400});
    add_mob(&glob->game->all[3].mobs.dinga, (V2F){500, 800});
    add_mob(&glob->game->all[3].mobs.dinga, (V2F){900, 100});
    add_mob(&glob->game->all[3].mobs.dinga, (V2F){950, 700});
    add_mob(&glob->game->all[3].mobs.dinga, (V2F){350, 400});
    create_animation("assets/maps/r1.png", 0, (V2F){1.92, 1.674}, glob->game->all[3].map);
    create_animation("assets/maps/r1s.png", 0, (V2F){1.92, 1.674}, glob->game->all[3].entity);
    glob->game->all[3].colision = sfImage_createFromFile("assets/maps/r1s.png");
}

void handle_s4(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s4(global_t *glob)
{
    if (test_entity(glob->game->all[3].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 0;
        glob->game->pos = (V2F){915, 778};
        }
    if (test_entity(glob->game->all[3].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 6;
        glob->game->pos = (V2F){1682, 463};
        }
    if (test_entity(glob->game->all[3].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 8;
        glob->game->pos = (V2F){1672, 472};
        }
    if (test_entity(glob->game->all[3].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 255)) == 0) {
        glob->game->index = 12;
        glob->game->pos = (V2F){1672, 472};
        }
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    update_mob(glob, glob->game->all[3].mobs.dinga, glob->delta_time);
}

void draw_s4(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[3].map->sprite, NULL);
    draw_mob(glob, glob->game->all[3].mobs.dinga);
}

void destroy_s4(global_t *glob)
{
    delete_mob(glob->game->all[3].mobs.dinga);
    free(glob->game->all[3].entity);
    free(glob->game->all[3].map);
}
