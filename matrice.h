#ifndef MATRICE
#define MATRICE

typedef struct{
    int ligne;
    int colonne;
    double **tab;
}Matrice;

Matrice* createMatrice(int ligne, int colonne);
void showMatrice(Matrice* matrix);
Matrice* sommeMatrice(Matrice* firstTrix, Matrice* secondTrix);
Matrice* produitMatrice(Matrice* firstTrix, Matrice* secondTrix);
Matrice* powerMatrice(Matrice* matrice, int power);
Matrice* getIdentite(int ordre);
Matrice* getNulle(int ligne, int colonne);
Matrice* scalaireMatrice(Matrice* matrice, double scalaire);
double traceMatrice(Matrice* matrice);
Matrice* transposeMatrice(Matrice* matrice);
Matrice* retrieveLineAndColonnes(Matrice* matrice, int line, int colonne);
double determinant(Matrice* matrice);
Matrice* getComatrice(Matrice * matrice);
Matrice* getInverse(Matrice* matrice);
void destroyMatrice(Matrice* matrice);

#endif // MATRICE