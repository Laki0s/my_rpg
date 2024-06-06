/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s11
*/

#include "my.h"

void init_s11(global_t *glob)
{
    glob->game->all[10].entity = malloc(sizeof(sprites_t));
    glob->game->all[10].map = malloc(sizeof(sprites_t));
    glob->game->all[10].mobs.boul = malloc(sizeof(mob_t));
    glob->game->all[10].mobs.boul = NULL;
    add_boul(&glob->game->all[10].mobs.boul, (V2F){900, 100});
    add_boul(&glob->game->all[10].mobs.boul, (V2F){500, 500});
    add_boul(&glob->game->all[10].mobs.boul, (V2F){700, 100});
    add_boul(&glob->game->all[10].mobs.boul, (V2F){100, 400});
    add_boul(&glob->game->all[10].mobs.boul, (V2F){300, 800});
    create_animation("assets/maps/r3.png", 0, (V2F){1.92, 1.674}, glob->game->all[10].map);
    create_animation("assets/maps/r3s.png", 0, (V2F){1.92, 1.674}, glob->game->all[10].entity);
    glob->game->all[10].colision = sfImage_createFromFile("assets/maps/r3s.png");
}

void handle_s11(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s11(global_t *glob)
{
    if (test_entity(glob->game->all[10].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 2;
        glob->game->pos = (V2F){1651, 490};
        }
    if (test_entity(glob->game->all[10].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 4;
        glob->game->pos = (V2F){920, 156};
        }
    if (test_entity(glob->game->all[10].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 255)) == 0) {
        glob->game->index = 12;
        glob->game->pos = (V2F){920, 156};
        }
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    update_boul(glob, glob->game->all[10].mobs.boul, glob->delta_time);
}

void draw_s11(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[10].map->sprite, NULL);
    draw_mob(glob, glob->game->all[10].mobs.boul);
}

void destroy_s11(global_t *glob)
{
    delete_mob(glob->game->all[10].mobs.boul);
    free(glob->game->all[10].entity);
    free(glob->game->all[10].map);
}
