#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

Matrice* transposeMatrice(Matrice* matrice){
    
    int i, j;
    Matrice *newMatrix = (Matrice*) malloc( sizeof(Matrice) );

    if(newMatrix==NULL ||matrice==NULL){
        printf("Une erreur c'est produite \n");
        return NULL;
    }

    newMatrix->tab = malloc(sizeof(double)*matrice->colonne);

    newMatrix->ligne= matrice->colonne;
    newMatrix->colonne= matrice->ligne;

    for(i=0; i<matrice->colonne; i++){
        newMatrix->tab[i] = malloc(sizeof(double)*matrice->ligne);
    }

    for(i=0; i<newMatrix->ligne; i++)
        for(j=0; j<newMatrix->colonne; j++)
            newMatrix->tab[i][j]=matrice->tab[j][i];

    return newMatrix;

}

Matrice* scalaireMatrice(Matrice* matrice, double scalaire){
    int i, j;
    Matrice *result = (Matrice*) malloc( sizeof(Matrice) );

    if(result==NULL || matrice ==NULL){
        printf("Une erreur s'est produite \n");
        return NULL;
    }

    result->tab = malloc(sizeof(double)*matrice->ligne);

    result->ligne= matrice->ligne;
    result->colonne= matrice->colonne;

    for(i=0; i < matrice->ligne; i++){
        result->tab[i] = malloc(sizeof(double)*matrice->colonne);
    }

    for(i=0; i<matrice->ligne; i++)
        for(j=0; j<matrice->colonne; j++){
            result->tab[i][j]=matrice->tab[i][j]*scalaire;
        }

    return result;
}

double traceMatrice(Matrice* matrice){
    double result = 0;
    int i, j;

    if(matrice==NULL){
        printf("Une erreur s'est produite\n");
        return 0; //sybolique pour le moment
    }

    if(matrice->ligne!=matrice->colonne){
        printf("La matrice suivante n'est pas carrée\n");
        return -1; //valeur symbolique
    }

    for(i=0; i<matrice->ligne; i++)
        for(j=0; j<matrice->ligne; j++)
            if(i==j)
                result+=matrice->tab[i][j];

    return result;
}

Matrice* powerMatrice(Matrice* matrice, int power){
    int i;
    Matrice* result = NULL;

    if(matrice==NULL || matrice->ligne!=matrice->colonne)
        printf("Une erreur c'est produite");

    if(power == 0 )
        return getIdentite(matrice->ligne);

    if(power == 1)
        return matrice;

    result = matrice;

    for(i=1; i<power; i++)
        result = produitMatrice(result, matrice);

    return result;
}

double determinant(Matrice* matrice){
    int ordre, i, j;
    double result = 0;
    
    if(matrice==NULL){
        printf("Une erreur c'est produite\n");
        return 0; //symbolique
    }

    if(matrice->ligne!=matrice->colonne){
        printf("La matrice n'est pas carrée\n");
        return 0; //symbolique
    }

    ordre = matrice->ligne;

    if(ordre==2){
        return matrice->tab[0][0]*matrice->tab[1][1]-matrice->tab[0][1]*matrice->tab[1][0];
    }

    for(j=0; j<ordre; j++){
        if((j+1)%2==0)
            result+= (-1)* matrice->tab[0][j] * determinant( retrieveLineAndColonnes(matrice, 1, j+1) );
        else
            result+= matrice->tab[0][j] * determinant( retrieveLineAndColonnes(matrice, 1, j+1) );
    }

    return result;
}