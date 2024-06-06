/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** action
*/

#include "my.h"
#define R8 "assets/settings/video/800.png"
#define R6 "assets/settings/video/600.png"
#define R3 "assets/settings/video/1366.png"
#define R7 "assets/settings/video/768.png"
#define R9 "assets/settings/video/1920.png"
#define R0 "assets/settings/video/1080.png"
#define R2 "assets/settings/video/2560.png"
#define R4 "assets/settings/video/1440.png"
#define OK "assets/settings/video/V.png"
#define OK2 "assets/settings/video/v.png"
#define FO "assets/settings/video/X.png"
#define FO2 "assets/settings/video/x.png"
#define M1 "assets/settings/video/144.png"
#define M2 "assets/settings/video/144V.png"
#define A1 "assets/settings/video/60.png"
#define A2 "assets/settings/video/60V.png"
#define L1 "assets/settings/video/30.png"
#define L2 "assets/settings/video/30V.png"
#define RESOLUTION "assets/settings/video/resolution.png"
#define SCREEN "assets/settings/video/fullscreen.png"
#define VSYNC "assets/settings/video/V-Sync.png"
#define FPS "assets/settings/video/FPS.png"
#define RES glob->settings->res

void init_video(global_t *glob)
{
    CA(RESOLUTION, 0, (V2F){0.5, 0.5}, &(glob->settings->vid[0]));
    CA(SCREEN, 0, (V2F){0.5, 0.5}, &(glob->settings->vid[1]));
    CA(VSYNC, 0, (V2F){0.5, 0.5}, &(glob->settings->vid[2]));
    CA(FPS, 0, (V2F){0.5, 0.5}, &(glob->settings->vid[3]));
    add_button(RES, PT(R8, R6, R6), (VF){420, 330}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){420, 330}, (VF){655, 403}, glob), &set_screen_little);
    add_button(RES, PT(R3, R7, R7), (VF){720, 330}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){720, 330}, (VF){954, 403}, glob), &set_screen_average);
    add_button(RES, PT(R9, R0, R0), (VF){1020, 330}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){1020, 330}, (VF){1256, 403}, glob), &set_screen_standar);
    add_button(RES, PT(R2, R4, R4), (VF){1320, 330}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){1320, 330}, (VF){1555, 403}, glob), &set_screen_big);
    add_button(RES, PT(OK, OK2, OK2), (VF){450, 480}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){450, 479}, (VF){527, 557}, glob), &set_fullscreen);
    add_button(RES, PT(FO, FO2, FO2), (VF){580, 480}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){580, 480}, (VF){657, 556}, glob), &set_windowmode);
    add_button(RES, PT(OK, OK2, OK2), (VF){450, 630}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){450, 630}, (VF){527, 707}, glob), &Vsync_a);
    add_button(RES, PT(FO, FO2, FO2), (VF){580, 630}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){580, 630}, (VF){657, 707}, glob), &Vsync_f);
    add_button(RES, PT(M1, M2, M2), (VF){420, 780}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){420, 780}, (VF){655, 853}, glob), &fps_max);
    add_button(RES, PT(A1, A2, A2), (VF){720, 780}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){720, 780}, (VF){954, 853}, glob), &fps_average);
    add_button(RES, PT(L1, L2, L2), (VF){1020, 780}, (VF){0.4, 0.4});
    set_up_rec(RES, rec((VF){1020, 780}, (VF){1256, 853}, glob), &fps_low);
}

int split_handle_video(global_t *glob, sfEvent event, list_but_t *t)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (sfFloatRect_contains(&(t->button->rec), m.x, m.y)) {
        if (t->current == STANDBY)
            sfSound_play(glob->bitbox.s1);
        if (event.type == sfEvtMouseButtonReleased) {
            t->button->action(glob);
            return (ACTIVE);
        } else {
            return (HOVER);
        }
    } else
        return (STANDBY);
}

void video(global_t *glob)
{
    glob->settings->b = 1;
    for (int i = 0; i < 4; i++) {
        SP((V2F){100, 320 + 150 * i}, &(glob->settings->vid[i]));
        DRAW(WINDOW, glob->settings->vid[i].sprite, NULL);
    }
    RES->draw(glob, glob->settings->res);
}