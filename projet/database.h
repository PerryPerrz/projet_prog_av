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
#include <stdio.h>


/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 700

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 400  

/**
 * \brief Coordonnée x du mur droit de la zone de jeu 
 */
#define PLAY_ZONE_RIGHT_WALL 573

/**
 * \brief Coordonnée x du mur gauche de la zone de jeu 
 */
#define PLAY_ZONE_LEFT_WALL 125

/**
 * \brief Coordonnée y du mur en haut de la zone de jeu 
 */
#define PLAY_ZONE_TOP_WALL 84  

/**
 * \brief Coordonnée y du mur en bas de la zone de jeu 
 */
#define PLAY_ZONE_BOTTOM_WALL 308

/**
 * \brief Taille des munitions
*/

#define AMMO_SIZE 8

/**
 * \brief Vitesse des munitions
*/

#define AMMO_SPEED 10

/**
 * \brief Représentation d'un sprite du jeu
*/

struct sprite_s
{
    int x;          /*!< Champ indiquant la position du centre du sprite (sur l'abscisse) */
    int y;          /*!< Champ indiquant la position du centre du sprite (sur l'ordonnée) */
    int h;          /*!< Champ indiquant la hauteur du sprite */
    int* w;         /*!< Champ indiquant la largeur du sprite (varie selon la colonne sur laquelle se trouve le sprite dans la sprite sheet) */
    int v;          /*!< Champ indiquant la vitesse verticale du sprite */
    int is_visible; /*!< Champ indiquant si le sprite est visible (0) ou invisible (1) */
    int* wich_img;  /*!< Champ indiquant quelle image doit être affichée pour le sprite à l'instant, [0] = n° sur l'axe x et [1] = n° sur l'axe y */
};

/**
 * \brief Type qui correspond à un sprite du jeu
 */

typedef struct sprite_s sprite_t;

struct character_s
{
    sprite_t *sprite;   /*!< Champ représentant le sprite du personnage */
    int hp;             /*!< Champ indiquant le nombre de points de vie du personnage */     
    int atk_power;      /*!< Champ indiquant la puissance d'attaque du personnage */
    int weapon;         /*!< Champ indiquant l'arme que tiens le personnage (1 = ... / 2 = ... / etc..) */
    int atk_speed;      /*!< Champ indiquant la vitesse d'attaque du personnage */
    int animation_timer;/*!< Champ indiquant le nombre de boucles nécessaires à l'animation du joueur */
};

/**
 * \brief Type qui correspond aux données du personnage du joueur
 */

typedef struct character_s character_t;

struct monster_s
{
    sprite_t *sprite;   /*!< Champ représentant le sprite du monstre */
    int hp;             /*!< Champ indiquant le nombre de points de vie du monstre */     
    int atk_power;      /*!< Champ indiquant la puissance d'attaque du monstre */
    int type;           /*!< Champ indiquant le type du monstre (1 = ... / 2 = ... / etc..) */
    int atk_speed;      /*!< Champ indiquant la vitesse d'attaque du monstre */
    int animation_timer;/*!< Champ indiquant le nombre de boucles nécessaires à l'animation du joueur */
};

/**
 * \brief Type qui correspond aux données des monstres
 */

typedef struct monster_s monster_t;

/**
 * \brief Représentation du monde du jeu
*/

struct world_s
{
    character_t *player;    /*!< Champ représentant le personnage du joueur */
    //sprite_t *ammo;         /*!< Champ représentant les munitions du joueur*/
    int gameover;           /*!< Champ indiquant si l'on est à la fin du jeu */
    monster_t **enemies;    /*!< Champ représentant les ennemis en jeu */
    int nb_enemies;         /*!< Champ représentant le nombre d'ennemis en jeu */
    int score;              /*!< Champ représentant le score du joueur */
    int game_state;         /*!< Champ représentant l'état de la partie en cours (1 = J perdu / 2 = E tous détruits / 3 = partie pas finie) */
    int room_state;         /*!< Champ représentant l'état de la salle actuelle (0 = entrée dans la salle / 1 = bataille en cours /2 = E tous détruits / etc... boos, shop,...) */             
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
 * \param w tableau contenant les largeurs des sprites selon leur position sur la sprite cheet
 * \param v la vitesse du sprite
 */
void init_sprite(sprite_t *sprite, int x, int y, int* w, int h, int v);

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


/**
 * \brief La fonction regarde si le sprite donné est en dehors de la zone de jeu
 * \param sprite Un sprite
 * \return Retourne 0 si vrai et 1 si faux
 */
int sprite_is_out_of_bounds(sprite_t* sprite);


/**
 * \brief La fonction change l'image affichée du sprite
 * \param sprite Un sprite
 * \param x Le n° de l'image sur l'axe des abscisses dans son sprite sheet
 * \param y Le n° de l'image sur l'axe des abscisses dans son sprite sheet
 */
void set_img_sprite(sprite_t* sprite, int x, int y);


#endif
