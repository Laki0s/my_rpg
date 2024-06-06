/*
** EPITECH PROJECT, 2023
** header
** File description:
** lol
*/

#pragma once

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <math.h>
#include <pthread.h>
#include "global.h"

#define SRWC sfRenderWindow_create
#define TCFF sfTexture_createFromFile
#define POLLEVENT sfRenderWindow_pollEvent
#define DRAW sfRenderWindow_drawSprite
#define SP sprite_position
#define WINDOW glob->window
#define TEXTURE glob->texture
#define SPRITE glob->paint->pic->sprite
#define GL glob->settings->select
#define VF sfVector2f
#define BD glob->settings->bind
#define CA create_animation
#define SE glob->settings->select
#define PT paths_to_tab
#define V2F sfVector2f
#define STATE glob->game->state

//str function
int description(char *filename);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
void set_sprite(sfSprite *sprite, sfTexture *texture,
    sfVector2f scale, sfVector2f pos);
char *my_strdup(char const *src);
int my_atoi(char *str);
char **paths_to_tab(char *standby, char *hover, char *active);
char *my_strcpy(char *dest, char const *src);
char *nbtostr(float nb);
char **my_str_to_word_array(char const *str);
char *inttostr(int nb);


//animation and gestion sprite
void create_animation(const char *texture_path, float duration,
    sfVector2f scale, sprites_t *animation);
void rigth_animation(const char *texture_path, float duration,
    sfVector2f scale, sprites_t *animation);
void update_animation(sprites_t *animation, float delta_time);
void sprite_position(sfVector2f pos, sprites_t *animation);
void draw_button(global_t *glob, button_t *but);
void destroy_button(button_t *but);
void add_button(button_t *but, char **paths, sfVector2f pos, sfVector2f scale);
void set_up_rec(button_t *but, sfFloatRect rec, void (*action)(global_t *));
sfFloatRect rec(sfVector2f max, sfVector2f min, global_t *glob);
void draw_text(global_t *glob, char *str, int scale, sfVector2f pos);

//other
void sound_box(global_t *glob);
void save_image(global_t *glob);
sfRectangleShape *rectancle(sfVector2f size, sfVector2f pos, sfColor color);

//action
void delete_backup(global_t *glob);
void leave(global_t *glob);
void start(global_t *glob);
void setting(global_t *glob);
void new_perso(global_t *glob);
void next(global_t *glob);
void intro(global_t *glob);
void back(global_t *glob);
void game(global_t *glob);
void lobby(global_t *glob);
void sound_off(global_t *glob);
void restore_a_level(global_t *glob);
void home(global_t *glob);
void check_screen(global_t *glob, sfEvent evt);
void *get_backup(void *args);
void characters(global_t *glob, sfEvent event, sfVector2f new);
void add_bullet(global_t *glob);
void update_bullet(global_t *glob);
void draw_bullet(global_t *glob);
void destroy_bullet(global_t *glob);
void init_scene(global_t *glob);
int test_entity(sfImage* map, sfVector2f pos, sfColor door);
void init_option(global_t *glob);
void draw_option(global_t *glob);
void destroy_option(global_t *glob);
void handle_option(global_t *glob, sfEvent event);
void draw_inv(global_t *glob);
void handle_inv(global_t *glob, sfEvent evt);
void handle_inv2(global_t *glob, sfEvent evt);
void init_inventory(global_t *glob);
void save(global_t *glob);
mob_t *new_tearmob(sfVector2f pos);
void add_tear(mob_t **mob, sfVector2f pos);
void update_tear(global_t *global, mob_t *mob, float delta_time);
void update_bat(global_t *global, mob_t *mob, float delta_time);
void add_bat(mob_t **mob, sfVector2f pos);
void add_bat2(mob_t **mob, sfVector2f pos);
void update_bat2(global_t *global, mob_t *mob, float delta_time);
void draw_mob(global_t *glob, mob_t *mob);
void delete_mob(mob_t *mob);
void add_slime(mob_t **mob, sfVector2f pos);
void update_slime(global_t *global, mob_t *mob, float delta_time);
void add_boul(mob_t **mob, sfVector2f pos);
void update_boul(global_t *global, mob_t *mob, float delta_time);
void update_b1(global_t *global, mob_t *mob, float delta_time);
void add_b1(mob_t **mob, sfVector2f pos);
void add_b2(mob_t **mob, sfVector2f pos);
void update_b2(global_t *global, mob_t *mob, float delta_time);
void add_b4(mob_t **mob, sfVector2f pos);
void update_b4(global_t *global, mob_t *mob, float delta_time);
void add_b3(mob_t **mob, sfVector2f pos);
void update_b3(global_t *global, mob_t *mob, float delta_time);

/////settings
//keybinding
void bindings(global_t *glob);
void init_binding(global_t *glob);
void init_bind(global_t *glob);
void rebinding(global_t *glob, int i, int key);
int split_handle_binding(global_t *glob, sfEvent event, list_but_t *t, int i);
void init_select(global_t *glob);
///video
void video(global_t *glob);
int split_handle_video(global_t *glob, sfEvent event, list_but_t *t);
void init_video(global_t *glob);
void set_screen_little(global_t *glob);
void set_screen_average(global_t *glob);
void set_screen_standar(global_t *glob);
void set_screen_big(global_t *glob);
void set_fullscreen(global_t *glob);
void set_windowmode(global_t *glob);
void Vsync_f(global_t *glob);
void Vsync_a(global_t *glob);
void fps_max(global_t *glob);
void fps_average(global_t *glob);
void fps_low(global_t *glob);
///gameplay
void gameplay(global_t *glob);
int split_handle_gameplay(global_t *glob, sfEvent event, list_but_t *t);
void init_gameplay(global_t *glob);
/// sound
void sound(global_t *glob);
void handle_sound(global_t *glob, sfEvent evt);
void init_sound(global_t *glob);
///////

///
void add_mob(mob_t **mob, sfVector2f pos);
void update_mob(global_t *global, mob_t *mob, float delta_time);
void draw_mob(global_t *glob, mob_t *mob);
void delete_mob(mob_t *mob);
///

///////////
/// handle load
void init_load(global_t *glob);
void handle_load_events(global_t *glob);
void update_load(global_t *glob);
void draw_load(global_t *glob);
void destroy_load(global_t *glob);
void destroy_glob(global_t *glob);
//handle menu
void init_menu(global_t *glob);
void handle_menu_events(global_t *glob);
void update_menu(global_t *glob);
void draw_menu(global_t *glob);
void destroy_menu(global_t *glob);
/// handle lobby
void init_lobby(global_t *glob);
void handle_lobby_events(global_t *glob);
void update_lobby(global_t *glob);
void draw_lobby(global_t *glob);
void destroy_lobby(global_t *glob);
/// handle intro
void init_intro(global_t *glob);
void handle_intro_events(global_t *glob);
void update_intro(global_t *glob);
void draw_intro(global_t *glob);
void destroy_intro(global_t *glob);
/// handle setting
void init_setting(global_t *glob);
void handle_setting_events(global_t *glob);
void update_setting(global_t *glob);
void draw_setting(global_t *glob);
void destroy_setting(global_t *glob);
/// handle game
void init_game(global_t *glob);
void handle_game_events(global_t *glob);
void update_game(global_t *glob);
void draw_game(global_t *glob);
void destroy_game(global_t *glob);
/// select perso
void init_new(global_t *glob);
void handle_new_events(global_t *glob);
void update_new(global_t *glob);
void draw_new(global_t *glob);
void destroy_new(global_t *glob);

//all
void destroy_glob(global_t *glob);
///////////////
void destroy_s1(global_t *glob);
void draw_s1(global_t *glob);
void update_s1(global_t *glob);
void handle_s1(global_t *glob);
void init_s1(global_t *glob);
void destroy_s2(global_t *glob);
void draw_s2(global_t *glob);
void update_s2(global_t *glob);
void handle_s2(global_t *glob);
void init_s2(global_t *glob);
void destroy_s3(global_t *glob);
void draw_s3(global_t *glob);
void update_s3(global_t *glob);
void handle_s3(global_t *glob);
void init_s3(global_t *glob);
void destroy_s4(global_t *glob);
void draw_s4(global_t *glob);
void update_s4(global_t *glob);
void handle_s4(global_t *glob);
void init_s4(global_t *glob);
void destroy_s5(global_t *glob);
void draw_s5(global_t *glob);
void update_s5(global_t *glob);
void handle_s5(global_t *glob);
void init_s5(global_t *glob);
void destroy_s6(global_t *glob);
void draw_s6(global_t *glob);
void update_s6(global_t *glob);
void handle_s6(global_t *glob);
void init_s6(global_t *glob);
void destroy_s7(global_t *glob);
void draw_s7(global_t *glob);
void update_s7(global_t *glob);
void handle_s7(global_t *glob);
void init_s7(global_t *glob);
void destroy_s8(global_t *glob);
void draw_s8(global_t *glob);
void update_s8(global_t *glob);
void handle_s8(global_t *glob);
void init_s8(global_t *glob);
void destroy_s9(global_t *glob);
void draw_s9(global_t *glob);
void update_s9(global_t *glob);
void handle_s9(global_t *glob);
void init_s9(global_t *glob);
void destroy_s10(global_t *glob);
void draw_s10(global_t *glob);
void update_s10(global_t *glob);
void handle_s10(global_t *glob);
void init_s10(global_t *glob);
void destroy_s11(global_t *glob);
void draw_s11(global_t *glob);
void update_s11(global_t *glob);
void handle_s11(global_t *glob);
void init_s11(global_t *glob);
void destroy_s12(global_t *glob);
void draw_s12(global_t *glob);
void update_s12(global_t *glob);
void handle_s12(global_t *glob);
void init_s12(global_t *glob);
void destroy_s13(global_t *glob);
void draw_s13(global_t *glob);
void update_s13(global_t *glob);
void handle_s13(global_t *glob);
void init_s13(global_t *glob);
void destroy_s14(global_t *glob);
void draw_s14(global_t *glob);
void update_s14(global_t *glob);
void handle_s14(global_t *glob);
void init_s14(global_t *glob);
void destroy_s15(global_t *glob);
void draw_s15(global_t *glob);
void update_s15(global_t *glob);
void handle_s15(global_t *glob);
void init_s15(global_t *glob);
void destroy_s16(global_t *glob);
void draw_s16(global_t *glob);
void update_s16(global_t *glob);
void handle_s16(global_t *glob);
void init_s16(global_t *glob);
void destroy_s17(global_t *glob);
void draw_s17(global_t *glob);
void update_s17(global_t *glob);
void handle_s17(global_t *glob);
void init_s17(global_t *glob);
void destroy_s18(global_t *glob);
void draw_s18(global_t *glob);
void update_s18(global_t *glob);
void handle_s18(global_t *glob);
void init_s18(global_t *glob);
void destroy_s19(global_t *glob);
void draw_s19(global_t *glob);
void update_s19(global_t *glob);
void handle_s19(global_t *glob);
void init_s19(global_t *glob);
void destroy_s20(global_t *glob);
void draw_s20(global_t *glob);
void update_s20(global_t *glob);
void handle_s20(global_t *glob);
void init_s20(global_t *glob);
void destroy_s21(global_t *glob);
void draw_s21(global_t *glob);
void update_s21(global_t *glob);
void handle_s21(global_t *glob);
void init_s21(global_t *glob);
void destroy_s22(global_t *glob);
void draw_s22(global_t *glob);
void update_s22(global_t *glob);
void handle_s22(global_t *glob);
void init_s22(global_t *glob);
void destroy_s23(global_t *glob);
void draw_s23(global_t *glob);
void update_s23(global_t *glob);
void handle_s23(global_t *glob);
void init_s23(global_t *glob);
void destroy_s24(global_t *glob);
void draw_s24(global_t *glob);
void update_s24(global_t *glob);
void handle_s24(global_t *glob);
void init_s24(global_t *glob);
void destroy_s25(global_t *glob);
void draw_s25(global_t *glob);
void update_s25(global_t *glob);
void handle_s25(global_t *glob);
void init_s25(global_t *glob);
void destroy_s26(global_t *glob);
void draw_s26(global_t *glob);
void update_s26(global_t *glob);
void handle_s26(global_t *glob);
void init_s26(global_t *glob);
