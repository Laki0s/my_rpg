/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s2
*/

#include "my.h"

void init_s8(global_t *glob)
{
    glob->game->all[7].entity = malloc(sizeof(sprites_t));
    glob->game->all[7].map = malloc(sizeof(sprites_t));
    glob->game->all[7].mobs.slime = malloc(sizeof(sprites_t));
    glob->game->all[7].mobs.tear = malloc(sizeof(sprites_t));
    glob->game->all[7].mobs.tear = NULL;
    glob->game->all[7].mobs.slime = NULL;
    add_slime(&glob->game->all[7].mobs.slime, (V2F){900, 100});
    add_tear(&glob->game->all[7].mobs.tear, (V2F){500, 400});
    create_animation("assets/maps/r4.png", 0, (V2F){1.92, 1.674}, glob->game->all[7].map);
    create_animation("assets/maps/r4s.png", 0, (V2F){1.92, 1.674}, glob->game->all[7].entity);
    glob->game->all[7].colision = sfImage_createFromFile("assets/maps/r4s.png");
}

void handle_s8(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s8(global_t *glob)
{
    if (test_entity(glob->game->all[7].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 1;
        glob->game->pos = (V2F){918, 107};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[7].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 2;
        glob->game->pos = (V2F){190, 476};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    }
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    update_slime(glob, glob->game->all[7].mobs.slime, glob->delta_time);
    update_tear(glob, glob->game->all[7].mobs.tear, glob->delta_time);
}

void draw_s8(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[7].map->sprite, NULL);
    draw_mob(glob, glob->game->all[7].mobs.slime);
    draw_mob(glob, glob->game->all[7].mobs.tear);
}

void destroy_s8(global_t *glob)
{
    delete_mob(glob->game->all[7].mobs.slime);
    delete_mob(glob->game->all[7].mobs.tear);
    free(glob->game->all[7].entity);
    free(glob->game->all[7].map);
}
