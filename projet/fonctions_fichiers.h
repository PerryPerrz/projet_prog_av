/**
 * \file fonctions_fichiers.h
 * \brief Programme déclarant des fonctions effectuant une lecture ou écriture de fichiers
 * \author YVOZ Ludovic
 * \date 31 Décembre 2020
 */

#ifndef init_file
#include <stdlib.h>
#include "database.h"

/**
 * \brief Fonction qui ouvre le fichier de sauvegarde et redonne les bonus écrits dedans si le fichier existe, sinon les bonus sont mis à 0.
 * \param file_name Le nom du fichier à ouvrir ou créer.
 */
void read_saved_file(world_t* world);

#endif
