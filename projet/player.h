/**
 * \file player.h
 * \brief Programme déclarant les fonctions relatives au personnage du joueur
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 24 novembre 2020
 */

#ifndef init_player
#include "database.h"


/**
 * \brief Hauteur du personnage
 */

#define PLAYER_HEIGHT 32

/**
 * \brief Largeur du personnage
 */

#define PLAYER_WIDTH 16

/**
 * \brief Vitesse du personnage
*/

#define PLAYER_SPEED 20

/**
 * \brief Points de vie du personnage
*/

#define PLAYER_HP 3

/**
 * \brief Dégats du personnage
*/

#define PLAYER_ATK_POWER 50

/**
 * \brief Vitesse d'attaque du personnage
*/

#define PLAYER_ATK_SPEED 3

/**
 * \brief La procédure initialise le personnage du joueur
 * \param world Les données du monde
 */
void init_player(world_t* world);

#endif
