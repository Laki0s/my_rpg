/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** action
*/

#include "my.h"

void next(global_t *glob)
{
    glob->old = glob->current_scene;
    glob->current_scene = GAME;
}

void intro(global_t *glob)
{
    glob->old = glob->current_scene;
    glob->current_scene = INTRO;
}

void back(global_t *glob)
{
    glob->current_scene = glob->old;
    glob->settings->draw = &video;
}

void check_screen(global_t *glob, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyF11) {
        if (glob->isfullscreen == true) {
            set_windowmode(glob);
        } else
            set_fullscreen(glob);
    }
    if (glob->current_scene == GAME &&
        evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape) {
        if (glob->game->option->active == true) {
            glob->game->option->active = false;
        } else
            glob->game->option->active = true;
    }
}

void setting(global_t *glob)
{
    glob->old = glob->current_scene;
    glob->current_scene = SETTING;
}

void home(global_t *glob)
{
    if (glob->current_scene == GAME)
        save(glob);
    glob->old = glob->current_scene;
    glob->current_scene = MENU;
}

void sound_off(global_t *glob)
{
    if (glob->settings->s == 0)
        glob->settings->s = 100;
    else
        glob->settings->s = 0;
    restore_a_level(glob);
}


void leave(global_t *glob)
{
    if (glob->current_scene == GAME)
        save(glob);
    sfRenderWindow_close(WINDOW);
    destroy_glob(glob);
}

void start(global_t *glob)
{
    pthread_join(glob->thread, NULL);
    glob->old = glob->current_scene;
    glob->current_scene = NEW;
}

void delete_backup(global_t *glob)
{
    char filename[1024];
    int nb = (glob->perso->delete);

    snprintf(filename, sizeof(filename), "save/backup%d", nb);
    remove(filename);
}

void game(global_t *glob)
{
    glob->old = glob->current_scene;
    glob->current_scene = GAME;
}

void lobby(global_t *glob)
{
    if (glob->backup[glob->perso->delete].exist == true) {
        glob->charac.class = glob->backup[glob->perso->delete].class;
        glob->charac.lvl = glob->backup[glob->perso->delete].lvl;
        glob->charac.hp = glob->backup[glob->perso->delete].hp;
        glob->charac.speed = glob->backup[glob->perso->delete].speed;
        glob->charac.fire_rate = glob->backup[glob->perso->delete].fire_rate;
        glob->charac.damage = glob->backup[glob->perso->delete].damage;
        glob->charac.range = glob->backup[glob->perso->delete].range;
        glob->charac.shot_speed = glob->backup[glob->perso->delete].shot_speed;
        glob->charac.quest = glob->backup[glob->perso->delete].quest;
        glob->charac.death = glob->backup[glob->perso->delete].death;
        glob->charac.timer = glob->backup[glob->perso->delete].seconde;
        glob->charac.inv = glob->backup[glob->perso->delete].inv;
        glob->old = glob->current_scene;
        glob->current_scene = GAME;
    } else {
        glob->old = glob->current_scene;
        glob->current_scene = LOBBY;
    }
}
