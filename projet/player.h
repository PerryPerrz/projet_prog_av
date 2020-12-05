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

#define PLAYER_HEIGHT 38

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_1_WIDTH 31

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_2_WIDTH 41

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_3_WIDTH 25

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_4_WIDTH 40

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_5_WIDTH 16

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_6_WIDTH 16

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_7_WIDTH 16

/**
 * \brief Largeur du personnage pour les sprites de la colonne 1 du sprite sheet
 */

#define PLAYER_SPRITE_COLUMN_8_WIDTH 16

/**
 * \brief Vitesse du personnage
*/

#define PLAYER_SPEED 20

/**
 * \brief Nombres de sprites sur la sprite cheet du personnage
*/

#define NB_SPRITES_PLAYER 48

/**
 * \brief Nombres de colonnes de sprites sur la sprite cheet du personnage
*/

#define NB_COLUMN_SPRITE_SHEET_PLAYER 8


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