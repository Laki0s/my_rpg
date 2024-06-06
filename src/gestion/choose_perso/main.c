/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include "my.h"

static void init_others(global_t *glob)
{
    add_button(glob->perso->but, paths_to_tab("assets/GUI/home.png", "assets/GUI/Home.png", "assets/GUI/Home.png"), (sfVector2f){1400, 900}, (sfVector2f){0.5, 0.5});
    set_up_rec(glob->perso->but, rec((sfVector2f){1400, 900}, (sfVector2f){1500, 1000}, glob), &home);
    add_button(glob->perso->but, paths_to_tab("assets/GUI/x.png", "assets/GUI/X.png", "assets/GUI/X.png"), (sfVector2f){1530, 900}, (sfVector2f){0.5, 0.5});
    set_up_rec(glob->perso->but, rec((sfVector2f){1530, 900}, (sfVector2f){1630, 1000}, glob), &leave);
    add_button(glob->perso->but, paths_to_tab("assets/GUI/audio.png", "assets/GUI/Audio.png", "assets/GUI/Audio.png"), (sfVector2f){1660, 900}, (sfVector2f){0.5, 0.5});
    set_up_rec(glob->perso->but, rec((sfVector2f){1660, 900}, (sfVector2f){1760, 1000}, glob), &sound_off);
    add_button(glob->perso->but, paths_to_tab("assets/GUI/settings.png", "assets/GUI/Settings.png", "assets/GUI/Settings.png"), (sfVector2f){1790, 900}, (sfVector2f){0.5, 0.5});
    set_up_rec(glob->perso->but, rec((sfVector2f){1790, 900}, (sfVector2f){1890, 1000}, glob), &setting);
    create_animation("assets/characters/isaac.png", 0, (V2F){2, 2}, &glob->perso->character[0]);
    create_animation("assets/characters/eden.png", 0, (V2F){2, 2}, &glob->perso->character[1]);
    create_animation("assets/characters/cain.png", 0, (V2F){2, 2}, &glob->perso->character[2]);
    create_animation("assets/characters/bethany.png", 0, (V2F){2, 2}, &glob->perso->character[3]);
    create_animation("assets/characters/samsun.png", 0, (V2F){2, 2}, &glob->perso->character[4]);
    create_animation("assets/characters/lazarus.png", 0, (V2F){2, 2}, &glob->perso->character[5]);
}

void init_new(global_t *glob)
{
    glob->perso = malloc(sizeof(new_t));
    glob->perso->background = malloc(sizeof(sprites_t));
    glob->perso->but = malloc(sizeof(button_t));
    glob->perso->del = malloc(sizeof(button_t));
    glob->perso->but->list = NULL;
    glob->perso->but->draw = &draw_button;
    glob->perso->but->destroy = &destroy_button;
    glob->perso->del->list = NULL;
    glob->perso->del->draw = &draw_button;
    glob->perso->del->destroy = &destroy_button;
    glob->perso->a = 255;
    create_animation("assets/background/nigth.png", 0, (V2F){6.28, 4.32}, glob->perso->background);
    for (int i = 0; i < 3; i++) {
        create_animation("assets/cadre.png", 0, (V2F){0.4, 0.3}, &glob->perso->cadre[i]);
        add_button(glob->perso->but, paths_to_tab("assets/GUI/X.png", "assets/GUI/x.png", "assets/GUI/x.png"), (sfVector2f){1225, 110 + 300 * i}, (sfVector2f){0.2, 0.2});
        set_up_rec(glob->perso->but, rec((sfVector2f){1225, 110 + 300 * i}, (sfVector2f){1265, 150 + 300 * i}, glob), &delete_backup);
    }
    init_others(glob);
    for (int i = 0; i < 3; i++) {
        add_button(glob->perso->del, paths_to_tab("assets/choose.png", "assets/choose.png", "assets/choose.png"), (sfVector2f){600, 100 + 300 * i}, (sfVector2f){1, 1});
        set_up_rec(glob->perso->del, rec((sfVector2f){620, 151 + 300 * i}, (sfVector2f){1254, 335 + 300 * i}, glob), &lobby);
    }
}

static int split_handle(global_t *glob, sfEvent event, list_but_t *t, int i, bool a)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (sfFloatRect_contains(&(t->button->rec), m.x, m.y)) {
        if (t->current == STANDBY)
            sfSound_play(glob->bitbox.s1);
        if (event.type == sfEvtMouseButtonReleased && i < 3 && a == true) {
            glob->backup[i].exist = false;
            delete_backup(glob);
            return (ACTIVE);
        } else if (event.type == sfEvtMouseButtonReleased) {
            t->button->action(glob);
            return (ACTIVE);
        } else {
            return (HOVER);
        }
    } else
        return (STANDBY);
}

void handle_new_events(global_t *glob)
{
    list_but_t *t = glob->perso->but->list;
    list_but_t *d = glob->perso->del->list;
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        for (int i = 0; d; i++) {
            glob->perso->delete = i;
            d->current = split_handle(glob, evt, d, i, false);
            d = d->next;
        }
        for (int i = 0; t; i++) {
            if (i < 3 && glob->backup[i].exist == true)
               glob->perso->delete = i + 1;
            t->current = split_handle(glob, evt, t, i, true);
            t = t->next;
        }
        check_screen(glob, evt);
    }
}

void update_new(global_t *glob)
{
    if (glob->perso->a  > 5)
        glob->perso->a -= 2;
    else
        glob->perso->a = 255;
}

static void if_not_existing(global_t *glob, char *str, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, glob->font);
    sfText_setCharacterSize(text, 120);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfColor_fromRGBA(0, 0, 0, glob->perso->a));
    sfText_setFillColor(text, sfColor_fromRGBA(255, 255, 255, glob->perso->a));
    sfRenderWindow_drawText(WINDOW, text, NULL);
    sfText_destroy(text);
}

static void draw_name(global_t *glob, int i)
{
    if (glob->backup[i].class == 0)
        draw_text(glob, "Isaac", 30, (V2F){960, 150 + 300 * i});
    if (glob->backup[i].class == 1)
        draw_text(glob, "Eden", 30, (V2F){960, 150 + 300 * i});
    if (glob->backup[i].class == 2)
        draw_text(glob, "Cain", 30, (V2F){960, 150 + 300 * i});
    if (glob->backup[i].class == 3)
        draw_text(glob, "Bethany", 30, (V2F){960, 150 + 300 * i});
    if (glob->backup[i].class == 4)
        draw_text(glob, "Samsun", 30, (V2F){960, 150 + 300 * i});
    if (glob->backup[i].class == 5)
        draw_text(glob, "Lazarus", 30, (V2F){960, 150 + 300 * i});
    draw_text(glob, inttostr(glob->backup[i].lvl), 30, (V2F){970, 180 + 300 * i});
    draw_text(glob, "Stat", 30, (V2F){1080, 150 + 300 * i});
    draw_text(glob, "- HP :", 20, (V2F){1080, 185 + 300 * i});
    draw_text(glob, nbtostr(glob->backup[i].hp), 20, (V2F){1130, 185 + 300 * i});
    draw_text(glob, "- SPEED :", 20, (V2F){1080, 210 + 300 * i});
    draw_text(glob, inttostr(glob->backup[i].speed), 20, (V2F){1160, 210 + 300 * i});
    draw_text(glob, "- FIRE RATE :", 20, (V2F){1080, 230 + 300 * i});
    draw_text(glob, nbtostr(glob->backup[i].fire_rate), 20, (V2F){1190, 230 + 300 * i});
    draw_text(glob, "- DAMAGE :", 20, (V2F){1080, 250 + 300 * i});
    draw_text(glob, inttostr(glob->backup[i].damage), 20, (V2F){1180, 250 + 300 * i});
    draw_text(glob, "- RANGE :", 20, (V2F){1080, 270 + 300 * i});
    draw_text(glob, inttostr(glob->backup[i].range), 20, (V2F){1160, 270 + 300 * i});
    draw_text(glob, "- SHOT SPEED :", 20, (V2F){1080, 290 + 300 * i});
    draw_text(glob, inttostr(glob->backup[i].shot_speed), 20, (V2F){1195, 290 + 300 * i});
}

static void save_existing(global_t *glob, int i)
{
    char progressess[15];

    snprintf(progressess, sizeof(progressess), "%.2f%%", glob->backup[i].quest / 20 * 100);
    sprite_position((V2F){850, 140 + 300 * i}, &glob->perso->cadre[i]);
    sprite_position((V2F){590, 100 + 300 * i}, &glob->perso->character[glob->backup[i].class]);
    DRAW(WINDOW, glob->perso->cadre[i].sprite, NULL);
    DRAW(WINDOW, glob->perso->character[glob->backup[i].class].sprite, NULL);
    draw_text(glob, "Name :", 30, (V2F){880, 150 + 300 * i});
    draw_text(glob, "Level  :", 30, (V2F){880, 180 + 300 * i});
    draw_name(glob, i);
    draw_text(glob, "Progression :", 30, (V2F){880, 210 + 300 * i});
    draw_text(glob, progressess, 25, (V2F){1025, 215 + 300 * i});
    draw_text(glob, "Time :", 30, (V2F){880, 250 + 300 * i});
    draw_text(glob, inttostr(glob->backup[i].seconde), 30, (V2F){950, 254 + 300 * i});
}

void draw_new(global_t *glob)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    DRAW(WINDOW, glob->perso->background->sprite, NULL);
    glob->perso->del->draw(glob, glob->perso->del);
    glob->perso->but->draw(glob, glob->perso->but);
    for (int i = 0; i < 3; i++) {
        if (glob->backup[i].exist != true)
            if_not_existing(glob, "New game !", (V2F){700, 150 + 300 * i});
        else
            save_existing(glob, i);
    }
    DRAW(WINDOW, glob->cursor.sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void destroy_new(global_t *glob)
{
    sfSprite_destroy(glob->perso->background->sprite);
    sfTexture_destroy(glob->perso->background->texture);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(glob->perso->cadre[i].sprite);
        sfTexture_destroy(glob->perso->cadre[i].texture);
    }
    glob->perso->but->destroy(glob->perso->but);
    free(glob->perso->background);
    free(glob->perso);
}
