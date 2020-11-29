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
                world->player->sprite->y += world->player->sprite->v;
                //animation perso
                break;
            case SDLK_DOWN:
                world->player->sprite->y -= world->player->sprite->v;
                //animation perso
                break;
            case SDLK_RIGHT:
                world->player->sprite->y += world->player->sprite->v;
                //animation perso
                break;
            case SDLK_LEFT:
                world->player->sprite->y -= world->player->sprite->v;
                //animation perso
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