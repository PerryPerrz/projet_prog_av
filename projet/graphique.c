/**
 * \file graphique.c
 * \brief Programme définissant les fonctions déclarées dans graphique.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 30 avril 2020
 */
 
#include "graphique.h"


void apply_sprite(SDL_Renderer * renderer, SDL_Texture * texture, sprite_t * sprite){
    if (sprite->is_visible == 0)
    {
        SDL_Rect SrcR; //On donne les coordonnées de l'image que l'on veut utiliser sur la sprite cheet
        SrcR.w = sprite->w[sprite->wich_img[0]];
        SrcR.h = sprite->h;
        SrcR.x = sprite->wich_img[0] /* * (SPACE_BETWEEN_COLUMNS + sprite->w[sprite->wich_img[0]]) mache pas à changer */;
        SrcR.y = sprite->wich_img[1] /* * (SPACE_BETWEEN_ROWS + sprite->h) idem */ ;

        apply_image(texture, renderer, SrcR, sprite->x - (sprite->h/2), sprite->y - (sprite->w[sprite->wich_img[0]]/2)); //On donne les coordonnées du coin en haut à gauche du sprite à partir du centre du sprite
    }
}

void apply_resized_sprite(SDL_Renderer * renderer, SDL_Texture * texture, sprite_t * sprite, int f){
    if (sprite->is_visible == 0)
    {
        SDL_Rect SrcR; //On donne les coordonnées de l'image que l'on veut utiliser sur la sprite cheet
        SrcR.w = sprite->w[sprite->wich_img[0]];
        SrcR.h = sprite->h;
        SrcR.x = sprite->wich_img[0] /* * (SPACE_BETWEEN_COLUMNS + sprite->w[sprite->wich_img[0]]) mache pas à changer */;
        SrcR.y = sprite->wich_img[1] /* * (SPACE_BETWEEN_ROWS + sprite->h) idem */  ;

        apply_resized_image(texture, renderer, SrcR, sprite->x - (sprite->h/2), sprite->y - (sprite->w[sprite->wich_img[0]]/2), f); //On donne les coordonnées du coin en haut à gauche du sprite à partir du centre du sprite
    }
}

void  init_resources(SDL_Renderer *renderer, resources_t *resources){
    resources->background = load_image("ressources/background1.bmp",renderer);
    resources->player = load_transparent_image("ressources/chest_closed.bmp", renderer,230,80,235);
    //resources->ammo = load_transparent_image("ressources/ammo.bmp", renderer,230,80,235);
    resources->slime = load_transparent_image("ressources/slime.bmp", renderer,230,80,235);
}

void clean_resources(resources_t *resources){
    clean_image(resources->background);
    clean_image(resources->player);
    //clean_image(resources->ammo);
    clean_image(resources->slime);
}


void apply_background(SDL_Renderer *renderer, resources_t *resources){
    if(resources->background != NULL){
        SDL_Rect SrcR = {0, 0, 0, 0};
        SDL_QueryTexture(resources->background, NULL, NULL, &SrcR.w, &SrcR.h);  //On demande directement les dimensions du background
        SrcR.w *= 2;
        SrcR.h *= 2;
        apply_image(resources->background, renderer, SrcR, 0, 0);
    }
}


void refresh_graphics(SDL_Renderer *renderer, world_t *world,resources_t *resources){
    
    //on vide le renderer
    SDL_RenderClear(renderer);
    
    //application des ressources dans le renderer
    apply_background(renderer, resources);
    apply_sprite(renderer, resources->player, world->player->sprite);

    //apply_sprite(renderer, resources->ammo, world->ammo);
    
    apply_monsters(renderer, world, resources);


    // on met à jour l'écran    
    SDL_RenderPresent(renderer);
}

void apply_monsters(SDL_Renderer* renderer, world_t* world, resources_t* resources) {
    //applications des monstres dans le renderer
    for (int i = 0; i < world->nb_enemies; i++) {
        switch (world->enemies[i]->type) 
        {
            case 1:
                apply_resized_sprite(renderer, resources->slime, world->enemies[i]->sprite, 2);
                world->enemies[i]->sprite->h *= 2;  //à mettre dans une fonction
                world->enemies[i]->sprite->w[0] *= 2; //idem
                break;
        }
    }
}