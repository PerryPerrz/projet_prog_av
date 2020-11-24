/**
 * \file update.h
 * \brief Programme déclarant les fonctions utilisées pour mettre à jour les données à chaque boucle de jeu
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 24 Novembre 2020
 */
  
#ifndef update_data
#include "database.h"
#include "enemy.h"
#include <math.h>


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param world données du monde
 */
void update_data(world_t *world);


/**
 * \brief Fonction qui vérifie si deux sprites sont en collision.
 * \param sp1 sprite n°1
 * \param sp2 sprite n°2
 * \return 1 en cas de collision et 0 en cas de non-collision
 */
int sprites_collide(sprite_t *sp2, sprite_t *sp1);


/**
 * \brief Procédure qui annule la vitesse de deux sprites en collision et qui les rends invisible.
 * \param sp1 sprite n°1
 * \param sp2 sprite n°2
 */
void handle_sprites_collision(sprite_t *sp2, sprite_t *sp1);


/**
 * \brief Procédure qui gère la collision entre un objet et le joueur.
 * \param sp1 sprite n°1 (objet)
 * \param sp2 sprite n°2
 */
void handle_item_collision(sprite_t *item, sprite_t *sp);


/**
 * \brief Procédure qui print les données d'un sprite
 * \param sprite Le sprite dont on veut afficher les données
 */
void print_sprite(sprite_t * sprite);


/**
 * \brief Procédure qui implémente les règles du jeu.
 * \param world Données du monde.
 */
void compute_game(world_t *world);


#endif