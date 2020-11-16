/**
 * \file fonctions_SDL.h
 * \brief Programme déclarant la fonction fonctions_SDL.h
 * \author IOPETI Hugo
 * \date 21 septembre 2020
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

/**
 * \brief Fonction qui charge une image et retourne la surface de texture
 * \param nomfichier Nom du fichier
 * \param renderer Le renderer
 * \return La surface de la texture chargée
 /
 */
SDL_Texture *charger_image(const char *nomfichier, SDL_Renderer *renderer);

/**
 * \brief Fonction qui charge une image transparente
 * \param nomfichier Nom du fichier
 * \param renderer Le renderer
 * \param renderer r codage rgb de R pour la couleur transparente
 * \param renderer g codage rgb de G pour la couleur transparente
 * \param renderer b codage rgb de B pour la couleur transparente
 * \return La surface de la texture chargée
 /
 */
SDL_Texture *charger_image_transparente(const char *nomfichier, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b);

/**
 * \brief Fonction qui charge le texte
 * \param message Le message à charger
 * \param renderer Le renderer
 * \param font La police du texte
 * \param color La couleur du texte
 * \return La surface de la texture chargée
 /
 */
SDL_Texture *charger_texte(const char *message, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color);