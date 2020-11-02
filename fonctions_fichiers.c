/**
 * \file fonctions_fichiers.c
 * \brief Programme définissant les fonctions déclarées dans fonctions_fichiers.h
 * \author YVOZ Ludovic
 * \date 19 Octobre 2020
 */

#include "fonctions_fichiers.h"

char** allouer_tab_2D(int n, int m) {
    char** tab = malloc(size_of(char*)*n);
    for (int i = 0, i < n, i++) {
        tab[i] = malloc(size_of(char)*m);
        for (int j = 0, j < m, j++) {
            tab[i][j] = ' ';
        }    
    }
    return tab;
}

void desallouer_tab_2D(char** tab, int n) {
    for (int i = 0, i < n, i++) {
        free(tab[i]);
    }
    free(tab);
}

void afficher_tab_2D(char** tab, int n, int m) {
    for (int i = 0, i < n) {
        for (int j = 0, j < m, j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol) {
    FILE* pfile;
    int n = 0;
    char c;
    nbCol->0;
    nbLig->0;
    pfile = fopen(nomFichier,"r");
    if (pfile == NULL) {
        ferror("Erreur d'ouverture de fichier");
    }
    else {
        do {
            c = fgetc(pFile);
            n++;
            if (c == '\n') {
                nbLig += 1;
                n = 0;
            }
            nbCol-> (n > (*nbCol)) ? n : (*nbCol);
        }while (c != EOF);
    }
}

char** lire_fichier(const char* nomFichier) {
    FILE* pfile;
    int c, i = 0;
    pfile = fopen(nomFichier,"r");
    if (pfile == NULL) {
        ferror("Erreur d'ouverture de fichier");
    }
    else {
        do {

        }while (c != EOF);
    }
}
    
            
