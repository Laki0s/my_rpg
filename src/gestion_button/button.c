/*
** EPITECH PROJECT, 2024
** paint
** File description:
** button
*/

#include "my.h"

char **paths_to_tab(char *standby, char *hover, char *active)
{
    char **tab = malloc(sizeof(char *) * 4);

    tab[0] = malloc(sizeof(char) * (my_strlen(standby) + 1));
    my_strcpy(tab[0], standby);
    tab[1] = malloc(sizeof(char) * (my_strlen(hover) + 1));
    my_strcpy(tab[1], hover);
    tab[2] = malloc(sizeof(char) * (my_strlen(active) + 1));
    my_strcpy(tab[2], active);
    tab[3] = NULL;
    return tab;
}

static list_but_t *new_but(char **paths, sfVector2f pos, sfVector2f scale)
{
    list_but_t *new_node = malloc(sizeof(list_but_t));

    new_node->current = STANDBY;
    new_node->button = malloc(sizeof(sprite_t));
    new_node->button->sprite = sfSprite_create();
    new_node->button->pos = (sfVector2f){pos.x, pos.y};
    new_node->button->standby = TCFF(paths[0], NULL);
    new_node->button->hover = TCFF(paths[1], NULL);
    new_node->button->active = TCFF(paths[2], NULL);
    new_node->button->scale = (sfVector2f){scale.x, scale.y};
    sfSprite_setScale(new_node->button->sprite, new_node->button->scale);
    sfSprite_setPosition(new_node->button->sprite, new_node->button->pos);
    new_node->next = NULL;
    for (int i = 0; paths[i]; i++)
        free(paths[i]);
    free(paths);
    return new_node;
}


void set_up_rec(button_t *but, sfFloatRect rec, void (*action)(global_t *))
{
    list_but_t *t = but->list;

    if (t == NULL) {
        return;
    } else {
        while (t->next)
            t = t->next;
        t->button->rec = rec;
        t->button->action = action;
    }
}

void add_button(button_t *but, char **paths, sfVector2f pos, sfVector2f scale)
{
    list_but_t *t = but->list;

    if (t == NULL) {
        but->list = new_but(paths, pos, scale);
    } else {
        while (t->next)
            t = t->next;
        t->next = new_but(paths, pos, scale);
    }
}

void draw_button(global_t *glob, button_t *but)
{
    list_but_t *t = but->list;

    if (t == NULL) {
        return;
    }
    while (t) {
        if (t->current == STANDBY)
            sfSprite_setTexture(t->button->sprite, t->button->standby, sfTrue);
        if (t->current == HOVER)
            sfSprite_setTexture(t->button->sprite, t->button->hover, sfTrue);
        if (t->current == ACTIVE)
            sfSprite_setTexture(t->button->sprite, t->button->active, sfTrue);
        sfRenderWindow_drawSprite(WINDOW, t->button->sprite, NULL);
        t = t->next;
    }
}

void destroy_button(button_t *but)
{
    list_but_t *t = but->list;
    list_but_t *s = NULL;

    while (t->next) {
        sfTexture_destroy(t->button->standby);
        sfTexture_destroy(t->button->hover);
        sfTexture_destroy(t->button->active);
        sfSprite_destroy(t->button->sprite);
        s = t;
        t = t->next;
        free(s->button);
        free(s);
    }
    free(but);
}


