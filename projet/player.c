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
    world->player->atk_sprite_hori = malloc(sizeof(sprite_t));
    world->player->atk_sprite_verti = malloc(sizeof(sprite_t));

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

    //On initialise l'attaque du personnage
    int* atk_w_h = malloc(sizeof(int)*NB_COLUMN_SPRITE_SHEET_PLAYER_ATTACK);
    atk_w_h[0] = PLAYER_ATTACK_HORI_WIDTH; 
    atk_w_h[1] = PLAYER_ATTACK_HORI_WIDTH;
    init_sprite(world->player->atk_sprite_hori, 0, 0, atk_w_h, PLAYER_ATTACK_HORI_HEIGHT, 0);
    set_invisible(world->player->atk_sprite_hori);

    int* atk_w_v = malloc(sizeof(int)*NB_COLUMN_SPRITE_SHEET_PLAYER_ATTACK);
    atk_w_v[0] = PLAYER_ATTACK_VERTI_WIDTH; 
    atk_w_v[1] = PLAYER_ATTACK_VERTI_WIDTH;
    init_sprite(world->player->atk_sprite_verti, 0, 0, atk_w_v, PLAYER_ATTACK_VERTI_HEIGHT, 0);
    set_invisible(world->player->atk_sprite_verti);

    world->player->hp = PLAYER_HP; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_power = PLAYER_ATK_POWER; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->atk_speed = PLAYER_ATK_SPEED; //+ bonus écrit dans un fichier qui vient d'une partie précédente
    world->player->weapon_element = 0;
    world->player->animation_timer = 0;
    world->player->invincibility_timer = 0;
    world->player->is_invincible = 0;
}

void handle_anim_player(world_t * world) {
    if (world->player->animation_timer >= 1 && world->player->animation_timer < 21) { //21 = 5*4 + 1 car on fait un changement de sprite toutes les 4 boucles de jeu pour une animation lente et on a 6 sprites dans une animation (notés de 0 à 5) 
        if (world->player->animation_timer%4 == 0) {
            world->player->sprite->wich_img[1]++;
            //On fait avancer le joueur si on en train d'avancer et non pas en train d'attaquer
            switch(world->player->sprite->wich_img[0]) {
                case 0 :
                    world->player->sprite->y += world->player->sprite->v/7;
                    //Je change temporairement le sprite en celui qui est le plus large sprite de marche pour éviter que le personnage reste coincé contre le mur dans certaines circonstances
                    set_img_sprite(world->player->sprite, 6, world->player->sprite->wich_img[1]);
                    if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                        world->player->sprite->y -= world->player->sprite->v/7;
                    }
                    //Je le remets dans son êtat normal
                    set_img_sprite(world->player->sprite, 0, world->player->sprite->wich_img[1]);
                    break;

                case 2 :
                    world->player->sprite->x += world->player->sprite->v/7;
                    //Je change temporairement le sprite en celui qui est le plus large sprite de marche pour éviter que le personnage reste coincé contre le mur dans certaines circonstances
                    set_img_sprite(world->player->sprite, 6, world->player->sprite->wich_img[1]);
                    if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                        world->player->sprite->x -= world->player->sprite->v/7;
                    }
                    //Je le remets dans son êtat normal
                    set_img_sprite(world->player->sprite, 2, world->player->sprite->wich_img[1]);
                    break;

                case 4 :
                    world->player->sprite->x -= world->player->sprite->v/7;
                    //Je change temporairement le sprite en celui qui est le plus large sprite de marche pour éviter que le personnage reste coincé contre le mur dans certaines circonstances
                    set_img_sprite(world->player->sprite, 6, world->player->sprite->wich_img[1]);
                    if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                        world->player->sprite->x += world->player->sprite->v/7;
                    }
                    //Je le remets dans son êtat normal
                    set_img_sprite(world->player->sprite, 4, world->player->sprite->wich_img[1]);
                    break;

                case 6 :
                    world->player->sprite->y -= world->player->sprite->v/7;
                    //Le sprite est déjà le plus large, il n'est donc pas nécessaire de le changer
                    if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                        world->player->sprite->y += world->player->sprite->v/7;
                    }
                    break;
            }
        }
        world->player->animation_timer++;
    }
    else { //bug se remet à son état initial après chaque action, tenter avec un else if
        set_img_sprite(world->player->sprite, world->player->sprite->wich_img[0], 2); //On remet le sprite dans une position détente après son attaque (le -1 c'est parce que la colonne détente est à indice -1 de la colonne attaque)
        set_invisible(world->player->atk_sprite_hori);
        set_invisible(world->player->atk_sprite_verti);
    }
}

void free_player(world_t* world) {
    free(world->player->sprite->w);
    free(world->player->sprite->wich_img);
    free(world->player->sprite);
    free(world->player->atk_sprite_hori->w);
    free(world->player->atk_sprite_hori->wich_img);
    free(world->player->atk_sprite_hori);
    free(world->player->atk_sprite_verti->w);
    free(world->player->atk_sprite_verti->wich_img);
    free(world->player->atk_sprite_verti);
    free(world->player);
}