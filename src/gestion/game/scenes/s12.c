/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s12
*/

#include "my.h"

void init_s12(global_t *glob)
{
    glob->game->all[11].entity = malloc(sizeof(sprites_t));
    glob->game->all[11].map = malloc(sizeof(sprites_t));
    glob->game->all[11].mobs.boul = malloc(sizeof(mob_t));
    glob->game->all[11].mobs.boul = NULL;
    add_boul(&glob->game->all[11].mobs.boul, (V2F){900, 100});
    add_boul(&glob->game->all[11].mobs.boul, (V2F){500, 500});
    add_boul(&glob->game->all[11].mobs.boul, (V2F){700, 100});
    add_boul(&glob->game->all[11].mobs.boul, (V2F){100, 400});
    add_boul(&glob->game->all[11].mobs.boul, (V2F){300, 800});
    create_animation("assets/maps/r4.png", 0, (V2F){1.92, 1.674}, glob->game->all[11].map);
    create_animation("assets/maps/r4s.png", 0, (V2F){1.92, 1.674}, glob->game->all[11].entity);
    glob->game->all[11].colision = sfImage_createFromFile("assets/maps/r4s.png");
}

void handle_s12(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s12(global_t *glob)
{
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    if (test_entity(glob->game->all[11].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 0;
        glob->game->pos = (V2F){480, 268};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[11].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 2;
        glob->game->pos = (V2F){920, 180};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    update_boul(glob, glob->game->all[11].mobs.boul, glob->delta_time);
}

void draw_s12(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[11].map->sprite, NULL);
    draw_mob(glob, glob->game->all[11].mobs.boul);
}

void destroy_s12(global_t *glob)
{
    delete_mob(glob->game->all[11].mobs.boul);
    free(glob->game->all[11].entity);
    free(glob->game->all[11].map);
}
