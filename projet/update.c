/**
 * \file update.c
 * \brief Programme définissant les fonctions déclarées dans update.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 24 Novembre 2020
 */

#include "update.h"

void update_data(world_t *world){
    //mise à jour des déplacements des missiles etc.. à faire
    if (world->room_state == 0) {   //On génère de nouveaux monstres si on est dans une nouvelle salle
        create_enemies(world);
        create_missiles(world);
        world->player->is_invincible = 0;   //On rends le joueur invincible quand il rentre dans une salle pour éviter de mourir sans pouvoir réagir
        world->player->invincibility_timer = 1;
        world->room_state = 1;
    }
    //On gère les attaques du personnage et des ennemis
    handle_attacks(world);
    handle_invincibility(world);

    //On gère le fait de finir une salle
    if (nb_enemies_alive(world) == 0 && world->room_state == 1) {
        world->room_state = 2;
    }

    update_enemies(world);
    update_missiles(world);

    compute_game(world);
}

int sprites_collide(sprite_t *sp2, sprite_t *sp1)
{
    if (sqrt(pow((sp1->x - sp2->x), 2) + pow((sp1->y - sp2->y), 2)) <= (sp1->h + sp2->h)/2)
    {
        return 1;
    }
    return 0;
}

void handle_attacks(world_t* world) {
    for (int i = 0; i < world->nb_enemies; i++) {

        //On gère le fait que le joueur attaque un monstre
        if (world->enemies[i]->sprite->is_visible == 0 && world->enemies[i]->is_invincible == 1) {
            if ((sprites_collide(world->player->atk_sprite_hori, world->enemies[i]->sprite) == 1 && world->player->atk_sprite_hori->is_visible == 0) || (sprites_collide(world->player->atk_sprite_verti, world->enemies[i]->sprite) == 1 && world->player->atk_sprite_verti->is_visible == 0)) {
                world->enemies[i]->hp -= world->player->atk_power;
                if (world->enemies[i]->hp <= 0) {
                    set_invisible(world->enemies[i]->sprite);
                    //Si une tourelle meurt, son missile disparait avec
                    if (world->enemies[i]->type == 3) {
                        for (int j = 0; j < world->nb_missiles; j++) {
                            if (world->missiles[j]->nb_turret == i) {
                                set_invisible(world->missiles[j]->sprite);
                            }
                        }
                    }
                }
                //On le rends invincible pendant un cours instant pour éviter que le joueur abuse de sa vitesse d'attaque
                world->enemies[i]->is_invincible = 0;
                world->enemies[i]->invincibility_timer = 1;   
            }
        }

        //On gère le fait qu'un monstre attaque le joueur
        if(sprites_collide(world->enemies[i]->sprite, world->player->sprite) == 1 && world->enemies[i]->sprite->is_visible == 0 && world->player->is_invincible == 1) {
            world->player->hp -= world->enemies[i]->atk_power;
            if (world->player->hp <= 0) {
                world->gameover = 1;
            }
            //On le rends invincible pendant un court instant pour simuler la vitesse d'attaque des monstres
            world->player->is_invincible = 0;
            world->player->invincibility_timer = world->enemies[i]->atk_speed; 
        }
    }

    
    for (int i = 0; i < world->nb_missiles; i++) {
    //On gère le fait que le joueur attaque un missile
        if (world->missiles[i]->sprite->is_visible == 0) {
            if ((sprites_collide(world->player->atk_sprite_hori, world->missiles[i]->sprite) == 1 && world->player->atk_sprite_hori->is_visible == 0) || (sprites_collide(world->player->atk_sprite_verti, world->missiles[i]->sprite) == 1 && world->player->atk_sprite_verti->is_visible == 0)) {
                set_invisible(world->missiles[i]->sprite);
                world->missiles[i]->timer_missile = 1;  //On reset le timer du missile pour que le joueur ait le temps de s'approcher des tourelles
            }
        }

        //On gère le fait qu'un missile touche le joueur
        if (sprites_collide(world->player->sprite, world->missiles[i]->sprite) == 1 && world->player->is_invincible == 1 && world->missiles[i]->sprite->is_visible == 0) {
            world->player->hp -= world->missiles[i]->atk_power;
            set_invisible(world->missiles[i]->sprite);
            world->missiles[i]->timer_missile = 1;  //On reset le timer du missile pour que le joueur ait le temps de s'approcher des tourelles
            if (world->player->hp <= 0) {
                world->gameover = 1;
            }
            //On le rends invincible pendant un court instant pour simuler la vitesse d'attaque des monstres
            world->player->is_invincible = 0;
            world->player->invincibility_timer = 1; //Le joueur est invincible pendant pas mal de temps car il à pris un gros coup
        }

        
    }

    

}

void handle_invincibility(world_t* world) {
    //On gère l'invicibilité du joueur
    if (world->player->invincibility_timer >= 1 && world->player->invincibility_timer <= 150) {
        world->player->invincibility_timer += 1;
    }
    else {
        world->player->invincibility_timer = 0;
        world->player->is_invincible = 1;
    }

    //On gère l'invicibilité des monstres
    for (int i = 0; i < world->nb_enemies; i++) {
        if (world->enemies[i]->invincibility_timer >= 1 && world->enemies[i]->invincibility_timer < 22) { //Presque le même temps que les attaques du joueur restent à l'écran pour ne pas prendre plusieurs coups avec une seule attaque
            world->enemies[i]->invincibility_timer += 1;
        }
        else {
            world->enemies[i]->invincibility_timer = 0;
            world->enemies[i]->is_invincible = 1;
        }
    }
}


void handle_item_collision(sprite_t *item, sprite_t *sp)
{
    if (sprites_collide(sp, item) == 1 && sp->is_visible == 0 && item->is_visible == 0)
    {
        set_invisible(item);
    }
}

void print_sprite(sprite_t * sprite)
{
    printf("x = %d\ny = %d\nh = %d\nw = %d\nv = %d\n",
        sprite->x,sprite->y,sprite->h,sprite->w[sprite->wich_img[0]],sprite->v);
}

void compute_game(world_t *world)
{
    //Pour l'instant pas de score d'implémenté etc...
}

int nb_enemies_alive(world_t* world) {
    int nb_enemies_alive = 0;
    for (int i = 0; i < world->nb_enemies; i++) {
        if (world->enemies[i]->sprite->is_visible == 0) {
            nb_enemies_alive++;
        }
    }
    return nb_enemies_alive;
}