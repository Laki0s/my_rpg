/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_backup
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

static int check_dir(char *dir)
{
    struct stat info_fd;
    int a = 0;

    if (lstat(dir, &info_fd) == -1)
        return false;
    a = S_ISDIR(info_fd.st_mode) ? true : false;
    if (a == true) {
        if (access(dir, R_OK) == 0)
            return true;
        else
            return false;
    } else
        return false;
}

static int *create_dir(char *dir, global_t *glob)
{
    for (int i = 0; i < 3; i++)
        glob->backup[i].exist = false;
    if (mkdir(dir, 0700) != 0)
        return 0;
    return 0;
}

static void gestion_inv(global_t *glob, char *data, int i)
{
    int size = glob->backup[i].size;

    if (strcmp(data, "none") == 0) {
        glob->backup[i].inv = NULL;
        return;
    }
    size++;
    glob->backup[i].size++;
    glob->backup[i].inv = realloc(glob->backup[i].inv, (size) * sizeof(int));
    glob->backup[i].inv[size - 1] = atoi(data);
}

static void sort_data(global_t *glob, char **tab, int i)
{
    if (strcmp(tab[0], "Class") == 0)
        glob->backup[i].class = atoi(tab[1]);
    if (strcmp(tab[0], "Lvl") == 0)
        glob->backup[i].lvl = atoi(tab[1]);
    if (strcmp(tab[0], "Hp") == 0)
        glob->backup[i].hp = atof(tab[1]);
    if (strcmp(tab[0], "Speed") == 0)
        glob->backup[i].speed = atoi(tab[1]);
    if (strcmp(tab[0], "FireRate") == 0)
        glob->backup[i].fire_rate = atof(tab[1]);
    if (strcmp(tab[0], "Damage") == 0)
        glob->backup[i].damage = atof(tab[1]);
    if (strcmp(tab[0], "Range") == 0)
        glob->backup[i].range = atoi(tab[1]);
    if (strcmp(tab[0], "Death") == 0)
        glob->backup[i].death = atoi(tab[1]);
    if (strcmp(tab[0], "ShotSpeed") == 0)
        glob->backup[i].shot_speed = atof(tab[1]);
    if (strcmp(tab[0], "Quest") == 0)
        glob->backup[i].quest = atof(tab[1]);
    if (strcmp(tab[0], "Timer") == 0)
        glob->backup[i].seconde = atoi(tab[1]);
    if (strcmp(tab[0], "Inventaire") == 0)
        gestion_inv(glob, tab[1], i);
}

static void get_data(global_t *glob, char *filename)
{
    int i = 0;
    FILE *file = fopen(filename, "r");
    char *str = NULL;
    size_t size = 0;
    char **tmp = NULL;

    if (file == NULL)
        return;
    for (; i < 3; i++)
        if (glob->backup[i].exist != true)
            break;
    glob->backup[i].size = 0;
    while (getline(&str, &size, file) != -1) {
        if (str[0] == '\n')
            continue;
        glob->backup[i].exist = true;
        tmp = my_str_to_word_array(str);
        sort_data(glob, tmp, i);
    }
}

void *get_backup(void *args)
{
    global_t *glob = (global_t *)args;
    DIR *dir = opendir("save");
    struct dirent *read;
    struct stat file_stat;
    char file[1024];

    if (check_dir("save") == false || dir == NULL)
        return (create_dir("save", glob));
    read = readdir(dir);
    while (read != NULL) {
        snprintf(file, sizeof(file), "save/%s", read->d_name);
        if (stat(file, &file_stat) == -1)
            continue;
        if (S_ISREG(file_stat.st_mode))
            get_data(glob, file);
        read = readdir(dir);
    }
    closedir(dir);
    return 0;
}

void save(global_t *glob)
{
    char filename[1024];
    FILE *file = NULL;
    int nb = glob->perso->delete == 0 ? 0 : 1;

    nb = glob->perso->delete == 2 ? 2 : 1;
    snprintf(filename, sizeof(filename), "save/backup%d", glob->perso->delete - (nb - 1));
    file = fopen(filename, "w");
    if (file != NULL) {
        glob->backup[glob->perso->delete - nb].exist = true;
        glob->backup[glob->perso->delete - nb].lvl = glob->charac.lvl;
        glob->backup[glob->perso->delete - nb].class = glob->charac.class;
        glob->backup[glob->perso->delete - nb].seconde = glob->game->time;
        glob->backup[glob->perso->delete - nb].quest = 0;
        glob->backup[glob->perso->delete - nb].hp = glob->charac.hp;
        glob->backup[glob->perso->delete - nb].speed = glob->charac.speed;
        glob->backup[glob->perso->delete - nb].fire_rate = glob->charac.fire_rate;
        glob->backup[glob->perso->delete - nb].damage = glob->charac.damage;
        glob->backup[glob->perso->delete - nb].range = glob->charac.range;
        glob->backup[glob->perso->delete - nb].shot_speed = glob->charac.shot_speed;
        glob->backup[glob->perso->delete - nb].death = glob->charac.death;
        fprintf(file, "Class=%d\n", glob->charac.class);
        fprintf(file, "Lvl=%d\n", glob->charac.lvl);
        fprintf(file, "Hp=%f\n", glob->charac.hp);
        fprintf(file, "Speed=%f\n", glob->charac.speed);
        fprintf(file, "FireRate=%f\n", glob->charac.fire_rate);
        fprintf(file, "Damage=%f\n", glob->charac.damage);
        fprintf(file, "Range=%d\n", glob->charac.range);
        fprintf(file, "ShotSpeed=%d\n", glob->charac.shot_speed);
        fprintf(file, "Quest=%.2f\n", glob->charac.quest);
        fprintf(file, "Timer=%d\n", glob->charac.timer);
        fprintf(file, "Death=%d\n", glob->charac.death);
        if (glob->charac.inv == NULL)
            fprintf(file, "Inventaire=none\n");
        for (int i = 0; glob->charac.inv != NULL && glob->charac.inv[i]; i++)
            fprintf(file, "Inventaire=%d\n", glob->charac.inv[i]);
        fclose(file);
    }
}