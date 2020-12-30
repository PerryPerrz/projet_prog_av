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
    int type, x_temp, y_temp, too_close; 
    int* w = malloc(sizeof(int)); //* nombre colonne du sprite sheet avec le plus de colonne des monstres
    for (int i = 0; i < world->nb_enemies; i++) {
        type = generate_number(1,2); // 1 seul pour l'instant 
        //On gère le fait de faire apparaitre les monstres au hasard sur l'écran et également le fait qu'un monstre ne peut pas apparaîte trop près du joueur
        too_close = 0;
        while(too_close == 0) {
            x_temp = generate_number(PLAY_ZONE_LEFT_WALL, PLAY_ZONE_RIGHT_WALL - ENEMY_1_HEIGHT/2);//hauteur du plus grand monstre
            y_temp = generate_number(PLAY_ZONE_TOP_WALL, PLAY_ZONE_BOTTOM_WALL - ENEMY_1_WIDTH/2);//largeur du plus large monstre
            if (!(x_temp < world->player->sprite->x + SPAWN_DISTANCE && x_temp > world->player->sprite->x - SPAWN_DISTANCE && y_temp < world->player->sprite->y + SPAWN_DISTANCE && y_temp < world->player->sprite->y - SPAWN_DISTANCE)) {
                too_close = 1;
            }
        }
        
        switch (type) {
            case 1:
                w[0] = ENEMY_1_WIDTH;
                init_sprite(world->enemies[i]->sprite, x_temp, y_temp, w, ENEMY_1_HEIGHT, ENEMY_1_SPEED);
                world->enemies[i]->hp = ENEMY_1_HP; //+ bonus selon l'étage actuel
                world->enemies[i]->atk_power = ENEMY_1_ATK_POWER; //+ bonus selon l'étage actuel
                world->enemies[i]->atk_speed = ENEMY_1_ATK_SPEED;
                world->enemies[i]->type = 1;
                break;

            //à développer

            default:
                break;
        }
        world->enemies[i]->animation_timer = 0;
        world->enemies[i]->invincibility_timer = 0;
        world->enemies[i]->is_invincible = 0;
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
        if (world->enemies[i]->type == 1) {
            int speed_restraint = generate_number(1,3); //On donne une chance sur deux aux monstres d'avancer pour qu'ils ne soient pas trop rapides et pour su'ils n'avancent pas tous à la même vitesse
            if (speed_restraint == 1) {
                //On fait avancer les monstres vers le joueur
                if (world->player->sprite->x > world->enemies[i]->sprite->x) {
                    world->enemies[i]->sprite->x += world->enemies[i]->sprite->v;
                }
                else {
                    world->enemies[i]->sprite->x -= world->enemies[i]->sprite->v;
                }
                if (world->player->sprite->y > world->enemies[i]->sprite->y) {
                    world->enemies[i]->sprite->y += world->enemies[i]->sprite->v;
                }
                else {
                    world->enemies[i]->sprite->y -= world->enemies[i]->sprite->v;
                }
            }
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