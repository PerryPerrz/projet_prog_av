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

    init_sprite(world->player->sprite, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED);

    world->player->hp = PLAYER_HP; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_power = PLAYER_ATK_POWER; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_speed = PLAYER_ATK_SPEED; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    //world->player->weapon = ; à voir si on gère avec un fichier ou un bouton ou qqchose du genre
}


