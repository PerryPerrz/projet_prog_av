/**
 * \file update.c
 * \brief Programme définissant les fonctions déclarées dans update.h
 * \author YVOZ Ludovic
 * \author IOPETI Hugo
 * \date 24 Novembre 2020
 */

#include "update.h"

void update_data(world_t *world){
    //mise à jour des déplacements des missiles etc.. à faire
    if (world->room_state == 0) {   //On génère de nouveaux monstres si on est dans une nouvelle salle
        create_enemies(world);
        world->room_state = 1;
    }
    update_enemies(world);

    compute_game(world);

}

int sprites_collide(sprite_t *sp2, sprite_t *sp1)
{
    if (sqrt(pow((sp1->x - sp2->x), 2) + pow((sp1->y - sp2->y), 2)) <= (sp1->h + sp2->h)/2)
    {
        return 1;
    }
    return 0;
}


void handle_sprites_collision(sprite_t *sp2, sprite_t *sp1)
{
    if (sprites_collide(sp1, sp2) == 1 && sp1->is_visible == 0 && sp2->is_visible == 0)
    {
        set_invisible(sp1);
        set_invisible(sp2);
        sp1->v = 0;
        sp2->v = 0;
    }
}


void handle_item_collision(sprite_t *item, sprite_t *sp)
{
    if (sprites_collide(sp, item) == 1 && sp->is_visible == 0 && item->is_visible == 0)
    {
        set_invisible(item);
    }
}

void print_sprite(sprite_t * sprite)
{
    printf("x = %d\ny = %d\nh = %d\nw = %d\nv = %d\n",
        sprite->x,sprite->y,sprite->h,sprite->w,sprite->v);
}

void compute_game(world_t *world)
{
    //Pour l'instant pas de score d'implémenté etc...
}