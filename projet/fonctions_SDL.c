/**
 * \file fonctions_SDL.c
 * \brief Programme déclarant la fonction charger_image
 * \author IOPETI Hugo
 * \author YVOZ Ludovic
 * \date 21 septembre 2020
 */

#include "fonctions_SDL.h"

SDL_Texture *load_image(const char *file_name, SDL_Renderer *renderer){
    SDL_Surface *image = SDL_LoadBMP(file_name);
    return SDL_CreateTextureFromSurface(renderer, image);
}

SDL_Texture *load_transparent_image(const char *file_name, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b){
    SDL_Surface *image_tr = SDL_LoadBMP(file_name);
    Uint32 color = SDL_MapRGB(image_tr->format, r, g, b);
    SDL_SetColorKey(image_tr, SDL_TRUE, color);
    return SDL_CreateTextureFromSurface(renderer, image_tr);
}

SDL_Texture *load_text(const char *message, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color){
    SDL_Surface *image_txt = TTF_RenderText_Solid(font, message, color);
    return SDL_CreateTextureFromSurface(renderer, image_txt);
}

void clean_image(SDL_Texture* image) {
    if (image != NULL) {
        SDL_DestroyTexture(image);
    }
}

void apply_image(SDL_Texture* image, SDL_Renderer* renderer, SDL_Rect SrcR, int x, int y) {
    SDL_Rect DestR = SrcR;

    DestR.x = x; //On choisit les coordnonnées de l'endroit où on affiche le sprite sur la fenêtre
    DestR.y = y;

    SDL_RenderCopy(renderer, image, &SrcR, &DestR);
}