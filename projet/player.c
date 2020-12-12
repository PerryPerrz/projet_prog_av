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

    int* w = malloc(sizeof(int)*NB_COLUMN_SPRITE_SHEET_PLAYER);
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
    set_img_sprite(world->player->sprite, 0, 2); //On affiche l'image de repos du personnage en premier

    world->player->hp = PLAYER_HP; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_power = PLAYER_ATK_POWER; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_speed = PLAYER_ATK_SPEED; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    //world->player->weapon = ; à voir si on gère avec un fichier ou un bouton ou qqchose du genre
    world->player->animation_timer = 0;
}

void handle_anim_player(world_t * world) {
    if (world->player->animation_timer >= 1 && world->player->animation_timer < 21) { //21 = 5*4 + 1 car on fait un changement de sprite toutes les 4 boucles de jeu pour une animation lente et on a 6 sprites dans une animation (notés de 0 à 5) 
        if (world->player->animation_timer%4 == 0) {
            world->player->sprite->wich_img[1]++;
        }
        world->player->animation_timer++;
    }
    else {
        world->player->sprite->wich_img[1] = 2;
    }
}

void free_player(world_t* world) {
    free(world->player->sprite->w);
    free(world->player->sprite->wich_img);
    free(world->player->sprite);
    free(world->player);
}