/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s5
*/

#include "my.h"

void init_s5(global_t *glob)
{
    glob->game->all[4].entity = malloc(sizeof(sprites_t));
    glob->game->all[4].map = malloc(sizeof(sprites_t));
    glob->game->all[4].mobs.bat = malloc(sizeof(mob_t));
    glob->game->all[4].mobs.bat2 = malloc(sizeof(mob_t));
    glob->game->all[4].mobs.bat = NULL;
    glob->game->all[4].mobs.bat2 = NULL;
    add_bat(&glob->game->all[4].mobs.bat, (V2F){200, 400});
    add_bat(&glob->game->all[4].mobs.bat, (V2F){500, 800});
    add_bat2(&glob->game->all[4].mobs.bat2, (V2F){900, 100});
    add_bat2(&glob->game->all[4].mobs.bat2, (V2F){950, 700});
    add_bat(&glob->game->all[4].mobs.bat, (V2F){350, 400});
    create_animation("assets/maps/r1.png", 0, (V2F){1.92, 1.674}, glob->game->all[4].map);
    create_animation("assets/maps/r1s.png", 0, (V2F){1.92, 1.674}, glob->game->all[4].entity);
    glob->game->all[4].colision = sfImage_createFromFile("assets/maps/r1s.png");
}

void handle_s5(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s5(global_t *glob)
{
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
    if (test_entity(glob->game->all[4].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 0;
        glob->game->pos = (V2F){1603, 498};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[4].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 10;
        glob->game->pos = (V2F){920, 780};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[4].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 255)) == 0) {
        glob->game->index = 13;
        glob->game->pos = (V2F){500, 500};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    if (test_entity(glob->game->all[4].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 0;
        glob->game->pos = (V2F){500, 500};
        sprite_position(glob->game->pos, &glob->game->steps[STATE]);
        }
    update_bat2(glob, glob->game->all[4].mobs.bat2, glob->delta_time);
    update_bat(glob, glob->game->all[4].mobs.bat, glob->delta_time);
}

void draw_s5(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[4].map->sprite, NULL);
    draw_mob(glob, glob->game->all[4].mobs.bat);
    draw_mob(glob, glob->game->all[4].mobs.bat2);
}

void destroy_s5(global_t *glob)
{
    delete_mob(glob->game->all[4].mobs.bat);
    delete_mob(glob->game->all[4].mobs.bat2);
    free(glob->game->all[4].entity);
    free(glob->game->all[4].map);
}
