/**
 * \file fonctions_fichiers.h
 * \brief Programme déclarant des fonctions effectuant une lecture ou écriture de fichiers
 * \author YVOZ Ludovic
 * \date 19 Octobre 2020
 */

#include <stdio.h>

/**
 * \brief Fonction qui alloue un tableau de caractères à deux dimensions.
 * \param n Entier (nombre de lignes)
 * \param m Entier (nombre de colonnes)
 * \return Un tableau de caractères de \a n lignes et \a m colonnes initialisé avec le caractère espace
 */
char** allouer_tab_2D(int n, int m);

/**
 * \brief Fonction qui libère un tableau de caractères à deux dimensions.
 * \param tab Tableau de caractères à deux dimensions
 * \param n Entier (nombre de lignes)
 */
void desallouer_tab_2D(char** tab, int n);

/**
 * \brief Fonction qui affiche un tableau de caractères à deux dimensions.
 * \param tab Tableau de caractères à deux dimensions
 * \param n Entier (nombre de lignes)
 * \param m Entier (nombre de colonnes)
 */
void afficher_tab_2D(char** tab, int n, int m);

/**
 * \brief Fonction qui compte les nombres max de lignes et de colonnes dans un fichier.
 * \param nomFichier Chaîne de caractères (Nom du fichier)
 * \param nbLig Pointeur vers un entier (nombre de lignes max)
 * \param nbCol Pointeur vers un entier (nombre de colonnes max)
 */
void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol);

/**
 * \brief Fonction qui lit un fichier et retourne sous forme de ttableau de caractères à 2 dimensions son contenu.
 * \param nomFichier Chaîne de caractères (Nom du fichier)
 */
char** lire_fichier(const char* nomFichier);

