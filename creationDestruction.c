#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

Matrice* createMatrice(int ligne, int colonne){

    int i, j;
    Matrice *newMatrix = (Matrice*) malloc( sizeof(Matrice) );

    if(newMatrix==NULL){
        printf("Une erreur c'est produite \n");
        return NULL;
    }

    newMatrix->tab = malloc(sizeof(double)*ligne);
    newMatrix->ligne= ligne;
    newMatrix->colonne= colonne;

    for(i=0; i<ligne; i++)
        newMatrix->tab[i] = malloc(sizeof(double)*colonne);

    for(i=0; i<ligne; i++)
        for(j=0; j<colonne; j++){
            printf("Ligne i : %d Colonne : %d = ", i+1, j+1);
            scanf("%lf", ( newMatrix->tab[i] ) + j);
        }

    return newMatrix;
}

void destroyMatrice(Matrice* matrice){
    free(matrice);
}