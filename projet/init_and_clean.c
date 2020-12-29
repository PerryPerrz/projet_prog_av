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

    init_enemies(world);
    init_player(world);

    init_floor(world);
    world->room_state = 0;

    world->gameover = 0;
    world->score = 0;
    world->game_state = 0;
}


void clean_data(world_t *world){
    free_player(world);
    free_enemies(world);
    free_floor(world->floor);
}
