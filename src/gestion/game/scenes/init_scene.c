/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_scene
*/

#include "my.h"

void (*init_funcs[26])() = {
    &init_s1, &init_s2, &init_s3, &init_s4, &init_s5, &init_s6,
    &init_s7, &init_s8, &init_s9, &init_s10, &init_s11, &init_s12,
    &init_s13, &init_s14, &init_s15
};

void (*handle_funcs[26])() = {
    &handle_s1, &handle_s2, &handle_s3, &handle_s4, &handle_s5, &handle_s6,
    &handle_s7, &handle_s8, &handle_s9, &handle_s11, &handle_s12, &handle_s13
    , &handle_s14, &handle_s15,
};

void (*update_funcs[26])() = {
    &update_s1, &update_s2, &update_s3, &update_s4, &update_s5, &update_s6,
    &update_s7, &update_s8, &update_s9, &handle_s10, &update_s11, &update_s12,
    &update_s13, &update_s14, &update_s15
};

void (*draw_funcs[26])() = {
    &draw_s1, &draw_s2, &draw_s3, &draw_s4, &draw_s5, &draw_s6,
    &draw_s7, &draw_s8, &draw_s9, &draw_s10, &draw_s11, &draw_s12,
    &draw_s13,  &draw_s14, &draw_s15,
};

void (*destroy_funcs[26])() = {
    &destroy_s1, &destroy_s2, &destroy_s3, &destroy_s4, &destroy_s5, &destroy_s6,
    &destroy_s7, &destroy_s8, &draw_s9, &destroy_s10, &destroy_s11, &destroy_s12,
    &destroy_s13, &destroy_s14, &destroy_s15
};

void init_scene(global_t *glob)
{
    for (int i = 0; i < 15; i++) {
        glob->game->scenes[i] = (scene_t){
            init_funcs[i],
            handle_funcs[i],
            update_funcs[i],
            draw_funcs[i],
            destroy_funcs[i]
        };
    glob->game->scenes[i].init(glob);
    }
}