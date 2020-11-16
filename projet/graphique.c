/**
 * \file graphique.c
 * \brief Programme définissant les fonctions déclarées dans graphique.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 30 avril 2020
 */
 
#include "graphique.h"


void apply_sprite(SDL_Renderer * renderer, SDL_Texture * texture, sprite_t * sprite)
{
    if (sprite->is_visible == 0)
    {
        apply_image(texture, renderer, sprite->x - (sprite->h/2), sprite->y - (sprite->w/2)); //On donne les coordonnées du coin en haut à gauche du sprite à partir du centre du sprite
    }
}

void  init_resources(SDL_Renderer *renderer, resources_t *resources){
    resources->background = load_image("ressources/background.bmp",renderer);
    resources->player = load_transparent_image("ressources/player.bmp", renderer,70,51,45);
    resources->ammo = load_transparent_image("ressources/ammo.bmp", renderer,70,51,45);
}

void clean_resources(resources_t *resources){
    clean_image(resources->background);
    clean_image(resources->player);
    clean_image(resources->ammo);
}


void apply_background(SDL_Renderer *renderer, resources_t *resources){
    if(resources->background != NULL){
      apply_texture(resources->background, renderer, 0, 0);
    }
}


void refresh_graphics(SDL_Renderer *renderer, world_t *world,resources_t *resources){
    
    //on vide le renderer
    SDL_RenderClear(renderer);
    
    //application des ressources dans le renderer
    apply_background(renderer, resources);
    apply_sprite(renderer, resources->player, world->player);
    apply_sprite(renderer, resources->ammo, world->ammo);
    
    // on met à jour l'écran
    update_screen(renderer);
}