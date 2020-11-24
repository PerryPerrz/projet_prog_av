/**
 * \file enemy.C
 * \brief Programme définnissant les fonctions déclarées dans enemy.h
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 24 novembre 2020
 */

#include "enemy.h"


void init_ennemies(world_t* world) {
    world->enemies = malloc(sizeof(monster_t)*NB_ENEMIES_MAX);
    for (int i = 0; i < NB_ENEMIES_MAX; i++) {
        world->enemies[i]->sprite = malloc(sizeof(sprite_t));
    }
}

void create_enemies(world_t* world) {
    int nb_enemies = generate_number(2,NB_ENEMIES_MAX);
    int type; // 1 seul pour l'instant 
    for (int i = 0; i < nb_enemies; i++) {
        type = generate_number(1,2);
        switch (type) {
        case 1:
            init_sprite(world->enemies[i]->sprite, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ENEMY_1_SIZE, ENEMY_1_SIZE, ENEMY_1_SPEED);
            world->enemies[i]->hp = ENEMY_1_HP; //+ bonus selon l'étage actuel
            world->enemies[i]->atk_power = ENEMY_1_ATK_POWER; //+ bonus selon l'étage actuel
            world->enemies[i]->atk_speed = ENEMY_1_ATK_SPEED;
            world->enemies[i]->type = 1;
            break;

            //à développer

        default:
            break;
        }
    }
}

void clear_enemies(world_t* world) {
}

void update_enemies(world_t* world)
{
    for (int i = 0; i < NB_ENEMIES_MAX; ++i)
    {
        //déplacement des ennemis à faire
    }
}