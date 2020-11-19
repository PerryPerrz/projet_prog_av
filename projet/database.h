/**
 * \file database.h
 * \brief Programme déclarant les constantes, structures et fonctions nécessaires à tous les modules
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 12 novembre 2020
 */

#ifndef SCREEN_WIDTH
#include "fonctions_SDL.h"
#include <time.h>

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 300

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 480

/**
 * \brief Taille du personnage
 */

#define PLAYER_SIZE 32

/**
 * \brief Taille des munitions
*/

#define AMMO_SIZE 8

/**
 * \brief Vitesse de l'ennemi
*/

#define ENNEMY_SPEED 2

/**
 * \brief Vitesse des munitions
*/

#define AMMO_SPEED 10

/**
 * \brief Vitesse du personnage
*/

#define PLAYER_SPEED 20

/**
 * \brief Nombre d'ennemis en jeu
*/

#define NB_ENEMIES 20

/**
 * \brief Nombre de boucles de jeu à faire avant de fermer la fenêtre de jeu (~2sec).
*/

#define NB_BOUCLES 200

/**
 * \brief Points de vie initiaux du boss.
*/

#define PV_INITIAL_BOSS 20

/**
 * \brief Représentation d'un sprite du jeu
*/

struct sprite_s
{
    int x;          /*!< Champ indiquant la position du centre du sprite (sur l'abscisse) */
    int y;          /*!< Champ indiquant la position du centre du sprite (sur l'ordonnée) */
    int h;          /*!< Champ indiquant la hauteur du sprite */
    int w;          /*!< Champ indiquant la largeur du sprite */
    int v;          /*!< Champ indiquant la vitesse verticale du sprite */
    int is_visible; /*!< Champ indiquant si le sprite est visible (0) ou invisible (1) */
    SDL_Rect SrcR;  /*!< Champ indiquant les coordonnées du sprite sur sa sprite sheet */
};

/**
 * \brief Type qui correspond à un sprite du jeu
 */

typedef struct sprite_s sprite_t;

/**
 * \brief Représentation du monde du jeu
*/

struct world_s
{
    sprite_t *player;   /*!< Champ représentant le personnage du joueur */
    sprite_t *ammo;     /*!< Champ représentant les munitions du joueur*/
    int gameover;       /*!< Champ indiquant si l'on est à la fin du jeu */
    sprite_t **enemies; /*!< Champ représentant les ennemis en jeu */
    int score;          /*!< Champ représentant le score du joueur */
    int etat_jeu;       /*!< Champ représentant l'état de la partie en cours (1 = J perdu / 2 = E tous détruits / 3 = partie pas finie) */
};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;

/**
 * \brief La procédure initialise les données d'un sprite
 * \param sprite le sprite à initialiser
 * \param x la position du centre du sprite (sur l'abscisse)
 * \param y la position du centre du sprite (sur l'ordonnée)
 * \param h la hauteur du sprite
 * \param w la largueur du sprites
 * \param v la vitesse verticale du sprite
 */
void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v);

/**
 * \brief Fonction qui génère un nombre aléatoire.
 * \param a Borne inférieure.
 * \param b Borne supérieure.
 * \return Un nombre compris entre \a a (inclus) et \a b (non-inclus).
 */
int generate_number(int a, int b);

/**
 * \brief La procédure rends le sprite visible
 * \param sprite le sprite à modifier
 */
void set_visible(sprite_t *sprite);

/**
 * \brief La procédure rends le sprite invisible
 * \param sprite le sprite à modifier
 */
void set_invisible(sprite_t *sprite);

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */
int is_game_over(world_t *world);

#endif
