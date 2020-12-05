/**
 * \file player.C
 * \brief Programme définnissant les fonctions déclarées dans player.h
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 24 novembre 2020
 */

#include "player.h"


void init_player(world_t* world) {

    world->player = malloc(sizeof(character_t));
    world->player->sprite = malloc(sizeof(sprite_t));

    int* w = malloc(sizeof(int)*NB_SPRITES_PLAYER);
    //On initialise les valeurs de w selon les largeurs des sprites dans la sprite sheet
    w[0] = PLAYER_SPRITE_COLUMN_1_WIDTH;
    w[1] = PLAYER_SPRITE_COLUMN_2_WIDTH;
    w[2] = PLAYER_SPRITE_COLUMN_3_WIDTH;
    w[3] = PLAYER_SPRITE_COLUMN_4_WIDTH;
    w[4] = PLAYER_SPRITE_COLUMN_5_WIDTH;
    w[5] = PLAYER_SPRITE_COLUMN_6_WIDTH;
    w[6] = PLAYER_SPRITE_COLUMN_7_WIDTH;
    w[7] = PLAYER_SPRITE_COLUMN_8_WIDTH;

    init_sprite(world->player->sprite, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, w, PLAYER_HEIGHT, PLAYER_SPEED);

    world->player->hp = PLAYER_HP; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_power = PLAYER_ATK_POWER; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_speed = PLAYER_ATK_SPEED; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    //world->player->weapon = ; à voir si on gère avec un fichier ou un bouton ou qqchose du genre
}

