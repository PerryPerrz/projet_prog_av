/**
 * \file enemy.h
 * \brief Programme déclarant les fonctions relatives aux monstres
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 24 novembre 2020
 */

#ifndef init_enemies
#include "database.h"


/**
 * \brief Hauteur des ennemis de type 1 (slime)
 */

#define ENEMY_1_HEIGHT 24

/**
 * \brief Largeur des ennemis de type 1 (slime)
 */

#define ENEMY_1_WIDTH 42

/**
 * \brief Vitesse des ennemis de type 1
*/

#define ENEMY_1_SPEED 1

/**
 * \brief Points de vie des ennemis de type 1
*/

#define ENEMY_1_HP 51

/**
 * \brief Dégats des ennemis de type 1
*/

#define ENEMY_1_ATK_POWER 5

/**
 * \brief Vitesse d'attaque des ennemis de type 1
*/

#define ENEMY_1_ATK_SPEED 1

/**
 * \brief Nombre d'ennemis maximum
*/

#define NB_ENEMIES_MAX 10

/**
 * \brief La distance entre l'apparition des monstres et le joueur au début d'une salle
*/

#define SPAWN_DISTANCE 100

/**
 * \brief La procédure initialise les ennemis
 * \param world Les données du monde
 */
void init_enemies(world_t* world);

/**
 * \brief La procédure crée les ennemis d'une salle
 * \param world Les données du monde
 */
void create_enemies(world_t* world);

/**
 * \brief La procédure nettoie les ennemis
 * \param world Les données du monde
 */
void free_enemies(world_t* world);

/**
 * \brief Procédure qui mets à jour les données des ennemis.
 * \param world Données du monde.
 */
void update_enemies(world_t* world);

#endif
