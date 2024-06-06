/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** video2
*/

#include "my.h"

void set_screen_little(global_t *glob)
{
    sfVector2u resolution = {800, 600};

    sfRenderWindow_setSize(WINDOW, resolution);
    sfView_setSize(glob->camera, (V2F){resolution.x, resolution.x});
}

void set_screen_average(global_t *glob)
{
    sfVector2u resolution = {1366, 768};

    sfRenderWindow_setSize(WINDOW, resolution);
    sfView_setSize(glob->camera, (V2F){resolution.x, resolution.x});
}

void set_screen_standar(global_t *glob)
{
    sfVector2u resolution = {1920, 1080};

    sfRenderWindow_setSize(WINDOW, resolution);
    sfView_setSize(glob->camera, (V2F){resolution.x, resolution.x});
}

void set_screen_big(global_t *glob)
{
    sfVector2u resolution = {2560, 1440};

    sfRenderWindow_setSize(WINDOW, resolution);
    sfView_setSize(glob->camera, (V2F){resolution.x, resolution.x});
}

void set_fullscreen(global_t *glob)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfImage* icon = sfImage_createFromFile("assets/icon.png");

    sfRenderWindow_destroy(WINDOW);
    WINDOW = sfRenderWindow_create(mode, "RPG", sfClose | sfFullscreen, NULL);
    sfRenderWindow_setIcon(WINDOW, sfImage_getSize(icon).x,
        sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
    sfView_setSize(glob->camera, (V2F){mode.width, mode.height});
    sfRenderWindow_setFramerateLimit(WINDOW, 144);
    sfRenderWindow_setMouseCursorVisible(WINDOW, false);
    glob->isfullscreen = true;
    sfImage_destroy(icon);
}

void set_windowmode(global_t *glob)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfImage* icon = sfImage_createFromFile("assets/icon.png");

    sfRenderWindow_destroy(WINDOW);
    WINDOW = SRWC(mode, "My RPG", sfClose, NULL);
    sfRenderWindow_setIcon(WINDOW, sfImage_getSize(icon).x,
        sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
    sfView_setSize(glob->camera, (V2F){mode.width, mode.height});
    sfRenderWindow_setFramerateLimit(WINDOW, 144);
    sfRenderWindow_setMouseCursorVisible(WINDOW, false);
    glob->isfullscreen = false;
    sfImage_destroy(icon);
}

void Vsync_a(global_t *glob)
{
    sfRenderWindow_setVerticalSyncEnabled(WINDOW, sfTrue);
}

void Vsync_f(global_t *glob)
{
    sfRenderWindow_setVerticalSyncEnabled(WINDOW, sfFalse);
}

void fps_max(global_t *glob)
{
    sfRenderWindow_setFramerateLimit(WINDOW, 144);
}

void fps_average(global_t *glob)
{
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
}

void fps_low(global_t *glob)
{
    sfRenderWindow_setFramerateLimit(WINDOW, 30);
}
