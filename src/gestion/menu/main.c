/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include "my.h"

static void init_but(menu_t *menu, global_t *glob)
{
    menu->but = malloc(sizeof(button_t));
    menu->but->list = NULL;
    menu->but->draw = &draw_button;
    menu->but->destroy = &destroy_button;
    add_button(menu->but, paths_to_tab("assets/but/Start.png", "assets/but/start.png", "assets/but/Start.png"), (sfVector2f){770, 440}, (sfVector2f){0.6, 0.6});
    set_up_rec(menu->but, rec((sfVector2f){772, 442}, (sfVector2f){1129, 559}, glob), &start);
    add_button(menu->but, paths_to_tab("assets/but/Settings.png", "assets/but/settings.png", "assets/but/Start.png"), (sfVector2f){770, 570}, (sfVector2f){0.6, 0.6});
    set_up_rec(menu->but, rec((sfVector2f){772, 573}, (sfVector2f){1129, 689}, glob), &setting);
    add_button(menu->but, paths_to_tab("assets/but/Exit.png", "assets/but/exit.png", "assets/but/Start.png"), (sfVector2f){770, 700}, (sfVector2f){0.6, 0.6});
    set_up_rec(menu->but, rec((sfVector2f){772, 702}, (sfVector2f){1129, 818}, glob), &leave);
}

void init_menu(global_t *glob)
{
    glob->menu = malloc(sizeof(menu_t));
    glob->menu->b1 = malloc(sizeof(sprites_t));
    glob->menu->b2 = malloc(sizeof(sprites_t));
    glob->menu->title = malloc(sizeof(sprites_t));
    create_animation("assets/tittle.png", 0, (sfVector2f){1, 1}, glob->menu->title);
    sprite_position((sfVector2f){420, 0}, glob->menu->title);
    create_animation("assets/background/menu.png", 0,  (sfVector2f){0.3, 0.432}, glob->menu->b1);
    sprite_position((sfVector2f){0, 0}, glob->menu->b1);
    create_animation("assets/background/menu.png", 0,  (sfVector2f){0.3, 0.432}, glob->menu->b2);
    sprite_position((sfVector2f){1920, 0}, glob->menu->b2);
    init_but(glob->menu, glob);
}

static int split_handle(global_t *glob, sfEvent event, list_but_t *t)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (sfFloatRect_contains(&(t->button->rec), m.x, m.y)) {
        if (t->current == STANDBY)
            sfSound_play(glob->bitbox.act);
        if (event.type == sfEvtMouseButtonReleased) {
            t->button->action(glob);
            return (ACTIVE);
        } else {
            return (HOVER);
        }
    } else
        return (STANDBY);
}

void handle_menu_events(global_t *glob)
{
    list_but_t *t = glob->menu->but->list;
    sfEvent event;

    while (POLLEVENT(WINDOW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        while (t) {
            t->current = split_handle(glob, event, t);
            t = t->next;
        }
        check_screen(glob, event);
    }
}

void update_menu(global_t *glob)
{
    if (glob->menu->b1->pos.x + 1920 < 0) {
        sprite_position((sfVector2f){1915, 0}, glob->menu->b1);
    } else {
        glob->menu->b1->pos.x -= 1;
        sfSprite_setPosition(glob->menu->b1->sprite, glob->menu->b1->pos);
    }
    if (glob->menu->b2->pos.x + 1920 < 0)
        sprite_position((sfVector2f){1915, 0}, glob->menu->b2);
    else {
        glob->menu->b2->pos.x -= 1;
        sfSprite_setPosition(glob->menu->b2->sprite, glob->menu->b2->pos);
    }
}

void draw_menu(global_t *glob)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    DRAW(WINDOW, glob->menu->b1->sprite, NULL);
    DRAW(WINDOW, glob->menu->b2->sprite, NULL);
    DRAW(WINDOW, glob->menu->title->sprite, NULL);
    glob->menu->but->draw(glob, glob->menu->but);
    DRAW(WINDOW, glob->cursor.sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void destroy_menu(global_t *glob)
{
    sfSprite_destroy(glob->menu->title->sprite);
    sfSprite_destroy(glob->menu->b1->sprite);
    sfSprite_destroy(glob->menu->b2->sprite);
    sfTexture_destroy(glob->menu->title->texture);
    sfTexture_destroy(glob->menu->b1->texture);
    sfTexture_destroy(glob->menu->b2->texture);
    glob->menu->but->destroy(glob->menu->but);
    free(glob->menu->b1);
    free(glob->menu->b2);
    free(glob->menu->title);
    free(glob->menu);
}

