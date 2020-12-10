/**
 * \file events.c
 * \brief Programme définissant les fonctions déclarées dans events.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 27 mai 2020
 */
 
#include "events.h"


void handle_events(SDL_Event *event,world_t *world){
    while( SDL_PollEvent( event ) ) {
        switch (event->type)
        {
        case SDL_QUIT:
            world->gameover = 1;
            break;

        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
            case SDLK_ESCAPE:
                //Ouvrir un menu peut-être
                break;

            case SDLK_UP:
                //pareil que pour z
            case SDLK_z:
                world->player->sprite->y -= world->player->sprite->v;
                if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                    world->player->sprite->y += world->player->sprite->v;
                }

                //animation perso
                world->player->sprite->wich_img[0] = 6;
                world->player->sprite->wich_img[1] = 0;
                break;
                
            case SDLK_DOWN:
            //pareil que pour s
            case SDLK_s:
                world->player->sprite->y += world->player->sprite->v;
                if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                    world->player->sprite->y -= world->player->sprite->v;
                }

                //animation perso
                world->player->sprite->wich_img[0] = 0;
                world->player->sprite->wich_img[1] = 0;
                break;
               
            case SDLK_RIGHT:
            //pareil que pour d
            case SDLK_d:
                world->player->sprite->x += world->player->sprite->v;
                if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                    world->player->sprite->x -= world->player->sprite->v;
                }

                //animation perso
                world->player->sprite->wich_img[0] = 2;
                world->player->sprite->wich_img[1] = 0;
                break;
               
            case SDLK_LEFT:
            //pareil que pour q    
            case SDLK_q:
                world->player->sprite->x -= world->player->sprite->v;
                if (sprite_is_out_of_bounds(world->player->sprite) == 0) {
                    world->player->sprite->x += world->player->sprite->v;
                }

                //animation perso
                world->player->sprite->wich_img[0] = 4;
                world->player->sprite->wich_img[1] = 0;
                break;

            case SDLK_SPACE:
                //active un objet actif
                break;
                
            case SDLK_e:
                //ramasse un objet proche du personnage
                break;
            default:
                break;
            }
        
        case SDL_MOUSEBUTTONDOWN:
            switch (event->button.button)
            {
            case SDL_BUTTON_LEFT:
                //Le joueur effectue une attaque
                //animation perso
                break;
            case SDL_BUTTON_RIGHT:
                //Le joueur effectue un bond en avant
                //animation perso
                break;
            default:
                break;
            }
        
        default:
            break;
        }
    }
}