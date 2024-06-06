/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include "my.h"
#define V1 "assets/settings/Video.png"
#define V2 "assets/settings/video.png"
#define G1 "assets/settings/Gameplay.png"
#define G2 "assets/settings/gameplay.png"
#define SO1 "assets/settings/Sound.png"
#define SO2 "assets/settings/sound.png"
#define K1 "assets/settings/Keybindings.png"
#define K2 "assets/settings/keybindings.png"
#define S1 "assets/settings/Bind/select.png"
#define S2 "assets/settings/Bind/Select.png"
#define OP "assets/settings/Option1.png"
#define B1 "assets/settings/back.png"
#define B2 "assets/settings/Back.png"
#define R1 "assets/settings/reset.png"
#define R2 "assets/settings/Reset.png"
#define BUT glob->settings->but

void init_bind(global_t *glob)
{
    glob->binding.forward = sfKeyZ + 2;
    glob->binding.backward = sfKeyS + 2;
    glob->binding.left = sfKeyQ + 2;
    glob->binding.right = sfKeyD + 2;
    glob->binding.melee = sfMouseLeft;
    glob->binding.secondary = sfMouseRight;
    glob->binding.compt1 = sfKeyNum1 + 2;
    glob->binding.compt2 = sfKeyNum2 + 2;
    glob->binding.compt3 = sfKeyNum3 + 2;
    glob->binding.compt4 = sfKeyNum4 + 2;
    glob->binding.inventory = sfKeyE + 2;
    glob->binding.screen = sfKeyF12 + 2;
    glob->binding.next = sfKeyRight + 2;
    glob->binding.back = sfKeyLeft + 2;
    glob->settings->draw = &video;
    glob->settings->m = 100;
    glob->settings->e = 100;
    glob->settings->s = 100;
    glob->difficulty = 1;
}

static void init_but(global_t *glob)
{
    init_select(glob);
    add_button(SE, PT(S1, S2, S2), (V2F){1000, 320}, (V2F){0.4, 0.4});
    set_up_rec(SE, rec((V2F){1000, 320}, (V2F){1235, 382}, glob), &bindings);
    add_button(SE, PT(S1, S2, S2), (V2F){1000, 385}, (V2F){0.4, 0.4});
    set_up_rec(SE, rec((V2F){1000, 386}, (V2F){1235, 445}, glob), &bindings);
    add_button(SE, PT(S1, S2, S2), (V2F){1000, 450}, (V2F){0.4, 0.4});
    set_up_rec(SE, rec((V2F){1000, 451}, (V2F){1235, 512}, glob), &bindings);
    add_button(SE, PT(S1, S2, S2), (V2F){1000, 515}, (V2F){0.4, 0.4});
    set_up_rec(SE, rec((V2F){1000, 516}, (V2F){1235, 590}, glob), &bindings);
    add_button(BUT, PT(V1, V2, V2), (V2F){100, 150}, (V2F){0.6, 0.6});
    set_up_rec(BUT, rec((V2F){101, 150}, (V2F){455, 266}, glob), &video);
    add_button(BUT, PT(G1, G2, G2), (V2F){550, 150}, (V2F){0.6, 0.6});
    set_up_rec(BUT, rec((V2F){551, 150}, (V2F){904, 266}, glob), &gameplay);
    add_button(BUT, PT(SO1, SO2, SO2), (V2F){1000, 150}, (V2F){0.6, 0.6});
    set_up_rec(BUT, rec((V2F){1002, 150}, (V2F){1359, 266}, glob), &sound);
    add_button(BUT, PT(K1, K2, K2), (V2F){1450, 150}, (V2F){0.6, 0.6});
    set_up_rec(BUT, rec((V2F){1441, 150}, (V2F){1808, 266}, glob), &bindings);
}

void init_setting(global_t *glob)
{
    glob->settings = malloc(sizeof(setting_t));
    glob->settings->background = malloc(sizeof(sprites_t));
    glob->settings->but = malloc(sizeof(button_t));
    glob->settings->select = malloc(sizeof(button_t));
    glob->settings->res = malloc(sizeof(button_t));
    glob->settings->but->list = NULL;
    glob->settings->select->list = NULL;
    glob->settings->res->list = NULL;
    glob->settings->but->draw = &draw_button;
    glob->settings->select->draw = &draw_button;
    glob->settings->res->draw = &draw_button;
    glob->settings->but->destroy = &destroy_button;
    glob->settings->select->destroy = &destroy_button;
    glob->settings->res->destroy = &destroy_button;
    glob->settings->b = 0;
    create_animation(OP, 0, (V2F){1, 1}, glob->settings->background);
    add_button(BUT, PT(B1, B2, B2), (V2F){1760, 940}, (V2F){0.3, 0.3});
    set_up_rec(BUT, rec((V2F){1760, 940}, (V2F){1815, 996}, glob), &back);
    add_button(BUT, PT(R1, R2, R2), (V2F){1830, 940}, (V2F){0.3, 0.3});
    set_up_rec(BUT, rec((V2F){1830, 940}, (V2F){1887, 997}, glob), &init_bind);
    init_but(glob);
    init_gameplay(glob);
    init_binding(glob);
    init_video(glob);
    init_sound(glob);
}

static int split_handle(global_t *glob, sfEvent event, list_but_t *t)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (sfFloatRect_contains(&(t->button->rec), m.x, m.y)) {
        if (t->current == STANDBY)
            sfSound_play(glob->bitbox.act);
        if (event.type == sfEvtMouseButtonReleased) {
            glob->settings->draw = t->button->action;
            return (ACTIVE);
        } else {
            return (HOVER);
        }
    } else
        return (STANDBY);
}

void handle_setting_events(global_t *glob)
{
    list_but_t *t = glob->settings->but->list;
    list_but_t *s = glob->settings->select->list;
    list_but_t *r = glob->settings->res->list;
    list_but_t *g = glob->settings->difficulty->list;
    sfEvent event;

    while (POLLEVENT(WINDOW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        for (; t; t = t->next)
            t->current = split_handle(glob, event, t);
        for (int i = 0; s && glob->settings->b == 4; i++) {
            s->current = split_handle_binding(glob, event, s, i);
            s = s->next;
        }
        for (; r && glob->settings->b == 1; r = r->next)
            r->current = split_handle_video(glob, event, r);
        for (; g && glob->settings->b == 2; g = g->next)
            g->current = split_handle_gameplay(glob, event, g);
        handle_sound(glob, event);
        check_screen(glob, event);
    }
}

void update_setting(global_t *glob)
{
    (void)glob;
}

void draw_setting(global_t *glob)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    DRAW(WINDOW, glob->settings->background->sprite, NULL);
    glob->settings->but->draw(glob, glob->settings->but);
    glob->settings->draw(glob);
    DRAW(WINDOW, glob->cursor.sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void destroy_setting(global_t *glob)
{
    for (int i = 0; i < 14; i++) {
        if (i < 3) {
            sfSprite_destroy(glob->settings->bar[i].sprite);
            sfSprite_destroy(glob->settings->cursor[i].sprite);
            sfSprite_destroy(glob->settings->sound[i].sprite);
            sfTexture_destroy(glob->settings->bar[i].texture);
            sfTexture_destroy(glob->settings->cursor[i].texture);
            sfTexture_destroy(glob->settings->sound[i].texture);
        } else if (i < 4) {
            sfSprite_destroy(glob->settings->vid[i].sprite);
            sfTexture_destroy(glob->settings->vid[i].texture);
        }
        sfSprite_destroy(glob->settings->bind[i].sprite);
        sfTexture_destroy(glob->settings->bind[i].texture);
    }
    sfSprite_destroy(glob->settings->background->sprite);
    sfSprite_destroy(glob->settings->choose_difficulty->sprite);
    sfSprite_destroy(glob->settings->bull.sprite);
    sfTexture_destroy(glob->settings->bull.texture);
    sfTexture_destroy(glob->settings->background->texture);
    sfTexture_destroy(glob->settings->choose_difficulty->texture);
    glob->settings->but->destroy(glob->settings->but);
    glob->settings->select->destroy(glob->settings->select);
    glob->settings->difficulty->destroy(glob->settings->difficulty);
    free(glob->settings->background);
    free(glob->settings->choose_difficulty);
    free(glob->settings);
}

