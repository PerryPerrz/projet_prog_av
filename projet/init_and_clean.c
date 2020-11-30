/**
 * \file init_and_clean.c
 * \brief Programme définissant les fonctions déclarées dans one_use.h
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 27 mai 2020
 */

#include "init_and_clean.h"

void init_data(world_t * world){
    srand(time(NULL));

    //world->ammo = malloc(sizeof(sprite_t));

    /* A faire si on implémente une attaque à distance pour le personnage
    int* ammo_w = malloc(sizeof(int));
    init_sprite(world->ammo, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - (0.5  * PLAYER_SIZE ) - (AMMO_SIZE / 2), AMMO_SIZE, AMMO_SIZE, AMMO_SPEED);   //La position y du missile équivaut à la position y du joueur - 1/2joueur-1/2missile (il est juste au-dessus).
    set_invisible(world->ammo);*/

    init_enemies(world);
    init_player(world);

    world->gameover = 0;
    world->score = 0;
    world->game_state = 0;
    world->room_state = 0;
}


void clean_data(world_t *world){
    //free_player(world);
    //free_monsters(world);
    //free(world->ammo);
    free_enemies(world);
}
