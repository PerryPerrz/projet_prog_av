/**
 * \file fonctions_SDL.h
 * \brief Programme déclarant la fonction charger_image
 * \author YVOZ Ludovic
 * \date 21 Septembre 2020
 */


#include <SDL2/SDL.h>
#include <stdio.h>

/**
 * \brief Fonction qui charge une image et retourne la surface de texture
 * \param nomfichier Nom du fichier
 * \param renderer Le renderer
 * \return La surface de la texture chargée
 */
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer) ;