#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"


Matrice* sommeMatrice(Matrice* firstTrix,Matrice* secondTrix){
    
    int i, j;
    Matrice *newMatrix = (Matrice*) malloc( sizeof(Matrice) );

    if(firstTrix->ligne!=secondTrix->ligne || firstTrix->colonne!=secondTrix->colonne){
        printf("Calcul non possible \n");
        return NULL;
    }

    if(firstTrix==NULL || secondTrix==NULL){
        printf("Une erreur c'est produite\n");
        return NULL;
    }

    if(newMatrix==NULL){
        printf("Une erreur c'est produite \n");
        return NULL;
    }

    newMatrix->tab = malloc(sizeof(double)*firstTrix->ligne);

    newMatrix->ligne= firstTrix->ligne;
    newMatrix->colonne= secondTrix->colonne;

    for(i=0; i<firstTrix->ligne; i++){
        newMatrix->tab[i] = malloc(sizeof(double)*secondTrix->colonne);
    }

    for(i=0; i<firstTrix->ligne; i++)
        for(j=0; j<firstTrix->colonne; j++){
            newMatrix->tab[i][j] = firstTrix->tab[i][j] + secondTrix->tab[i][j];
        }

    return newMatrix;
}

Matrice* produitMatrice(Matrice* firstTrix, Matrice* secondTrix){
    int i, j, k, same; 
    double calcProduct = 0;
    Matrice *newMatrix = (Matrice*) malloc( sizeof(Matrice) );

    if(firstTrix->colonne!=secondTrix->ligne){
        printf("Calcul non possible \n");
        return NULL;
    }

    same = firstTrix->colonne;

    if(newMatrix==NULL){
        printf("Une erreur c'est produite \n");
        return NULL;
    }

    newMatrix->tab = malloc(sizeof(double)*firstTrix->ligne);

    newMatrix->ligne= firstTrix->ligne;
    newMatrix->colonne= secondTrix->colonne;

    for(i=0; i<firstTrix->ligne; i++){
        newMatrix->tab[i] = malloc(sizeof(double)*secondTrix->colonne);
    }

    for(i=0; i<firstTrix->ligne; i++){
        for(j=0; j<secondTrix->colonne; j++){
            calcProduct=0;
            for(k = 0; k<same; k++){
                calcProduct+=firstTrix->tab[i][k]*secondTrix->tab[k][j];
            }
            newMatrix->tab[i][j] = calcProduct;
        }
    }

    return newMatrix;
}
