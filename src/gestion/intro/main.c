/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include "my.h"

void init_intro(global_t *glob)
{
    glob->intro = malloc(sizeof(intro_t));
}

void handle_intro_events(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
    }
}

void update_intro(global_t *glob)
{
    (void)glob;
}

void draw_intro(global_t *glob)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    DRAW(WINDOW, glob->cursor.sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void destroy_intro(global_t *glob)
{
    free(glob->intro);
}
