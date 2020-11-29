/**
 * \file enemy.C
 * \brief Programme définnissant les fonctions déclarées dans enemy.h
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 24 novembre 2020
 */

#include "enemy.h"


void init_enemies(world_t* world) {
    world->enemies = malloc(sizeof(monster_t*)*NB_ENEMIES_MAX);
    for (int i = 0; i < NB_ENEMIES_MAX; i++) {
        world->enemies[i] = malloc(sizeof(monster_t));
        world->enemies[i]->sprite = malloc(sizeof(sprite_t));
    }
}

void create_enemies(world_t* world) {
    world->nb_enemies = generate_number(2,NB_ENEMIES_MAX);
    int type; 
    for (int i = 0; i < world->nb_enemies; i++) {
        type = generate_number(1,2); // 1 seul pour l'instant 
        switch (type) {
        case 1:
            init_sprite(world->enemies[i]->sprite, SCREEN_WIDTH / 4, SCREEN_HEIGHT /3, ENEMY_1_WIDTH, ENEMY_1_HEIGHT, ENEMY_1_SPEED);
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

void free_enemies(world_t* world) {
    for (int i = 0; i < NB_ENEMIES_MAX; i++) {
        free(world->enemies[i]->sprite);
        free(world->enemies[i]);
    }
    free(world->enemies);
}

void update_enemies(world_t* world)
{
    for (int i = 0; i < world->nb_enemies; ++i)
    {
        if (world->enemies[i]->type == 0) {
            //Faire avancer le monstre vers le perso avec l'algorithme de pathfinding pour tous les monstres de corps à corps
        }
        else {
            //Monstres à distance se déplaçant au hasard
            int direction = generate_number(1,5);
            switch (direction)
            {
            case 1:
                world->enemies[i]->sprite->x += world->enemies[i]->sprite->v;
                if (sprite_is_out_of_bounds(world->enemies[i]->sprite) == 0) {
                    world->enemies[i]->sprite->x -= world->enemies[i]->sprite->v;
                }
                break;
            
            case 2:
                world->enemies[i]->sprite->x -= world->enemies[i]->sprite->v;
                if (sprite_is_out_of_bounds(world->enemies[i]->sprite) == 0) {
                    world->enemies[i]->sprite->x += world->enemies[i]->sprite->v;
                }
                break;

            case 3:
                world->enemies[i]->sprite->y += world->enemies[i]->sprite->v;
                if (sprite_is_out_of_bounds(world->enemies[i]->sprite) == 0) {
                    world->enemies[i]->sprite->y -= world->enemies[i]->sprite->v;
                }
                break;

            case 4:
                world->enemies[i]->sprite->y -= world->enemies[i]->sprite->v;
                if (sprite_is_out_of_bounds(world->enemies[i]->sprite) == 0) {
                    world->enemies[i]->sprite->y += world->enemies[i]->sprite->v;
                }
                break;
            }
        }
    }
}