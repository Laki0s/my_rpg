/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** invotory
*/
#include "my.h"
#define EKC evt.key.code
#define GGII glob->game->inv.items

void init_inventory(global_t *glob)
{
    for (int i = 0; i < 4; i++) {
        CA("assets/slot.png", 0, (V2F){3, 3}, &glob->game->inv.slot[i]);
        SP((V2F){0, 400 + 80 *i}, &glob->game->inv.slot[i]);
        CA("assets/slect.png", 0, (V2F){3, 3}, &GGII[i].curseur);
        SP((V2F){0, 400 + 80 *i}, &glob->game->inv.items[i].curseur);
        glob->game->inv.items[i].id = 0;
        glob->game->inv.items[i].here = false;
    }
    glob->game->inv.items[0].here = true;
    glob->game->inv.index = 0;
}

static void move_cursor_left(global_t *glob)
{
    if (glob->game->inv.index == 0)
        return;
    else
        glob->game->inv.index--;
}

static void move_cursor_right(global_t *glob)
{
    if (glob->game->inv.index == 4)
        return;
    else
        glob->game->inv.index++;
}

void draw_inv(global_t *glob)
{
    for (int i = 0; i < 4; i++)
        DRAW(WINDOW, glob->game->inv.slot[i].sprite, NULL);
    DRAW(WINDOW, GGII[glob->game->inv.index].curseur.sprite, NULL);
}

void handle_inv2(global_t *glob, sfEvent evt)
{
    if (EKC == sfKeyLeft || evt.key.code == glob->binding.back - 2) {
            move_cursor_left(glob);
        } else if (EKC == sfKeyRight || evt.key.code == glob->binding.next - 2)
            move_cursor_right(glob);
        if (evt.key.code == glob->binding.compt1 - 2)
            glob->game->inv.index = 0;
        if (evt.key.code == glob->binding.compt2 - 2)
            glob->game->inv.index = 1;
        if (evt.key.code == glob->binding.compt3 - 2)
            glob->game->inv.index = 2;
        if (evt.key.code == glob->binding.compt4 - 2)
            glob->game->inv.index = 3;
}

void handle_inv(global_t *glob, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed) {
        handle_inv2(glob, evt);
    }
}
