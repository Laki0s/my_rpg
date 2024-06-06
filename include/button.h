/*
** EPITECH PROJECT, 2024
** paint
** File description:
** button
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>

#define STATUS 3

typedef struct button_s button_t;
typedef struct global_s global_t;

typedef enum STATE {
    STANDBY,
    HOVER,
    ACTIVE
} STATE_E;

typedef struct sprite_s {
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *standby;
    sfTexture *hover;
    sfTexture *active;
    sfFloatRect rec;
    void (*action)(global_t *glob);
} sprite_t;

typedef struct list_but_s {
    sprite_t *button;
    STATE_E current;
    struct list_but_s *next;
} list_but_t;

typedef struct button_s {
    list_but_t *list;
    void (*draw)(global_t *glob, button_t *but);
    void (*destroy)(button_t *but);
} button_t;
