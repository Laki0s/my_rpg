/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include "my.h"

void init_load(global_t *glob)
{
    glob->load = malloc(sizeof(load_t));
    glob->load->limousine = malloc(sizeof(sprites_t));
    create_animation("assets/background/caca.png", 0, (sfVector2f){1, 1}, glob->load->limousine);
    glob->load->r = rectancle((sfVector2f){1920, 1080}, (sfVector2f){0, 0}, sfColor_fromRGBA(0, 0, 0, 255));
    glob->load->a = 255;
}

void handle_load_events(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (evt.type == sfEvtMouseButtonPressed &&
            sfMouse_isButtonPressed(sfMouseLeft))
            glob->timer = 1.81;
        check_screen(glob, evt);
    }
}

void update_load(global_t *glob)
{
    if (glob->load->a > 0 && glob->timer < 1.8) {
        glob->load->a -= 1;
    } else {
        glob->load->a += 1;
        if (glob->load->a > 254)
        glob->current_scene = MENU;
    }
    sfRectangleShape_setFillColor(glob->load->r, sfColor_fromRGBA(0, 0, 0, glob->load->a));
}

void draw_load(global_t *glob)
{
    sfRenderWindow_clear(WINDOW, sfMagenta);
    DRAW(WINDOW, glob->load->limousine->sprite, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, glob->load->r, NULL);
    sfRenderWindow_display(WINDOW);
}

void destroy_load(global_t *glob)
{
    sfSprite_destroy(glob->load->limousine->sprite);
    sfTexture_destroy(glob->load->limousine->texture);
    sfRectangleShape_destroy(glob->load->r);
    free(glob->load->limousine);
    free(glob->load);
}

