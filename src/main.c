/*
** EPITECH PROJECT, 2024
** paint
** File description:
** glob
*/

#include "my.h"

static void init_window(global_t *glob)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();

    WINDOW = SRWC(mode, "My RPG", sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 144);
    glob->isfullscreen = true;
    glob->camera = sfView_create();
    glob->clock = sfClock_create();
    glob->delta_time = 0;
    glob->timer = 0;
    sfImage* icon = sfImage_createFromFile("assets/new/logo.png");
    sfRenderWindow_setIcon(WINDOW, sfImage_getSize(icon).x, sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}

static void init_glob(global_t *glob)
{
    glob->current_scene = LOAD;
    glob->old = MENU;
    glob->scenes[LOAD] = (scene_t){&init_load, &handle_load_events,
        &update_load, &draw_load, &destroy_load};
    glob->scenes[MENU] = (scene_t){&init_menu, &handle_menu_events,
        &update_menu, &draw_menu, &destroy_menu};
    glob->scenes[LOBBY] = (scene_t){&init_lobby, &handle_lobby_events,
        &update_lobby, &draw_lobby, &destroy_lobby};
    glob->scenes[NEW] = (scene_t){&init_new, &handle_new_events,
        &update_new, &draw_new, &destroy_new};
    glob->scenes[INTRO] = (scene_t){&init_intro, &handle_intro_events,
        &update_intro, &draw_intro, &destroy_intro};
    glob->scenes[SETTING] = (scene_t){&init_setting, &handle_setting_events,
        &update_setting, &draw_setting, &destroy_setting};
    glob->scenes[GAME] = (scene_t){&init_game, &handle_game_events,
        &update_game, &draw_game, &destroy_game};
    glob->scenes[LOAD].init(glob);
    glob->scenes[MENU].init(glob);
    glob->scenes[LOBBY].init(glob);
    glob->scenes[NEW].init(glob);
    glob->scenes[INTRO].init(glob);
    glob->scenes[SETTING].init(glob);
    glob->scenes[GAME].init(glob);
}

static float get_delta_time(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float delta_time = time.microseconds / 1000000.0;

    sfClock_restart(clock);
    return (delta_time);
}

void destroy_glob(global_t *glob)
{
    glob->scenes[LOAD].destroy(glob);
    glob->scenes[MENU].destroy(glob);
    glob->scenes[LOBBY].destroy(glob);
    glob->scenes[INTRO].destroy(glob);
    glob->scenes[SETTING].destroy(glob);
    glob->scenes[GAME].destroy(glob);
    sfClock_destroy(glob->clock);
    sfFont_destroy(glob->font);
    sfMusic_destroy(glob->bitbox.ost);
    sfSound_destroy(glob->bitbox.act);
    sfSound_destroy(glob->bitbox.s1);
    sfSprite_destroy(glob->cursor.sprite);
    sfTexture_destroy(glob->cursor.texture);
    free(glob);
    exit(0);
}

static void init_character(global_t *glob)
{
    glob->charac.class = 0;
    glob->charac.lvl = 1;
    glob->charac.hp = 3;
    glob->charac.speed = 8;
    glob->charac.fire_rate = 1.58;
    glob->charac.damage = 1;
    glob->charac.range = 50 + 500;
    glob->charac.shot_speed = 1.89;
    glob->charac.quest = 0;
    glob->charac.timer = 0;
    glob->charac.death = 0;
    glob->charac.inv = NULL;
}

void init_other(global_t *glob)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile("assets/act.ogg");

    glob->bitbox.act = sfSound_create();
    sfSound_setBuffer(glob->bitbox.act, buffer);
    buffer = sfSoundBuffer_createFromFile("assets/s1.ogg");
    glob->bitbox.s1 = sfSound_create();
    sfSound_setBuffer(glob->bitbox.s1, buffer);
    sfRenderWindow_setMouseCursorVisible(WINDOW, false);
    create_animation("assets/cursor.png", 0, (sfVector2f){1, 1}, &(glob->cursor));
    glob->bitbox.ost = sfMusic_createFromFile("assets/ost.ogg");
    sfMusic_setLoop(glob->bitbox.ost, true);
    sfMusic_play(glob->bitbox.ost);
    glob->font = sfFont_createFromFile("assets/font.ttf");
    glob->difficulty = 1.0f;
    for (int i = 0; i < 3; i++)
        glob->backup[i].exist = false;
    init_character(glob);
    pthread_create(&glob->thread, NULL, get_backup, (void *)glob);
}

int main(void)
{
    global_t *glob = malloc(sizeof(global_t));
    sfVector2i m;

    init_window(glob);
    init_glob(glob);
    init_other(glob);
    while (sfRenderWindow_isOpen(WINDOW)) {
        glob->delta_time = get_delta_time(glob->clock);
        glob->timer += glob->delta_time;
        m = sfMouse_getPositionRenderWindow(WINDOW);
        sprite_position((sfVector2f){m.x, m.y}, &(glob->cursor));
        glob->scenes[glob->current_scene].handle_event(glob);
        glob->scenes[glob->current_scene].update(glob);
        glob->scenes[glob->current_scene].draw(glob);
    }
    return 0;
}
