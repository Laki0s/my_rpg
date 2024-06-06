/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** binding
*/

#include "my.h"
#define S1 "assets/settings/Bind/select.png"
#define S2 "assets/settings/Bind/Select.png"

void init_select(global_t *glob)
{
    add_button(GL, PT(S1, S2, S2), (VF){420, 320}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 320}, (VF){656, 383}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 385}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 385}, (VF){656, 450}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 450}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 451}, (VF){656, 512}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 515}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 515}, (VF){656, 579}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 580}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 581}, (VF){656, 642}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 645}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 645}, (VF){656, 707}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 710}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 711}, (VF){656, 773}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 775}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 776}, (VF){656, 837}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 840}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 842}, (VF){656, 901}, glob), &bindings);
    add_button(GL, PT(S1, S2, S2), (VF){420, 905}, (VF){0.4, 0.4});
    set_up_rec(GL, rec((VF){420, 907}, (VF){656, 981}, glob), &bindings);
}

void init_binding(global_t *glob)
{
    CA("assets/settings/Bind/avance.png", 0, (VF){0.4, 0.4}, &(BD[0]));
    CA("assets/settings/Bind/backward.png", 0, (VF){0.4, 0.4}, &(BD[1]));
    CA("assets/settings/Bind/left.png", 0, (VF){0.4, 0.4}, &(BD[2]));
    CA("assets/settings/Bind/rigth.png", 0, (VF){0.4, 0.4}, &(BD[3]));
    CA("assets/settings/Bind/melee.png", 0, (VF){0.4, 0.4}, &(BD[4]));
    CA("assets/settings/Bind/secondary.png", 0, (VF){0.4, 0.4}, &(BD[5]));
    CA("assets/settings/Bind/compt1.png", 0, (VF){0.4, 0.4}, &(BD[6]));
    CA("assets/settings/Bind/compt2.png", 0, (VF){0.4, 0.4}, &(BD[7]));
    CA("assets/settings/Bind/compt3.png", 0, (VF){0.4, 0.4}, &(BD[8]));
    CA("assets/settings/Bind/compt4.png", 0, (VF){0.4, 0.4}, &(BD[9]));
    CA("assets/settings/Bind/inventaire.png", 0, (VF){0.4, 0.4}, &(BD[10]));
    CA("assets/settings/Bind/Screenshot.png", 0, (VF){0.4, 0.4}, &(BD[11]));
    CA("assets/settings/Bind/Next.png", 0, (VF){0.4, 0.4}, &(BD[12]));
    CA("assets/settings/Bind/back.png", 0, (VF){0.4, 0.4}, &(BD[13]));
    init_bind(glob);
}

void rebind(global_t *glob, int i)
{
    sfEvent event;
    sfRenderWindow_waitEvent(glob->window, &event);

    if (event.type == sfEvtKeyPressed)
        rebinding(glob, i, event.key.code + 2);
    else if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft)
            rebinding(glob, i, sfMouseLeft);
        else if (event.mouseButton.button == sfMouseRight)
            rebinding(glob, i, sfMouseRight);
    }
}

int split_handle_binding(global_t *glob, sfEvent event, list_but_t *t, int i)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);

    if (sfFloatRect_contains(&(t->button->rec), m.x, m.y)) {
        if (t->current == STANDBY)
            sfSound_play(glob->bitbox.s1);
        if (event.type == sfEvtMouseButtonReleased) {
            rebind(glob, i);
            return (ACTIVE);
        } else {
            return (HOVER);
        }
    } else
        return (STANDBY);
}

static void check_dico(int i, int nb, global_t *glob, sfVector2f pos)
{
    char* dico[] = {
        "Left Click", "Rigth Click", "A", "B", "C", "D", "E", "F", "G", "H",
        "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
        "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "Escape", "LControl", "LShift", "LAlt", "LSystem", "RControl",
        "RShift", "RAlt", "RSystem", "Menu", "[", "]", ";", ",", ".", "'", "/",
        "\\", "~", "=", "-", "Space", "Return", "Back", "Tab",
        "PageUp", "PageDown", "End", "Home", "Insert", "Delete", "+", "-", "*",
        "/", "Left", "Right", "Up", "Down", "Numpad0", "Numpad1", "Numpad2",
        "Numpad3", "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8",
        "Numpad9", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10",
        "F11", "F12", "F13", "F14", "F15", "Pause", NULL
    };

    for (int j = 0; dico[j]; j++) {
        if (j == nb && strlen(dico[j]) > 2)
            draw_text(glob, dico[j], 40,
            (sfVector2f){pos.x - strlen(dico[j]) - 20, pos.y + 65 * i});
        else if (j == nb)
            draw_text(glob, dico[j], 40, (sfVector2f){pos.x, pos.y + 65 * i});
    }
}

static void draw_bindings(global_t *glob)
{
    const char* key[] = {
        nbtostr(glob->binding.forward), nbtostr(glob->binding.backward),
        nbtostr(glob->binding.left), nbtostr(glob->binding.right),
        nbtostr(glob->binding.melee), nbtostr(glob->binding.secondary),
        nbtostr(glob->binding.compt1), nbtostr(glob->binding.compt2),
        nbtostr(glob->binding.compt3), nbtostr(glob->binding.compt4),
        nbtostr(glob->binding.inventory), nbtostr(glob->binding.screen),
        nbtostr(glob->binding.next), nbtostr(glob->binding.back)
    };
    int i = 0;

    for (; i < 10; i++)
        check_dico(i, atoi(key[i]), glob, (sfVector2f){500, 325});
    for (int p = 0; i < 14; i++) {
        check_dico(p, atoi(key[i]), glob, (sfVector2f){1070, 325});
        p++;
    }
}

void bindings(global_t *glob)
{
    int i = 0;

    glob->settings->b = 4;
    for (; i < 10; i++) {
        SP((sfVector2f){150, 320 + 65 * i}, &(glob->settings->bind[i]));
        DRAW(WINDOW, glob->settings->bind[i].sprite, NULL);
    }
    for (int j = 0; j < 4; j++) {
        SP((sfVector2f){750, 320 + 65 * j}, &(glob->settings->bind[i]));
        DRAW(WINDOW, glob->settings->bind[i].sprite, NULL);
        i++;
    }
    glob->settings->select->draw(glob, glob->settings->select);
    draw_bindings(glob);
}