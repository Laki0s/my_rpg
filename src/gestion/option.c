/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** option
*/

#include "my.h"

static void quit(global_t *glob)
{
    glob->game->option->active = false;
    save(glob);
}

void init_option(global_t *glob)
{
    glob->game->option = malloc(sizeof(option_t));
    glob->game->option->active = false;
    glob->game->option->back = malloc(sizeof(sprites_t));
    glob->game->option->but = malloc(sizeof(button_t));
    glob->game->option->but->list = NULL;
    glob->game->option->but->draw = &draw_button;
    glob->game->option->but->destroy = &destroy_button;
    glob->game->option->rec = rectancle((V2F){1920, 1080}, (V2F){0, 0}, sfColor_fromRGBA(0, 0, 0, 150));
    create_animation("assets/cadres.png", 0, (V2F){4, 4}, glob->game->option->back);
    sprite_position((V2F){600, 150}, glob->game->option->back);
    add_button(glob->game->option->but, paths_to_tab("assets/GUI/x.png", "assets/GUI/X.png", "assets/GUI/X.png"), (sfVector2f){1284, 180}, (sfVector2f){0.3, 0.3});
    set_up_rec(glob->game->option->but, rec((sfVector2f){1284, 180}, (sfVector2f){1341, 236}, glob), &quit);
    add_button(glob->game->option->but, paths_to_tab("assets/but/Resume.png", "assets/but/resume.png", "assets/but/resume.png"), (sfVector2f){800, 320}, (sfVector2f){0.6, 0.6});
    set_up_rec(glob->game->option->but, rec((sfVector2f){800, 320}, (sfVector2f){1154, 435}, glob), &quit);
    add_button(glob->game->option->but, paths_to_tab("assets/but/Settings.png", "assets/but/settings.png", "assets/but/settings.png"), (sfVector2f){800, 450}, (sfVector2f){0.6, 0.6});
    set_up_rec(glob->game->option->but, rec((sfVector2f){800, 450}, (sfVector2f){1154, 563}, glob), &setting);
    add_button(glob->game->option->but, paths_to_tab("assets/but/Menu.png", "assets/but/menu.png", "assets/but/menu.png"), (sfVector2f){800, 580}, (sfVector2f){0.6, 0.6});
    set_up_rec(glob->game->option->but, rec((sfVector2f){800, 580}, (sfVector2f){1154, 694}, glob), &home);
    add_button(glob->game->option->but, paths_to_tab("assets/but/Quit.png", "assets/but/quit.png", "assets/but/quit.png"), (sfVector2f){800, 710}, (sfVector2f){0.6, 0.6});
    set_up_rec(glob->game->option->but, rec((sfVector2f){800, 710}, (sfVector2f){1154, 824}, glob), &leave);
    glob->game->option->active = false;
    glob->game->option->hitbox = false;
}

static int split_handle(global_t *glob, sfEvent event, list_but_t *t)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (sfFloatRect_contains(&(t->button->rec), m.x, m.y)) {
        if (t->current == STANDBY)
            sfSound_play(glob->bitbox.act);
        if (event.type == sfEvtMouseButtonPressed) {
            t->button->action(glob);
            return (ACTIVE);
        } else {
            return (HOVER);
        }
    } else
        return (STANDBY);
}

void handle_option(global_t *glob, sfEvent event)
{
    list_but_t *t = glob->game->option->but->list;

    while (t) {
        t->current = split_handle(glob, event, t);
        t = t->next;
    }
}

void draw_option(global_t *glob)
{
    if (glob->game->option->active == true) {
        DRAW(WINDOW, glob->game->option->back->sprite, NULL);
        draw_text(glob, "Option", 150, (V2F){800, 130});
        glob->game->option->but->draw(glob, glob->game->option->but);
        DRAW(WINDOW, glob->cursor.sprite, NULL);
    }
}

void destroy_option(global_t *glob)
{
    glob->game->option->but->destroy(glob->game->option->but);
    sfSprite_destroy(glob->game->option->back->sprite);
    sfTexture_destroy(glob->game->option->back->texture);
    free(glob->game->option);
    free(glob->game->option->back);
}