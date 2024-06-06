/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include "my.h"

static void init_characters(global_t *glob)
{
    create_animation("assets/characters/isaac.png", 0, (V2F){1.5, 1.5}, &glob->hub->caracter[0]);
    sprite_position((V2F){265, 360}, &glob->hub->caracter[0]);
    create_animation("assets/characters/eden.png", 0, (V2F){1.5, 1.5}, &glob->hub->caracter[1]);
    sprite_position((V2F){817, 368}, &glob->hub->caracter[1]);
    create_animation("assets/characters/cain.png", 0, (V2F){1.5, 1.5}, &glob->hub->caracter[2]);
    sprite_position((V2F){1380, 370}, &glob->hub->caracter[2]);
    create_animation("assets/characters/bethany.png", 0, (V2F){1.5, 1.5}, &glob->hub->caracter[3]);
    sprite_position((V2F){265, 670}, &glob->hub->caracter[3]);
    create_animation("assets/characters/samsun.png", 0, (V2F){1.5, 1.5}, &glob->hub->caracter[4]);
    sprite_position((V2F){825, 670}, &glob->hub->caracter[4]);
    create_animation("assets/characters/lazarus.png", 0, (V2F){1.5, 1.5}, &glob->hub->caracter[5]);
    sprite_position((V2F){1380, 670}, &glob->hub->caracter[5]);
}

static void init_cadre(global_t *glob)
{
    add_button(glob->hub->but, paths_to_tab("assets/cadres.png", "assets/cadres.png", "assets/cadres.png"), (V2F){260, 330}, (V2F){1.2, 1.2});
    set_up_rec(glob->hub->but, rec((V2F){260, 385}, (V2F){475, 540}, glob), NULL);
    add_button(glob->hub->but, paths_to_tab("assets/cadres.png", "assets/cadres.png", "assets/cadres.png"), (V2F){810, 330}, (V2F){1.2, 1.2});
    set_up_rec(glob->hub->but, rec((V2F){815, 385}, (V2F){1027, 540}, glob), NULL);
    add_button(glob->hub->but, paths_to_tab("assets/cadres.png", "assets/cadres.png", "assets/cadres.png"), (V2F){1360, 330}, (V2F){1.2, 1.2});
    set_up_rec(glob->hub->but, rec((V2F){1366, 385}, (V2F){1576, 540}, glob), NULL);
    add_button(glob->hub->but, paths_to_tab("assets/cadres.png", "assets/cadres.png", "assets/cadres.png"), (V2F){260, 630}, (V2F){1.2, 1.2});
    set_up_rec(glob->hub->but, rec((V2F){260, 685}, (V2F){475, 840}, glob), NULL);
    add_button(glob->hub->but, paths_to_tab("assets/cadres.png", "assets/cadres.png", "assets/cadres.png"), (V2F){810, 630}, (V2F){1.2, 1.2});
    set_up_rec(glob->hub->but, rec((V2F){815, 641}, (V2F){1027, 840}, glob), NULL);
    add_button(glob->hub->but, paths_to_tab("assets/cadres.png", "assets/cadres.png", "assets/cadres.png"), (V2F){1360, 630}, (V2F){1.2, 1.2});
    set_up_rec(glob->hub->but, rec((V2F){1366, 641}, (V2F){1576, 840}, glob), NULL);
    add_button(glob->hub->but, paths_to_tab("assets/name.png", "assets/name.png", "assets/name.png"), (V2F){260, 330}, (V2F){1.2, 1.2});
    add_button(glob->hub->but, paths_to_tab("assets/name.png", "assets/name.png", "assets/name.png"), (V2F){810, 330}, (V2F){1.2, 1.2});
    add_button(glob->hub->but, paths_to_tab("assets/name.png", "assets/name.png", "assets/name.png"), (V2F){1360, 330}, (V2F){1.2, 1.2});
    add_button(glob->hub->but, paths_to_tab("assets/name.png", "assets/name.png", "assets/name.png"), (V2F){260, 630}, (V2F){1.2, 1.2});
    add_button(glob->hub->but, paths_to_tab("assets/name.png", "assets/name.png", "assets/name.png"), (V2F){810, 630}, (V2F){1.2, 1.2});
    add_button(glob->hub->but, paths_to_tab("assets/name.png", "assets/name.png", "assets/name.png"), (V2F){1360, 630}, (V2F){1.2, 1.2});
}

void init_lobby(global_t *glob)
{
    glob->hub = malloc(sizeof(lobby_t));
    glob->hub->background = malloc(sizeof(sprites_t));
    glob->hub->cadre = malloc(sizeof(sprites_t));
    glob->hub->but = malloc(sizeof(button_t));
    glob->hub->but->list = NULL;
    glob->hub->but->draw = &draw_button;
    glob->hub->but->destroy = &destroy_button;
    add_button(glob->hub->but, paths_to_tab("assets/GUI/home.png", "assets/GUI/Home.png", "assets/GUI/Home.png"), (sfVector2f){20, 10}, (sfVector2f){0.4, 0.4});
    set_up_rec(glob->hub->but, rec((sfVector2f){20, 10}, (sfVector2f){100, 90}, glob), &home);
    add_button(glob->hub->but, paths_to_tab("assets/GUI/back.png", "assets/GUI/Back.png", "assets/GUI/Back.png"), (sfVector2f){120, 10}, (sfVector2f){0.4, 0.4});
    set_up_rec(glob->hub->but, rec((sfVector2f){120, 10}, (sfVector2f){200, 90}, glob), &back);
    add_button(glob->hub->but, paths_to_tab("assets/GUI/settings.png", "assets/GUI/Settings.png", "assets/GUI/Settings.png"), (sfVector2f){220, 10}, (sfVector2f){0.4, 0.4});
    set_up_rec(glob->hub->but, rec((sfVector2f){220, 10}, (sfVector2f){300, 90}, glob), &setting);
    create_animation("assets/background/back.png", 0, (V2F){3.1, 2.39}, glob->hub->background);
    create_animation("assets/Floral.png", 0, (V2F){0.8, 0.44}, glob->hub->cadre);
    sprite_position((V2F){600, 0}, glob->hub->cadre);
    init_characters(glob);
    init_cadre(glob);
    glob->hub->choice = false;
    glob->hub->a = 0;
    glob->hub->rec = rectancle((V2F){1920, 1080}, (sfVector2f){0, 0}, sfColor_fromRGBA(0, 0, 0, 0));
}

static int split_handle(global_t *glob, sfEvent event, list_but_t *t, int i)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (sfFloatRect_contains(&(t->button->rec), m.x, m.y)) {
        if (t->current == STANDBY)
            sfSound_play(glob->bitbox.s1);
        if (event.type == sfEvtMouseButtonReleased && i < 3) {
            t->button->action(glob);
            return (ACTIVE);
        } else if (event.type == sfEvtMouseButtonReleased) {
            glob->hub->choice = true;
            glob->charac.class = i - 3;
            return (ACTIVE);
        } else {
            return (HOVER);
        }
    } else
        return (STANDBY);
}

void handle_lobby_events(global_t *glob)
{
    list_but_t *t = glob->hub->but->list;
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        for (int i = 0; t; i++) {
            t->current = split_handle(glob, evt, t, i);
            t = t->next;
        }
        check_screen(glob, evt);
    }
}

static void create_new_save(global_t *glob, int i)
{
    char filename[1024];
    FILE *file;

    snprintf(filename, sizeof(filename), "save/backup%d", (i + 1));
    file = fopen(filename, "w");
    if (file != NULL) {
        glob->backup[i].exist = true;
        glob->backup[i].lvl = 1;
        glob->backup[i].class = glob->charac.class;
        glob->backup[i].seconde = 0;
        glob->backup[i].quest = 0;
        glob->backup[i].hp = 3;
        glob->backup[i].speed = 8;
        glob->backup[i].fire_rate = 1.58;
        glob->backup[i].damage = 1;
        glob->backup[i].range = 50 + 500;
        glob->backup[i].shot_speed = 3;
        glob->backup[i].death = 0;
        fprintf(file, "Class=%d\n", glob->charac.class);
        fprintf(file, "Lvl=%d\n", glob->charac.lvl);
        fprintf(file, "Hp=%f\n", glob->charac.hp);
        fprintf(file, "Speed=%f\n", glob->charac.speed);
        fprintf(file, "FireRate=%f\n", glob->charac.fire_rate);
        fprintf(file, "Damage=%f\n", glob->charac.damage);
        fprintf(file, "Range=%d\n", glob->charac.range);
        fprintf(file, "ShotSpeed=%d\n", glob->charac.shot_speed);
        fprintf(file, "Quest=%.2f\n", glob->charac.quest);
        fprintf(file, "Timer=%d\n", glob->charac.timer);
        fprintf(file, "Death=%d\n", glob->charac.death);
        if (glob->charac.inv == NULL)
            fprintf(file, "Inventaire=none\n");
        for (int i = 0; glob->charac.inv != NULL && glob->charac.inv[i]; i++)
            fprintf(file, "Inventaire=%d\n", glob->charac.inv[i]);
        fclose(file);
    }
}

void update_lobby(global_t *glob)
{
    int i = 0;

    for (; i < 3; i++)
        if (glob->backup[i].exist == false)
            break;
    if (glob->hub->choice == true) {
        glob->hub->a += 1;
        sfRectangleShape_setFillColor(glob->hub->rec, sfColor_fromRGBA(0, 0, 0, glob->hub->a));
        if (glob->hub->a >= 255 && i < 3) {
            glob->timer = 0;
            create_new_save(glob, i);
            sfMusic_pause(glob->bitbox.ost);
            glob->current_scene = GAME;
        }
    }
}

static void text(global_t *glob, char *str, int scale, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, glob->font);
    sfText_setCharacterSize(text, scale);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfText_setOutlineColor(text, sfColor_fromRGB(200, 180, 220));
    sfText_setOutlineThickness(text, 2);
    sfRenderWindow_drawText(WINDOW, text, NULL);
    sfText_destroy(text);
}

static void draw_name_characters(global_t *glob)
{
    text(glob, "Isaac", 50, (V2F){330, 330});
    text(glob, "Eden", 50, (V2F){880, 330});
    text(glob, "Cain", 50, (V2F){1440, 330});
    text(glob, "Bethany", 48, (V2F){310, 630});
    text(glob, "Samsun", 50, (V2F){860, 630});
    text(glob, "Lazarus", 50, (V2F){1420, 630});
}

void draw_lobby(global_t *glob)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    DRAW(WINDOW, glob->hub->background->sprite, NULL);
    DRAW(WINDOW, glob->hub->cadre->sprite, NULL);
    glob->hub->but->draw(glob, glob->hub->but);
    for (int i = 0; i < 6; i++) {
        DRAW(WINDOW, glob->hub->caracter[i].sprite, NULL);
    }
    text(glob, "Select your", 100, (V2F){755, 20});
    text(glob, "Caracters", 100, (V2F){760, 110});
    draw_name_characters(glob);
    if (glob->hub->choice == true)
        sfRenderWindow_drawRectangleShape(WINDOW, glob->hub->rec, NULL);
    DRAW(WINDOW, glob->cursor.sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void destroy_lobby(global_t *glob)
{
    free(glob->hub);
}
