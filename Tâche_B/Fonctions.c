#include "Fonctions.h"


int min3(int a, int b, int c){
    if a < b{
        if a < c {
            return a;
        }
        else{
            return c;
        }
    }
    else{ 
        if b < c{
            return b;
        }
        else{
            return c;
        }
    }
}

Alignement* creer_alignement(int n, int m){

}


int dist_1(char * x, char* y, int n, int m, int * Distances[][]){
/*Fonction qui calcule la distance d'édition entre x et y de taille n et m en utilisant un tableau de taille n x m également passé en paramètres*/
    int i ;
    int j ;
    for( i = 0 ; i < n ; i ++){
        for (j = 0 ; j < m ; j++){
            if i = 0 {
                if j = 0 {
                    Distances[i][j] = 0;
                else
                    Distances[i][j] = j * C_INS;
                }
            }
            else{
                if j = 0 then{
                    Distances[i][j] = i * C_DEL;
                }
                else{
                    Distances[i][j] = Distances[i-1, j-1] + min3(C_INS , C_DEL , cout_substitution(x[i] , y[j] ));
                }
            }
        }
    }
    return Distances[n][m];
}


Alignement* sol_1(char* x, char* y, int n, int m, int* Distances[][]){
    int i = n; 
    int j = m;
    /*CREATION DE L'ALIGNEMENT*/
    Alignement* res = creer_alignement(int n, int m);

    while i > 0 || j > 0 {
        if j > 0 and D(i, j) = D(i, j-1) + C_INS{
            x = −· x 
            y.append(y j )
            j = j -1
        }
        else if i > 0 and D(i, j) = D(i -1, j) + C_DEL {
            x = x i · x
            y.append(-)
            i = i -1
        }
        else if i > 0 et j > 0 et D(i, j) = D(i -1, j -1) + cout_substitution (x[i] , y[j]){
            x = x i · x
            y.append(y j )
            i = i -1
        }
        else{
            printf("Erreur dans D !\n");
            x.append( 'E'  )
            y.append( 'E' )
        }
    }
    return res;
}
