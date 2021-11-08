#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

Matrice* retrieveLineAndColonnes(Matrice* matrice, int line, int colonne){

    int i, j;
    Matrice *newMatrix = (Matrice*) malloc( sizeof(Matrice) );

    if(newMatrix==NULL || matrice==NULL){
        printf("Une erreur c'est produite \n");
        return NULL;
    }

    newMatrix->tab = malloc(sizeof(double)*matrice->ligne-1);

    newMatrix->ligne = matrice->ligne-1;
    newMatrix->colonne = matrice->colonne-1;

    for(i=0; i< matrice->ligne-1; i++){
        newMatrix->tab[i] = malloc(sizeof(double)*matrice->colonne);
    }

    for(i=0; i< newMatrix->ligne; i++)
        for(j=0; j< newMatrix->colonne; j++){
            if(i < line - 1 && j <colonne -1)
                newMatrix->tab[i][j]=matrice->tab[i][j];
            else if(i < line - 1 && j >= colonne -1)
                newMatrix->tab[i][j]=matrice->tab[i][j+1];
            else if(i >= line - 1 && j < colonne -1)
                newMatrix->tab[i][j]=matrice->tab[i+1][j];
            else if(i >= line - 1 && j >= colonne -1)
                newMatrix->tab[i][j]=matrice->tab[i+1][j+1];
        }

    return newMatrix;
}