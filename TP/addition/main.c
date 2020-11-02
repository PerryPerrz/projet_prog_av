/**
 * \file main.c
 * \brief Programme faisant las somme de deux entiers donnés par l'utilisateur
 * \author YVOZ Ludovic
 * \date 21 Septembre 2020
 */


#include "addition.h"

/**
 *  \brief programme principal
 */
int main();


int main() {
    int n, m;

    printf("Donnez la valeur de n : ");
    scanf("%d",&n);
    printf("Donnez la valeur de m : ");
    scanf("%d",&m);

    printf("La somme de n et m est : %d !\n",somme(n, m));
}
