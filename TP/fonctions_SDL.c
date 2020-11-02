/**
 * \file fonctions_SDL.c
 * \brief Programme définissant la fonction charger_image
 * \author YVOZ Ludovic
 * \date 21 Septembre 2020
 */


#include "fonctions_SDL.h"

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer) {
    SDL_Surface* image = SDL_LoadBMP(nomfichier);
    return SDL_CreateTextureFromSurface(renderer, image);
}
