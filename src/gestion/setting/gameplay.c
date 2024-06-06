/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** gameplay
*/

#include "my.h"
#define DIFF glob->settings->difficulty
#define EASY "assets/settings/gameplay/easy.png"
#define FACILE "assets/settings/gameplay/facile.png"
#define NORMAL "assets/settings/gameplay/normal.png"
#define NORMAL2 "assets/settings/gameplay/Normal.png"
#define HARD1 "assets/settings/gameplay/HARD.png"
#define HARD2 "assets/settings/gameplay/HARD1.png"
#define GOD1 "assets/settings/gameplay/GOD.png"
#define GOD2 "assets/settings/gameplay/GOD1.png"

static void coef1(global_t *glob)
{
    glob->difficulty = 1.0f;
}

static void coef_low(global_t *glob)
{
    glob->difficulty = 0.75f;
}

static void coef_hard(global_t *glob)
{
    glob->difficulty = 1.25f;
}

static void coef2(global_t *glob)
{
    glob->difficulty = 1.5f;
}

void init_gameplay(global_t *glob)
{
    glob->settings->choose_difficulty = malloc(sizeof(sprites_t));
    glob->settings->difficulty = malloc(sizeof(button_t));
    glob->settings->difficulty->list = NULL;
    glob->settings->difficulty->draw = &draw_button;
    glob->settings->difficulty->destroy = &destroy_button;
    CA("assets/settings/gameplay/difficulty.png", 0, (V2F){0.7, 0.7}, glob->settings->choose_difficulty);
    SP((V2F){750, 320}, glob->settings->choose_difficulty);
    CA("assets/settings/cursor.png", 0, (V2F){0.8, 0.8}, &(glob->settings->bull));
    SP((V2F){800, 750}, &(glob->settings->bull));
    add_button(DIFF, PT(EASY, FACILE, FACILE), (V2F){220, 520}, (V2F){0.5, 0.5});
    set_up_rec(DIFF, rec((V2F){223, 519}, (V2F){513, 614}, glob), &coef_low);
    add_button(DIFF, PT(NORMAL, NORMAL2, NORMAL2), (V2F){620, 520}, (V2F){0.5, 0.5});
    set_up_rec(DIFF, rec((V2F){619, 519}, (V2F){915, 614}, glob), &coef1);
    add_button(DIFF, PT(HARD1, HARD2, HARD2), (V2F){1020, 520}, (V2F){0.5, 0.5});
    set_up_rec(DIFF, rec((V2F){1022, 519}, (V2F){1315, 614}, glob), &coef_hard);
    add_button(DIFF, PT(GOD1, GOD2, GOD2), (V2F){1420, 520}, (V2F){0.5, 0.5});
    set_up_rec(DIFF, rec((V2F){1419, 519}, (V2F){1712, 614}, glob), &coef2);
}

int split_handle_gameplay(global_t *glob, sfEvent event, list_but_t *t)
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

void gameplay(global_t *glob)
{
    glob->settings->b = 2;
    DRAW(WINDOW, glob->settings->choose_difficulty->sprite, NULL);
    DIFF->draw(glob, DIFF);
    DRAW(WINDOW, glob->settings->bull.sprite, NULL);
    draw_text(glob, nbtostr(glob->difficulty), 60, (V2F){840, 790});
}