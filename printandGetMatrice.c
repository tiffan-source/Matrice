#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

void showMatrice(Matrice* matrix){
    int i, j;
    if(matrix==NULL){
        printf("Matrice inexistante\n");
        return;   
    }
    printf("This is your matrix\n");

    for(i=0; i< matrix->ligne; i++){
        for(j=0; j< matrix->colonne; j++)
            printf("| %.2f |", matrix->tab[i][j]);
        
        printf("\n");
    }
}

Matrice* getIdentite(int ordre){
    int i, j;
    Matrice *idMatrice = (Matrice*) malloc( sizeof(Matrice) );

    if(idMatrice==NULL){
        printf("Une erreur s'est produite \n");
        return NULL;
    }

    idMatrice->tab = malloc(sizeof(double)*ordre);

    idMatrice->ligne= ordre;
    idMatrice->colonne= ordre;

    for(i=0; i<ordre; i++){
        idMatrice->tab[i] = malloc(sizeof(double)*ordre);
    }

    for(i=0; i<ordre; i++)
        for(j=0; j<ordre; j++){
                idMatrice->tab[i][j]= i==j ? 1 : 0;
        }

    return idMatrice;
}

Matrice* getNulle(int ligne, int colonne){
    int i, j;
    Matrice *nullMatrice = (Matrice*) malloc( sizeof(Matrice) );

    if(nullMatrice==NULL){
        printf("Une erreur s'est produite \n");
        return NULL;
    }

    nullMatrice->tab = malloc(sizeof(double)*ligne);

    nullMatrice->ligne= ligne;
    nullMatrice->colonne= colonne;

    for(i=0; i<ligne; i++){
        nullMatrice->tab[i] = malloc(sizeof(double)*colonne);
    }

    for(i=0; i<ligne; i++)
        for(j=0; j<colonne; j++){
                nullMatrice->tab[i][j]=0;
        }

    return nullMatrice;
}

Matrice* getComatrice(Matrice * matrice){
    int i, j;
    Matrice* comatrice =  (Matrice*) malloc( sizeof(Matrice) );

    if(matrice->ligne!=matrice->colonne){
        printf("La matrice n'est pas carré\n");
        return NULL;
    }

    if(matrice==NULL){
        printf("Une erreur c'est produite\n");
        return NULL;
    }

    comatrice->tab = malloc(sizeof(double)*matrice->ligne);

    comatrice->ligne=matrice->ligne;
    comatrice->colonne=matrice->colonne;



    for(i=0; i<matrice->ligne; i++)
        comatrice->tab[i] = malloc(sizeof(double)*matrice->colonne);
    

    for(i=0; i<matrice->ligne; i++)
        for(j=0; j<matrice->colonne; j++)
            comatrice->tab[i][j] = determinant( retrieveLineAndColonnes(matrice, i+1, j+1) ) * ((i+j)%2==0?1:-1);

    return comatrice;

}

Matrice* getInverse(Matrice* matrice){
    int i;
    Matrice* inverse =  (Matrice*) malloc( sizeof(Matrice) );

    if(matrice->ligne!=matrice->colonne){
        printf("La matrice n'est pas carré\n");
        return NULL;
    }

    if(determinant(matrice)==0){
        printf("La matrice n'est pas inversible\n");
        return NULL;
    }

    if(matrice==NULL){
        printf("Une erreur c'est produite\n");
        return NULL;
    }

    inverse->tab = malloc(sizeof(double)*matrice->ligne);

    inverse->ligne=matrice->ligne;
    inverse->colonne=matrice->colonne;



    for(i=0; i<matrice->ligne; i++)
        inverse->tab[i] = malloc(sizeof(double)*matrice->colonne);
    
    return scalaireMatrice(
        transposeMatrice( getComatrice(matrice) ),
        1/determinant(matrice)
    );
}