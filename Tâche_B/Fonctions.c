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
    Alignement* res = (Alignement*) malloc (sizeof(Alignement*));
    char * x = (char*) malloc( (n+m) * sizeof(char));
    char *  y = (char*) malloc ( (n+m) * sizeof(char));

    res->curseur = n + m - 1;
    res->x = x;
    res->y = y;

    res->taille = n + m;
    return res;
}

void afficher_alignement(Alignement* algn){
    int i;
    for(int i = algn->curseur; i < algn->taille; i ++){
        printf("%c",algn->x[i]);
    }
    printf("\n");
    for(int i = algn->curseur ; i <algn->taille; i++){
        printf("%c",algn->y[i]);
    }
    printf("\nDistance d'édition = %d",algn->distance_edition);
}
void supprimer_alignement(Alignement* algn){
    free(algn->x);
    free(algn->y);
    free(algn);
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


Alignement* sol_1(char* x, char* y, int n, int m, int* D[][]){
    int i = n; 
    int j = m;

    /*CREATION DE L'ALIGNEMENT*/
    Alignement* res = creer_alignement(int n, int m);
    res->distance_edition = D[n][m];

    /*Parcourt dans le tableau, puisqu'on avance soit vers la gauche, soit le haut, soit les deux, on passe bien au maximum n + m fois
    dans la boucle, pas de problème sur le curseur, en cas d'erreur, on quitte la fonction en retournant une erreur.*/
    while i > 0 || j > 0 {
        if ((j > 0) && (D[i][j] == D[i] [j-1] + C_INS)){
            res->x[res->curseur] = '-';
            res->y[res->curseur] = y[j];
            res->curseur --;                //On recule dans la chaîne de caractères car on la remplit par la fin
            j = j -1;
        }
        else if ((i > 0) && (D[i] [j] == D[i -1] [j] + C_DEL)) {
            res->x[res->curseur] = x[i];
            res->y[res->curseur] = '-';
            res->curseur --;                //On avance dans la chaîne de caractères
            i = i -1;
        }
        else if ((i > 0) && (j > 0) (&& D[i] [j] == D[i -1][j -1] + cout_substitution (x[i] , y[j]))){
            res->x[res->curseur] = x[i];
            res->y[res->curseur] = y[j];
            res->curseur --;
            i = i -1;
            j = j -1;
        }
        else{
            printf("Erreur dans D !\n");
            res->x[res->curseur] = 'E';
            res->y[res->curseur] = 'E';
            res->curseur --;
            return res;            
        }
    }
    return res;
}

Alignement* prog_dyn(Couple_chaine* couple){

    int Dist[couple->n][couple->m];         //Tableau pour la programmation dynamique

    dist_1(couple->x,Couple_chaine->y,couple->n,couple->m,&Dist);

    Alignement* res = sol_1(couple->x,couple->y,couple->n, couple->m,&Dist);

    return res;
}