 /*
** EPITECH PROJECT, 2024
** rpg
** File description:
** s1
*/

#include "my.h"

void init_s1(global_t *glob)
{
    glob->game->all[0].entity = malloc(sizeof(sprites_t));
    glob->game->all[0].map = malloc(sizeof(sprites_t));
    create_animation("assets/maps/s1.png", 0, (V2F){1.92, 1.674}, glob->game->all[0].map);
    create_animation("assets/maps/s1s.png", 0, (V2F){1, 1}, glob->game->all[0].entity);
    glob->game->all[0].colision = sfImage_createFromFile("assets/maps/s1s.png");
}

void handle_s1(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_s1(global_t *glob)
{
    if (test_entity(glob->game->all[0].colision,
        glob->game->pos, sfColor_fromRGB(255, 255, 0)) == 0) {
        glob->game->index = 1;
        glob->game->pos = (V2F){1600, 492};
        }
    if (test_entity(glob->game->all[0].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 255)) == 0) {
        glob->game->index = 2;
        glob->game->pos = (V2F){915, 754};
        }
    if (test_entity(glob->game->all[0].colision,
        glob->game->pos, sfColor_fromRGB(255, 0, 0)) == 0) {
        glob->game->index = 4;
        glob->game->pos = (V2F){200, 483};
        }
    if (test_entity(glob->game->all[0].colision,
        glob->game->pos, sfColor_fromRGB(0, 255, 0)) == 0) {
        glob->game->index = 3;
        glob->game->pos = (V2F){912, 163};
        }
    sprite_position(glob->game->pos, &glob->game->steps[STATE]);
}

void draw_s1(global_t *glob)
{
    DRAW(WINDOW, glob->game->all[0].map->sprite, NULL);
}

void destroy_s1(global_t *glob)
{
    free(glob->game->all[0].entity);
    free(glob->game->all[0].map);
}