/**
 * \file fonctions_fichiers.c
 * \brief Programme définissant les fonctions déclarées dans fonctions_fichiers.h
 * \author YVOZ Ludovic
 * \date 31 Décembre 2020
 */

#include "fonctions_fichiers.h"


void read_saved_file(world_t* world) {
    FILE* pfile = fopen("sauvegarde/sauvegarde.txt", "r");
    char temp;
    char string_temp[3];
    int index_string = 0, index_data = 0;
    if (pfile == NULL) {    //Si il n'y a pas de fichier, il n'y a pas de sauvegarde, donc le joueur n'a pas de bonus
        world->player->bonus_hp = 0;
        world->player->bonus_atk_power = 0;
        world->player->bonus_atk_speed = 0;
    }
    else {
        do{
            temp = fgetc(pfile);
            if (temp == '\n') { //Si on est à une fin de ligne
                //On stocke la valeur de la sauvegarde
                switch (index_data)
                {
                case 0:
                    world->player->bonus_hp = atoi(string_temp);
                    break;

                case 1:
                    world->player->bonus_atk_power = atoi(string_temp);
                    break;

                case 2:
                    world->player->bonus_atk_speed = atoi(string_temp);
                    break;
                default:
                    break;
                }
                index_string = 0;
                index_data++;
                string_temp[0] = ' ';
                string_temp[1] = ' ';
                string_temp[2] = ' ';
            }
            else {
                string_temp[index_string] = temp;
                index_string++;
            }
        }while(temp != EOF);
        fclose(pfile);
    }
}