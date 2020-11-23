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
    world->player = malloc(sizeof(sprite_t));
    world->ammo = malloc(sizeof(sprite_t));

    init_sprite(world->player, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, PLAYER_SIZE, PLAYER_SIZE, PLAYER_SPEED);
    init_sprite(world->ammo, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - (0.5 * PLAYER_SIZE) - (AMMO_SIZE / 2), AMMO_SIZE, AMMO_SIZE, AMMO_SPEED);   //La position y du missile équivaut à la position y du joueur - 1/2joueur-1/2missile (il est juste au-dessus).
    set_invisible(world->ammo);
    init_enemies(world);

    world->gameover = 0;
    world->score = 0;
    world->etat_jeu = 0;
}


void clean_data(world_t *world){
    free(world->player);
    free(world->ammo);
    for (int i = 0; i < NB_ENEMIES; ++i)
    {
        free(world->enemies[i]);
    }
}

void init_enemies(world_t* world)
{  
    world->enemies = malloc(sizeof(sprite_t*)*NB_ENEMIES);
    for (int i = 0; i < NB_ENEMIES; ++i)
    {
        world->enemies[i] = malloc(sizeof(sprite_t));
        init_sprite(world->enemies[i], 0, 0, ENNEMY_SIZE, ENNEMY_SIZE, ENNEMY_SPEED);
    }
}
