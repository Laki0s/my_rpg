/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** main
*/

#include "my.h"

static void init_other(global_t *glob)
{
    for (int i = 0; i < 11; i++) {
        create_animation("assets/stats/full_heart.png", 0, (V2F){0.5, 0.5}, &glob->game->hearth[i].hearth);
        create_animation("assets/stats/demi_hearth.png", 0, (V2F){0.5, 0.5}, &glob->game->hearth[i].demi_hearth);
        create_animation("assets/stats/void_heart.png", 0, (V2F){0.5, 0.5}, &glob->game->hearth[i].void_hearth);
        sprite_position((V2F){0 + 50 * i, 0}, &glob->game->hearth[i].hearth);
        sprite_position((V2F){0 + 50 * i, 0}, &glob->game->hearth[i].demi_hearth);
        sprite_position((V2F){0 + 50 * i, 0}, &glob->game->hearth[i].void_hearth);
    }
    create_animation("assets/stats/damage.png", 0, (V2F){0.65, 0.5}, &glob->game->stat.damage);
    sprite_position((V2F){0, 100}, &glob->game->stat.damage);
    create_animation("assets/stats/delay_shot.png", 0, (V2F){0.65, 0.5}, &glob->game->stat.fire_rate);
    sprite_position((V2F){0, 150}, &glob->game->stat.fire_rate);
    create_animation("assets/stats/speed.png", 0, (V2F){0.65, 0.5}, &glob->game->stat.speed);
    sprite_position((V2F){0, 200}, &glob->game->stat.speed);
    create_animation("assets/stats/fire_rate.png", 0, (V2F){0.65, 0.5}, &glob->game->stat.shot_speed);
    sprite_position((V2F){0, 250}, &glob->game->stat.shot_speed);
    create_animation("assets/stats/range.png", 0, (V2F){0.65, 0.5}, &glob->game->stat.range);
    sprite_position((V2F){0, 300}, &glob->game->stat.range);
    create_animation("assets/stats/lives.png", 0, (V2F){0.4, 0.4}, &glob->game->stat.death);
    sprite_position((V2F){-10, 350}, &glob->game->stat.death);
}

void init_game(global_t *glob)
{
    glob->game = malloc(sizeof(game_t));
    glob->game->shot = malloc(sizeof(bullet_t));
    glob->game->shot = NULL;
    glob->game->index = 0;
    glob->game->time = 0;
    glob->game->battle_mode = false;
    glob->game->mode = 0;
    glob->game->stat.delay = 0;
    glob->game->stat.delay_a = false;
    glob->game->getdata = false;
    glob->game->stat.left = false;
    glob->game->stat.rigth = false;
    glob->game->stat.top = false;
    glob->game->stat.bot = false;
    glob->game->hitbox = rectancle((V2F){90, 110}, (V2F){20, 20}, sfColor_fromRGBA(255, 0, 0, 0));
    sfRectangleShape_setOrigin(glob->game->hitbox, (V2F){5, 10});
    create_animation("assets/new/backward.png", 0.15, (V2F){1, 1}, &glob->game->steps[0]);
    create_animation("assets/new/forward.png", 0.15, (V2F){1, 1}, &glob->game->steps[1]);
    rigth_animation("assets/new/left.png", 0.15, (V2F){1, 1}, &glob->game->steps[2]);
    rigth_animation("assets/new/rigth.png", 0.15, (V2F){1, 1}, &glob->game->steps[3]);
    create_animation("assets/new/idle3.png", 0.15, (V2F){1, 1}, &glob->game->steps[4]);
    create_animation("assets/new/idle4.png", 0.15, (V2F){1, 1}, &glob->game->steps[5]);
    rigth_animation("assets/new/idle2.png", 0.15, (V2F){1, 1}, &glob->game->steps[6]);
    rigth_animation("assets/new/idle1.png", 0.15, (V2F){1, 1}, &glob->game->steps[7]);
    glob->game->state = 5;
    glob->game->stat.xp = 0;
    glob->game->pos = (V2F){480, 268};
    sprite_position((V2F){480, 268}, &glob->game->steps[0]);
    init_scene(glob);
    init_other(glob);
    init_option(glob);
    init_inventory(glob);
}

void handle_game_events(global_t *glob)
{
    sfEvent evt;
    sfVector2f new = glob->game->pos;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        check_screen(glob, evt);
        if (glob->game->option->active == false) {
            glob->game->scenes[glob->game->index].handle_event(glob);
            characters(glob, evt, new);
            handle_inv(glob, evt);
        }
        handle_option(glob, evt);
    }
}

void update_game(global_t *glob)
{
    if (glob->game->getdata == false) {
        glob->game->life = glob->charac.hp;
        glob->game->stat.value_damage = glob->charac.damage;
        glob->game->stat.value_fire_rate = glob->charac.fire_rate;
        glob->game->stat.value_range = glob->charac.range;
        glob->game->stat.value_shot_speed = glob->charac.shot_speed * 50;
        glob->game->stat.value_speed = glob->charac.speed;
        glob->game->stat.value_death = glob->charac.death;
        glob->game->getdata = true;
    }
    if (glob->game->stat.delay_a == true) {
        glob->game->stat.delay += glob->delta_time;
        if (glob->game->stat.delay >= glob->game->stat.value_fire_rate) {
            glob->game->stat.delay = 0;
            glob->game->stat.delay_a = false;
        }
    }
    if (glob->game->option->active == false) {
        update_bullet(glob);
        glob->game->time += glob->delta_time;
        if (STATE < 4)
            update_animation(&glob->game->steps[glob->game->state], glob->delta_time);
        sfRectangleShape_setPosition(glob->game->hitbox, glob->game->pos);
        glob->game->scenes[glob->game->index].update(glob);
        if (glob->game->life <= 0) {
            glob->game->index = 0;
            glob->game->pos = (V2F){480, 268};
            glob->game->getdata = false;
            glob->charac.death++;
        }
        if (5 * glob->charac.lvl <= glob->game->stat.xp) {
            glob->charac.lvl++;
            glob->game->stat.xp = 0;
            glob->charac.hp += 1;
            glob->charac.damage += 1;
            glob->charac.fire_rate -= 0.20;
            glob->charac.range += 25;
            glob->charac.shot_speed += 5;
            glob->game->getdata = true;
        }
    }
}

static void draw_stat(global_t *glob)
{
    int integer = glob->game->life;
    float b = integer - glob->game->life;
    int i = 0;

    for (; i < integer; i++)
        DRAW(WINDOW, glob->game->hearth[i].hearth.sprite, NULL);
    if (b != 0.0f) {
        DRAW(WINDOW, glob->game->hearth[i].demi_hearth.sprite, NULL);
        i++;
    }
    for (; i < glob->charac.hp; i++)
        DRAW(WINDOW, glob->game->hearth[i].void_hearth.sprite, NULL);
    DRAW(WINDOW, glob->game->stat.damage.sprite, NULL);
    DRAW(WINDOW, glob->game->stat.fire_rate.sprite, NULL);
    DRAW(WINDOW, glob->game->stat.speed.sprite, NULL);
    DRAW(WINDOW, glob->game->stat.shot_speed.sprite, NULL);
    DRAW(WINDOW, glob->game->stat.range.sprite, NULL);
    DRAW(WINDOW, glob->game->stat.death.sprite, NULL);
    draw_text(glob, "Lvl :", 50, (V2F){0, 33});
    draw_text(glob, inttostr(glob->charac.lvl), 50, (V2F){100, 33});
    draw_text(glob, nbtostr(glob->game->stat.value_damage), 30, (V2F){50, 100});
    draw_text(glob, nbtostr(glob->game->stat.value_fire_rate), 30, (V2F){50, 150});
    draw_text(glob, nbtostr(glob->game->stat.value_speed), 30, (V2F){50, 200});
    draw_text(glob, nbtostr(glob->game->stat.value_shot_speed), 30, (V2F){50, 250});
    draw_text(glob, nbtostr(glob->game->stat.value_range), 30, (V2F){50, 300});
    draw_text(glob, inttostr(glob->game->stat.value_death), 30, (V2F){50, 350});
}

void draw_game(global_t *glob)
{
    sfVideoMode size = sfVideoMode_getDesktopMode();

    sfRenderWindow_clear(WINDOW, sfBlack);
    glob->game->scenes[glob->game->index].draw(glob);
    draw_bullet(glob);
    draw_text(glob, nbtostr(glob->game->stat.delay), 50, (V2F){size.width - 80, size.height -70});
    DRAW(WINDOW, glob->game->steps[glob->game->state].sprite, NULL);
    draw_stat(glob);
    draw_option(glob);
    draw_inv(glob);
    sfRenderWindow_display(WINDOW);
}

void destroy_game(global_t *glob)
{
    glob->game->scenes[0].destroy(glob);
    free(glob->game);
}
