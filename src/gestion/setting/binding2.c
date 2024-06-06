/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** binding2
*/

#include "my.h"

typedef struct action_s {
    void (*action)(int);
} action_t;

static void setforward(global_t *glob, int key) {
    glob->binding.forward = key;
}

static void setbackward(global_t *glob, int key) {
    glob->binding.backward = key;
}

static void setleft(global_t *glob, int key) {
    glob->binding.left = key;
}

static void setright(global_t *glob, int key) {
    glob->binding.right = key;
}

static void setmelee(global_t *glob, int key) {
    glob->binding.melee = key;
}

static void setsecondary(global_t *glob, int key) {
    glob->binding.secondary = key;
}

static void setcompt1(global_t *glob, int key) {
    glob->binding.compt1 = key;
}

static void setcompt2(global_t *glob, int key) {
    glob->binding.compt2 = key;
}

static void setcompt3(global_t *glob, int key) {
    glob->binding.compt3 = key;
}

static void setcompt4(global_t *glob, int key) {
    glob->binding.compt4 = key;
}

static void setinventory(global_t *glob, int key) {
    glob->binding.inventory = key;
}

static void setscreen(global_t *glob, int key) {
    glob->binding.screen = key;
}

static void setnext(global_t *glob, int key) {
    glob->binding.next = key;
}

static void setback(global_t *glob, int key) {
    glob->binding.back = key;
}

void rebinding(global_t *glob, int i, int key)
{
    void (*Binding[14])(global_t *, int) = {
        setforward, setbackward, setleft, setright,
        setmelee, setsecondary, setcompt1, setcompt2,
        setcompt3, setcompt4, setinventory, setscreen,
        setnext, setback
    };

    if (glob->binding.forward == key || glob->binding.backward == key ||
        glob->binding.left == key || glob->binding.right == key ||
        glob->binding.melee == key || glob->binding.secondary == key ||
        glob->binding.compt1 == key || glob->binding.compt2 == key ||
        glob->binding.compt3 == key || glob->binding.compt4 == key ||
        glob->binding.inventory == key || glob->binding.screen == key ||
        glob->binding.next == key || glob->binding.back == key) {
            return;
        } else
            (Binding[i])(glob, key);
}
