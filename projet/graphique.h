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
 * \brief Représentation pour stocker les ressources nécessaires à l'affichage graphique
*/

struct resources_s{
    SDL_Texture* background;            /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* player;                /*!< Texture liée à l'image du personnage. */
    SDL_Texture* ammo;                  /*!< Texture liée à l'image des munitions. */
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
 * \brief La procédure applique une texture sur le renderer à sa position
 * \param renderer Le renderer actuel
 * \param texture La texture à appliquer
 * \param sprite Le sprite dont on doit appliquer la texture
 * \param f facteur de changement de taille (négatif : réduction de taille / positif : augmantation de taille)
 * \return La nouvelle hauteur et la nouvelle largeur du sprite sous forme de tableau d'entiers.
*/
int* apply_resized_sprite(SDL_Renderer * renderer, SDL_Texture * texture, sprite_t * sprite, int f);


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
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param resources les ressources
 */
void refresh_graphics(SDL_Renderer *renderer, world_t *world,resources_t *resources);

/**
 * \brief La fonction applique les monstres sur le renderer
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param resources les ressources
 */
void apply_monsters(SDL_Renderer* renderer, world_t* world, resources_t* resources);

#endif