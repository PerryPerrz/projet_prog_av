/**
 * \file fonctions_SDL.c
 * \brief Programme déclarant la fonction charger_image
 * \author IOPETI Hugo
 * \date 21 septembre 2020
 */

#include "fonctions_SDL.h"

SDL_Texture *charger_image(const char *nomfichier, SDL_Renderer *renderer)
{
    SDL_Surface *image = SDL_LoadBMP(nomfichier);
    return SDL_CreateTextureFromSurface(renderer, image);
}

SDL_Texture *charger_image_transparente(const char *nomfichier, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Surface *image_tr = SDL_LoadBMP(nomfichier);
    Uint32 color = SDL_MapRGB(image_tr->format, r, g, b);
    SDL_SetColorKey(image_tr, SDL_TRUE, color);
    return SDL_CreateTextureFromSurface(renderer, image_tr);
}

SDL_Texture *charger_texte(const char *message, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color)
{
    SDL_Surface *image_txt = TTF_RenderText_Solid(font, message, color);
    return SDL_CreateTextureFromSurface(renderer, image_txt);
}