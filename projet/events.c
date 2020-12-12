/**
 * \file events.c
 * \brief Programme définissant les fonctions déclarées dans events.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 27 mai 2020
 */
 
#include "events.h"


void handle_events(SDL_Event *event,world_t *world){
    float distance_x, distance_y;
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
                world->player->animation_timer = 1;
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
                world->player->animation_timer = 1;
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
                world->player->animation_timer = 1;
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
                world->player->animation_timer = 1;
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
            distance_x = sqrt(pow(world->player->sprite->x - event->motion.x,2));   //La distance entre le "x" du joueur et le "x" de la souris
            distance_y = sqrt(pow(world->player->sprite->y - event->motion.y,2));   //La distance entre le "y" du joueur et le "y" de la souris

              if(distance_x >= distance_y){  //On sait que le curseur de la sourie est plus sur un des deux cotés du personnage que en bas ou en haut du personnage
                    if(event->motion.x <= world->player->sprite->x){ //On sait que le curseur est à gauche du personnage
                        world->player->sprite->wich_img[0] = 5;
                        world->player->sprite->wich_img[1] = 0;
                        world->player->animation_timer = 1;
                    }
                    else{   //On sait que le curseur est à droite du personnage
                        world->player->sprite->wich_img[0] = 3;
                        world->player->sprite->wich_img[1] = 0;
                        world->player->animation_timer = 1;
                    }
               }
               else{
                    if(event->motion.y <= world->player->sprite->y){ //On sait que le curseur est en haut du personnage
                        world->player->sprite->wich_img[0] = 7;
                        world->player->sprite->wich_img[1] = 0;
                        world->player->animation_timer = 1;
                    }
                    else{   //On sait que le curseur est en bas du personnage
                        world->player->sprite->wich_img[0] = 1;
                        world->player->sprite->wich_img[1] = 0;
                        world->player->animation_timer = 1;
                    }
               }
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