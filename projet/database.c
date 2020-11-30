/**
 * \file database.c
 * \brief Programme definissant les fonctions déclarées dans database.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 12 novembre 2020
 */
#include "database.h"

void init_sprite(sprite_t *sprite, int x, int y, int* w, int h, int v)
{
    sprite->x = x;
    sprite->y = y;
    sprite->h = h;
    sprite->w = w;
    sprite->v = v;
    sprite->is_visible = 0;
    sprite->wich_img = malloc(sizeof(int)*2);
    sprite->wich_img[0] = 0;
    sprite->wich_img[1] = 0;
}

int generate_number(int a, int b)
{
    return rand() % (b - a) + a;
}

void set_visible(sprite_t *sprite)
{
    sprite->is_visible = 0;
}

void set_invisible(sprite_t *sprite)
{
    sprite->is_visible = 1;
}

int is_game_over(world_t *world)
{
    return world->gameover;
}

int sprite_is_out_of_bounds(sprite_t* sprite)
{
    if ((sprite->x + sprite->w[sprite->wich_img[0]] / 2 >= PLAY_ZONE_RIGHT_WALL)  ||  (sprite->x - sprite->w[sprite->wich_img[0]] / 2 <= PLAY_ZONE_LEFT_WALL) || (sprite->y - sprite->h/ 2 <= PLAY_ZONE_TOP_WALL) || (sprite->y + sprite->h / 2 >= PLAY_ZONE_BOTTOM_WALL)) {
        return 0;
    }
    return 1;
}