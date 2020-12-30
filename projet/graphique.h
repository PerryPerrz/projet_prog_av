/**
 * \file graphique.h
 * \brief Programme déclarant les fonctions graphiques
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 30 avril 2020
 */
 
#ifndef apply_sprite
#include "database.h"

/**
 * \brief Ecart entre les lignes d'une sprite sheet
 */
#define SPACE_BETWEEN_ROWS 26

/**
 * \brief Ecart entre les colonnes d'une sprite sheet
 */
#define SPACE_BETWEEN_COLUMNS 5


/**
 * \brief Représentation pour stocker les ressources nécessaires à l'affichage graphique des salles
*/

struct room_resources_s{
    SDL_Texture* background;            /*!< Texture liée à l'image du fond de l'écran */
    SDL_Texture* door_down_close;       /*!< Texture liée à l'image de la porte du bas fermée */
    SDL_Texture* door_up_close;         /*!< Texture liée à l'image de la porte du haut fermée */
    SDL_Texture* door_down_open;        /*!< Texture liée à l'image de la porte du bas fermée */
    SDL_Texture* door_up_open;          /*!< Texture liée à l'image de la porte du haut fermée */
    SDL_Texture* door_right_close;      /*!< Texture liée à l'image de la porte de droite fermée */ 
    SDL_Texture* door_right_open;       /*!< Texture liée à l'image de la porte de droite ouvert */  
    SDL_Texture* door_left_close;       /*!< Texture liée à l'image de la porte de gauche fermée */
    SDL_Texture* door_left_open;        /*!< Texture liée à l'image de la porte de gauche ouverte */
    SDL_Texture* wall_down;             /*!< Texture liée à l'image du mur du bas */
    SDL_Texture* wall_up;               /*!< Texture liée à l'image du mur du haut */
    SDL_Texture* wall_right;            /*!< Texture liée à l'image du mur de droite */ 
    SDL_Texture* wall_left;             /*!< Texture liée à l'image du mur de gauche */
};

/**
 * \brief Type qui correspond aux ressources du jeu
*/

typedef struct room_resources_s room_resources_t;


/**
 * \brief Représentation pour stocker les ressources nécessaires à l'affichage graphique
*/

struct resources_s{
    room_resources_t* room;             /*!< Textures liées à l'image de la salle */
    SDL_Texture* player;                /*!< Texture liée à l'image du personnage. */
    SDL_Texture* player_attack_hori;    /*!< Texture liée à l'image de l'attaque du personnage (forme horizontale) */
    SDL_Texture* player_attack_verti;    /*!< Texture liée à l'image de l'attaque du personnage (forme verticale)*/   
    SDL_Texture* slime;                 /*!< Texture liée à l'image des slimes. */
};

/**
 * \brief Type qui correspond aux ressources du jeu
*/

typedef struct resources_s resources_t;



/**
 * \brief La procédure applique une texture sur le renderer à sa position
 * \param renderer Le renderer actuel
 * \param texture La texture à appliquer
 * \param sprite Le sprite dont on doit appliquer la texture
*/
void apply_sprite(SDL_Renderer * renderer, SDL_Texture * texture, sprite_t * sprite);


/**
 * \brief La fonction initialise les texures
 * \param screen la surface correspondant à l'écran de jeu
 * \param resources les ressources du jeu
*/
void  init_resources(SDL_Renderer *renderer, resources_t *resources);


/**
 * \brief La fonction nettoie les ressources
 * \param resources les ressources
*/
void clean_resources(resources_t *resources);


/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param resources les ressources du jeu
*/
void apply_background(SDL_Renderer *renderer, resources_t *resources);


/**
 * \brief La procédure applique une texture sur le renderer à une position donnée en paramètres
 * \param renderer Le renderer actuel
 * \param texture La texture à appliquer
 * \param x la coordonnée en abscisse de l'endroit où on compte afficher la texture
 * \param y la coordonnée en ordonnée de l'endroit où on compte afficher la texture
*/
void apply_part_of_background(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);


/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param resources les ressources
 */
void refresh_graphics(SDL_Renderer *renderer, world_t *world,resources_t *resources);


/**
 * \brief La fonction s'occupe de l'affichage des portes et murs sur les côtés
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param resources les ressources
 */
void refresh_room(SDL_Renderer *renderer, world_t *world, resources_t *resources);


/**
 * \brief La fonction applique les monstres sur le renderer
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param resources les ressources
 */
void apply_monsters(SDL_Renderer* renderer, world_t* world, resources_t* resources);

#endif