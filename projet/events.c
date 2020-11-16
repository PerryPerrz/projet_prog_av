/**
 * \file events.c
 * \brief Programme définissant les fonctions déclarées dans events.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 27 mai 2020
 */
 
#include "events.h"


void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
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
                world->player->y += PLAYER_SPEED;
                break;
            case SDLK_DOWN:
                world->player->y -= PLAYER_SPEED;
                break;
            case SDLK_RIGHT:
                world->player->y += PLAYER_SPEED;
                break;
            case SDLK_LEFT:
                world->player->y -= PLAYER_SPEED;
                break;

            case SDLK_SPACE:
                //active un objet actif
                break;
                
            case SDLK_e:
                //ramasse un objet actif proche du personnage
                break;
            default:
                break;
            }
        
        case SDL_MOUSEBUTTONDOWN:
            switch (event->button.button)
            {
            case SDL_BUTTON_LEFT:
                //Le joueur effectue une attaque
                break;
            case SDL_BUTTON_RIGHT:
                //Le joueur effectue une roulade
                break;
            default:
                break;
            }
        
        default:
            break;
        }
    }
}