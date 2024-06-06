/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** mystruct
*/

#pragma once
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include "button.h"

#define SCENES 7

typedef struct global_s global_t;

typedef enum SCENE {
    LOAD,
    MENU,
    LOBBY,
    NEW,
    INTRO,
    SETTING,
    GAME
} SCENE_E;

typedef struct scene_s {
    void (*init)(global_t *global);
    void (*handle_event)(global_t *global);
    void (*update)(global_t *global);
    void (*draw)(global_t *global);
    void (*destroy)(global_t *global);
} scene_t;

typedef struct sprites_s {
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f origin;
    float frame_duration;
    float seconds;
    int frame_size;
    int end_frame;
    sfIntRect bounds;
    sfSprite *sprite;
    sfTexture *texture;
    void (*update)(struct sprites_s *this, float delta_time);
    sfImage* image;
} sprites_t;

typedef struct characters_s {
    int class;
    int lvl;
    float hp;
    float speed;
    float fire_rate;
    float damage;
    int range;
    int shot_speed;
    float quest;
    int death;
    int timer;
    int *inv;
} characters_t;

typedef struct save_s {
    int exist;
    int class;
    float quest;
    int lvl;
    float hp;
    float speed;
    int death;
    float fire_rate;
    float damage;
    int range;
    float shot_speed;
    int seconde;
    int *inv;
    int size;
} save_t;

typedef struct bind_s {
    int forward;
    int backward;
    int left;
    int right;
    int melee;
    int secondary;
    int compt1;
    int compt2;
    int compt3;
    int compt4;
    int inventory;
    int screen;
    int next;
    int back;
} bind_t;

typedef struct sound_s {
    sfMusic *ost;
    sfSound *act;
    sfSound *s1;
} sound_t;

typedef struct load_s {
    sprites_t *limousine;
    sfRectangleShape *r;
    int a;
} load_t;

typedef struct menu_s {
    sprites_t *b1;
    sprites_t *b2;
    sprites_t *title;
    button_t *but;
} menu_t;

typedef struct lobby_s {
    sprites_t *background;
    sprites_t *cadre;
    sprites_t caracter[6];
    button_t *but;
    sfRectangleShape *rec;
    int a;
    bool choice;
} lobby_t;

typedef struct new_s {
    sprites_t *background;
    sprites_t cadre[6];
    sprites_t character[6];
    button_t *del;
    int delete;
    button_t *but;
    int a;
} new_t;

typedef struct intro_s {
    sprites_t background[1];
} intro_t;

typedef struct setting_s {
    sprites_t *background;
    sprites_t *choose_difficulty;
    sprites_t bull;
    sprites_t bar[3];
    sprites_t sound[3];
    sprites_t vid[4];
    sprites_t bind[14];
    sprites_t cursor[3];
    button_t *res;
    button_t *difficulty;
    button_t *but;
    button_t *select;
    int m;
    float e;
    float s;
    int b;
    void (*draw)(global_t *);
    void (*handle)(global_t *);
} setting_t;

typedef struct mob_s {
    float hp;
    int speed;
    float fire_rate;
    float damage;
    int range;
    int shot_speed;
    sprites_t *mob;
    sfRectangleShape *hitbox;
    sfVector2f position;
    float delay;
    bool delay_a;
    bool finish;
    struct mob_s *next;
} mob_t;

typedef struct all_mobs_s {
    mob_t *dinga;
    mob_t *tear;
    mob_t *bat;
    mob_t *bat2;
    mob_t *slime;
    mob_t *boul;
    mob_t *b1;
    mob_t *b2;
    mob_t *b3;
    mob_t *b4;
} all_mob_t;

typedef struct scene_game_s {
    sprites_t *map;
    sprites_t *entity;
    sfImage *colision;
    all_mob_t mobs;
} scene_game_t;

typedef struct lives_s{
    sprites_t hearth;
    sprites_t demi_hearth;
    sprites_t void_hearth;
} lives_t;

typedef struct stats_s{
    sprites_t speed;
    sprites_t fire_rate;
    sprites_t damage;
    sprites_t range;
    sprites_t shot_speed;
    sprites_t death;
    float value_speed;
    float value_fire_rate;
    float value_damage;
    float value_range;
    float value_shot_speed;
    int value_death;
    int xp;
    float delay;
    bool delay_a;
    bool left;
    bool rigth;
    bool top;
    bool bot;
} stat_t;

typedef struct bullet_s {
    sprites_t bullet;
    sfVector2f old;
    sfVector2f end;
    sfRectangleShape *hitbox;
    bool finish;
    int a;
    struct bullet_s *next;
} bullet_t;

typedef struct option_s {
    bool active;
    sfRectangleShape *rec;
    bool hitbox;
    sprites_t *back;
    button_t *but;
} option_t;

typedef struct item_t {
    int id;
    sprites_t sprite;
    sprites_t curseur;
    bool here;
} item_t;

typedef struct inventory_t {
    sprites_t slot[4];
    item_t items[4];
    int index;
} inventory_t;

typedef struct game_s {
    scene_t scenes[26];
    scene_game_t all[26];
    sprites_t steps[8];
    int state;
    inventory_t inv;
    lives_t hearth[11];
    bullet_t *shot;
    stat_t stat;
    sfRectangleShape *hitbox;
    option_t *option;
    float life;
    int index;
    sfVector2f pos;
    int mode;
    bool battle_mode;
    int time;
    bool getdata;
} game_t;

typedef struct global_s {
    bool isfullscreen;
    pthread_t thread;
    sfRenderWindow *window;
    SCENE_E old;
    SCENE_E current_scene;
    scene_t scenes[SCENES];
    sfClock *clock;
    sfView *camera;
    save_t backup[3];
    characters_t charac;
    float difficulty;
    float timer;
    float delta_time;
    sfFont *font;
    bind_t binding;
    sprites_t cursor;
    sound_t bitbox;
    load_t *load;
    menu_t *menu;
    lobby_t *hub;
    new_t *perso;
    intro_t *intro;
    setting_t *settings;
    game_t *game;
    mob_t* head;
} global_t;
