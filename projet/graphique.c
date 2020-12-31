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

        SrcR.x = 0;
        for (int i = 0; i < sprite->wich_img[0]; i++) { //On donne la coordonnée x du sprite sur la sprite sheet alors que la largeur entre chaque colonne est différente
            SrcR.x += sprite->w[i] + SPACE_BETWEEN_COLUMNS ;
        }

        SrcR.y = sprite->wich_img[1] * (SPACE_BETWEEN_ROWS + sprite->h);

        apply_image(texture, renderer, SrcR, sprite->x - sprite->w[sprite->wich_img[0]]/2, sprite->y -sprite->h/2); //On donne les coordonnées du coin en haut à gauche du sprite à partir du centre du sprite
    }
}

void  init_resources(SDL_Renderer *renderer, resources_t *resources){
    resources->player = load_transparent_image("ressources/player/sprite_sheet.bmp", renderer,230,80,235);
    resources->player_attack_hori = load_transparent_image("ressources/player/atk_hori_sprite_sheet.bmp", renderer,230,80,235);
    resources->player_attack_verti = load_transparent_image("ressources/player/atk_verti_sprite_sheet.bmp", renderer,230,80,235);
    resources->slime = load_transparent_image("ressources/monsters/slime.bmp", renderer,230,80,235);

    //On s'occupe des textures de la salle
    resources->room = malloc(sizeof(room_resources_t));
    resources->room->background = load_image("ressources/map/background1.bmp",renderer);
    resources->room->door_down_close = load_image("ressources/map/door_down_close.bmp", renderer);
    resources->room->door_up_close = load_image("ressources/map/door_up_close.bmp", renderer);
    resources->room->door_right_close = load_image("ressources/map/door_right_close.bmp", renderer);
    resources->room->door_left_close = load_image("ressources/map/door_left_close.bmp", renderer);
    resources->room->door_down_open = load_image("ressources/map/door_down_open.bmp", renderer);
    resources->room->door_up_open = load_image("ressources/map/door_up_open.bmp", renderer);
    resources->room->door_right_open = load_image("ressources/map/door_right_open.bmp", renderer);
    resources->room->door_left_open = load_image("ressources/map/door_left_open.bmp", renderer);
    resources->room->wall_down = load_image("ressources/map/wall_down.bmp", renderer);
    resources->room->wall_up = load_image("ressources/map/wall_up.bmp", renderer);
    resources->room->wall_right = load_image("ressources/map/wall_right.bmp", renderer);
    resources->room->wall_left = load_image("ressources/map/wall_left.bmp", renderer);

    //On s'occupe de la police d'écriture
    init_ttf();
    resources->font = load_font("ressources/font/arial.ttf", 12);
    resources->color.a = 0;
    resources->color.r = 250;
    resources->color.b = 250;
    resources->color.g = 250;
}

void clean_resources(resources_t *resources){
    clean_image(resources->player);
    clean_image(resources->player_attack_hori);
    clean_image(resources->player_attack_verti);
    clean_image(resources->slime);
    //On s'occupe des textures de la salle
    clean_image(resources->room->background);
    clean_image(resources->room->door_down_close);
    clean_image(resources->room->door_up_close); 
    clean_image(resources->room->door_right_close);
    clean_image(resources->room->door_left_close);
    clean_image(resources->room->door_down_open);
    clean_image(resources->room->door_up_open);
    clean_image(resources->room->door_right_open);
    clean_image(resources->room->door_left_open);
    clean_image(resources->room->wall_down);
    clean_image(resources->room->wall_up);
    clean_image(resources->room->wall_right);
    clean_image(resources->room->wall_left);
    free(resources->room);

    //On s'occupe de la police d'écriture
    clean_font(resources->font);
}


void apply_background(SDL_Renderer *renderer, resources_t *resources){
    if(resources->room->background != NULL){
        SDL_Rect SrcR = {0, 0, 0, 0};
        SDL_QueryTexture(resources->room->background, NULL, NULL, &SrcR.w, &SrcR.h);  //On demande directement les dimensions du background
        apply_image(resources->room->background, renderer, SrcR, 0, 0);
    }
}

void apply_part_of_background(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y){
    SDL_Rect SrcR = {0, 0, 0, 0};
    SDL_QueryTexture(texture, NULL, NULL, &SrcR.w, &SrcR.h);  //On demande directement les dimensions de l'image à afficher
    apply_image(texture, renderer, SrcR, x, y);
}


void refresh_graphics(SDL_Renderer *renderer, world_t *world, resources_t *resources){
    //on vide le renderer
    SDL_RenderClear(renderer);
    
    //application des ressources dans le renderer
    //On gère l'affichage de la salle
    apply_background(renderer, resources);
    refresh_room(renderer, world, resources);
    //On gère l'affichage des sprites
    apply_sprite(renderer, resources->player, world->player->sprite);
    apply_monsters(renderer, world, resources);
    apply_sprite(renderer, resources->player_attack_hori, world->player->atk_sprite_hori);
    apply_sprite(renderer, resources->player_attack_verti, world->player->atk_sprite_verti);

    //On gère l'affichage des textes 
    char player_hp_string[8];
    sprintf(player_hp_string, "HP = %d", world->player->hp);
    apply_text(renderer, resources->font, resources->color, player_hp_string, 50, 50);

    //On gère l'affichage d'un message pour passer d'une salle à l'autre
    if (sprite_is_out_of_additional_bounds(world->player->sprite, world->floor->direction, world->room_state) == 1) {
        if (world->floor->type == 0) {
            apply_text(renderer, resources->font, resources->color, "Appuyez sur la barre espace pour avancer vers la prochaine salle !", SCREEN_WIDTH/2 - 180, SCREEN_HEIGHT/2 - 12);
        }
        else {
            //Message de fin
        }
    }
    
    // on met à jour l'écran    
    SDL_RenderPresent(renderer);
}

void refresh_room(SDL_Renderer *renderer, world_t *world, resources_t *resources){
    switch(world->floor->direction) {

        case 0 :
            if (world->room_state != 1) {  //Si le combat est terminé, la porte est ouverte
                apply_part_of_background(renderer, resources->room->door_down_open, PLAY_ZONE_ADD_TOP_X + 1, PLAY_ZONE_BOTTOM_WALL - 1);
            }
            else {  //Sinon, elle est fermée
                apply_part_of_background(renderer, resources->room->door_down_close, PLAY_ZONE_ADD_TOP_X + 1, PLAY_ZONE_BOTTOM_WALL - 1);
            }
            apply_part_of_background(renderer, resources->room->wall_up, PLAY_ZONE_ADD_TOP_X, 0);
            apply_part_of_background(renderer, resources->room->wall_right, PLAY_ZONE_RIGHT_WALL, PLAY_ZONE_ADD_LEFT_Y + 1);
            apply_part_of_background(renderer, resources->room->wall_left, 0, PLAY_ZONE_ADD_LEFT_Y);           
            break;

        case 1 :
            if (world->room_state != 1) {
                apply_part_of_background(renderer, resources->room->door_right_open, PLAY_ZONE_RIGHT_WALL, PLAY_ZONE_ADD_LEFT_Y + 1);
            }
            else {
                apply_part_of_background(renderer, resources->room->door_right_close, PLAY_ZONE_RIGHT_WALL, PLAY_ZONE_ADD_LEFT_Y + 1);
            }
            apply_part_of_background(renderer, resources->room->wall_up, PLAY_ZONE_ADD_TOP_X, 0);
            apply_part_of_background(renderer, resources->room->wall_down, PLAY_ZONE_ADD_TOP_X + 1, PLAY_ZONE_BOTTOM_WALL - 1);
            apply_part_of_background(renderer, resources->room->wall_left, 0, PLAY_ZONE_ADD_LEFT_Y);
            break;

        case 2 :
            if (world->room_state != 1) {
                apply_part_of_background(renderer, resources->room->door_left_open, 0, PLAY_ZONE_ADD_LEFT_Y);
            }
            else {
                apply_part_of_background(renderer, resources->room->door_left_close, 0, PLAY_ZONE_ADD_LEFT_Y);
            }
            apply_part_of_background(renderer, resources->room->wall_up, PLAY_ZONE_ADD_TOP_X, 0);
            apply_part_of_background(renderer, resources->room->wall_right, PLAY_ZONE_RIGHT_WALL, PLAY_ZONE_ADD_LEFT_Y + 1);
            apply_part_of_background(renderer, resources->room->wall_down, PLAY_ZONE_ADD_TOP_X + 1, PLAY_ZONE_BOTTOM_WALL - 1);
            break;

        case 3 :
            if (world->room_state != 1) {
                apply_part_of_background(renderer, resources->room->door_up_open, PLAY_ZONE_ADD_TOP_X, 0);
            }
            else {
                apply_part_of_background(renderer, resources->room->door_up_close, PLAY_ZONE_ADD_TOP_X, 0);
            }
            apply_part_of_background(renderer, resources->room->wall_down, PLAY_ZONE_ADD_TOP_X + 1, PLAY_ZONE_BOTTOM_WALL - 1);
            apply_part_of_background(renderer, resources->room->wall_right, PLAY_ZONE_RIGHT_WALL, PLAY_ZONE_ADD_LEFT_Y + 1);
            apply_part_of_background(renderer, resources->room->wall_left, 0, PLAY_ZONE_ADD_LEFT_Y);
            break;
    }
}

void apply_monsters(SDL_Renderer* renderer, world_t* world, resources_t* resources) {
    //applications des monstres dans le renderer
    for (int i = 0; i < world->nb_enemies; i++) {
        switch (world->enemies[i]->type) 
        {
            case 1:
                apply_sprite(renderer, resources->slime, world->enemies[i]->sprite);
                break;
        }
    }
}

void apply_text(SDL_Renderer * renderer, TTF_Font* font, SDL_Color color, char * string, int x, int y) {
    SDL_Texture* texture = load_text(string, renderer, font, color);
    SDL_Rect rect = {0,0,0,0};
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    apply_image(texture, renderer, rect, x, y);
}
