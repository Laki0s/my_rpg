/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** sound
*/

#include "my.h"

void init_sound(global_t *glob)
{
    sfColor color;

    CA("assets/settings/effect.png", 0 , (V2F){0.6, 0.6}, &glob->settings->sound[0]);
    SP((V2F){230, 750}, &glob->settings->sound[0]);
    CA("assets/settings/music.png", 0 , (V2F){0.6, 0.6}, &glob->settings->sound[1]);
    SP((V2F){230, 550}, &glob->settings->sound[1]);
    CA("assets/settings/main.png", 0 , (V2F){0.6, 0.6}, &glob->settings->sound[2]);
    SP((V2F){230, 350}, &glob->settings->sound[2]);
    for (int i = 0; i < 3; i++) {
        CA("assets/settings/bg.png", 0 , (V2F){2, 2}, &glob->settings->bar[i]);
        CA("assets/settings/cursor.png", 0 , (V2F){0.29, 0.3}, &glob->settings->cursor[i]);
        color = sfSprite_getColor(glob->settings->cursor[i].sprite);
        color.a = 180;
        sfSprite_setColor(glob->settings->cursor[i].sprite, color);
        SP((V2F){700, 350 + 210 * i}, &glob->settings->bar[i]);
        SP((V2F){1100, 368 + 210 * i}, &glob->settings->cursor[i]);
    }
    glob->settings->m = 100;
    glob->settings->e = 100;
    glob->settings->s = 100;
}

static float sound_rate(float x)
{
    float x1 = 730;
    float x2 = 1180;
    float y1 = 0;
    float y2 = 100;
    float coef = (y2 - y1) / (x2 - x1);
    float origine = y1 - coef * x1;
    float taux = coef * x + origine;

    if (taux < 0)
        taux = 0;
    else if (taux > 100)
        taux = 100;
    return taux;
}

void restore_a_level(global_t *glob)
{
    sfMusic_setVolume(glob->bitbox.ost, (glob->settings->s / 100) * glob->settings->m);
    sfSound_setVolume(glob->bitbox.act, (glob->settings->e / 100) * glob->settings->m);
    sfSound_setVolume(glob->bitbox.s1, (glob->settings->e / 100) * glob->settings->m);
}

static void split_handle_sound(global_t *glob, int i)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (i == 1)
        glob->settings->m = sound_rate(m.x);
    if (i == 2)
        glob->settings->s = sound_rate(m.x);
    if (i == 3)
        glob->settings->e = sound_rate(m.x);
    if (m.x <= 700)
        m.x = 700;
    else if (m.x >= 1100)
        m.x = 1100;
    SP((V2F){m.x, glob->settings->cursor[i - 1].pos.y}, &glob->settings->cursor[i - 1]);
    restore_a_level(glob);
}

void handle_sound(global_t *glob, sfEvent evt)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);
    sfFloatRect main = rec((V2F){730, 372}, (V2F){1180, 422}, glob);
    sfFloatRect music = rec((V2F){730, 583}, (V2F){1180, 631}, glob);
    sfFloatRect effect = rec((V2F){730, 792}, (V2F){1180, 843}, glob);

    if (glob->settings->b != 3)
        return;
    if (sfFloatRect_contains(&main, m.x, m.y) &&
        evt.type == sfEvtMouseButtonPressed) {
        split_handle_sound(glob, 1);
        }
    if (sfFloatRect_contains(&music, m.x, m.y) &&
        evt.type == sfEvtMouseButtonPressed) {
        split_handle_sound(glob, 2);
        }
    if (sfFloatRect_contains(&effect, m.x, m.y) &&
        evt.type == sfEvtMouseButtonPressed) {
        split_handle_sound(glob, 3);
        }
}

void sound(global_t *glob)
{
    char buffer[1024];

    glob->settings->b = 3;
    for (int i = 0; i < 3; i++) {
        DRAW(WINDOW, glob->settings->bar[i].sprite, NULL);
        DRAW(WINDOW, glob->settings->cursor[i].sprite, NULL);
        DRAW(WINDOW, glob->settings->sound[i].sprite, NULL);
        if (i == 0)
            sprintf(buffer, "%d%%", glob->settings->m);
        if (i == 1)
            sprintf(buffer, "%.0f%%", glob->settings->s);
        if (i == 2)
            sprintf(buffer, "%.0f%%", glob->settings->e);
        draw_text(glob, buffer, 40, (V2F){920, 370 + 210 * i});
    }
}