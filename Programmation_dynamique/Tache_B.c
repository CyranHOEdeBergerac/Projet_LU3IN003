#include "Tache_B.h"



int dist_1(char * x, char* y, int n, int m, int ** Distances){
/*Fonction qui calcule la distance d'édition entre x et y de taille n et m en utilisant un tableau de taille n+1 x m+1 également passé en paramètres*/
    int i ;
    int j ;
    int cas_ins;
    int cas_del;
    int cas_sub;
    for( i = 0 ; i <= n ; i ++){
        for (j = 0 ; j <= m ; j++){
            if (i == 0) {
                if (j == 0) {
                    Distances[i][j] = 0;
                }
                else{
                    Distances[i][j] = j * C_INS;
                }
            }
            else{
                if (j == 0) {
                    Distances[i][j] = i * C_DEL;
                }
                else{
                    cas_ins = Distances[i][j-1] + C_INS;
                    cas_del = Distances[i-1][j] + C_DEL;
                    cas_sub = Distances[i-1][j-1] + cout_substitution(x[i-1] , y[j-1]);     //Attention : les chaînes de caractère commencent à l'indice 0 !


                    Distances[i][j] = min3(cas_ins , cas_del , cas_sub);
                }
            }
        }
    }
    return Distances[n][m];
}


Alignement* sol_1(char* x, char* y, int n, int m, int** D){
    int i = n; 
    int j = m;

    /*CREATION DE L'ALIGNEMENT*/
    Alignement* res = creer_alignement(n, m);
    res->distance_edition = D[n][m];

    /*Parcourt dans le tableau, puisqu'on avance soit vers la gauche, soit le haut, soit les deux, on passe bien au maximum n + m fois
    dans la boucle, pas de problème sur le curseur, en cas d'erreur, on quitte la fonction en retournant une erreur.*/
    while ((i > 0) || (j > 0)) {
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
        else if ((i > 0) && (j > 0) && (D[i] [j] == D[i -1][j -1] + cout_substitution(x[i-1] , y[j-1]))){           //Attention : on regarde bien dans une chaîne, l'indice i dans le tableau est l'indice i - 1 dans la chaîne en C !
            res->x[res->curseur] = x[i-1];
            res->y[res->curseur] = y[j-1];
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

    int** Dist = (int **) malloc((couple->n +1)* sizeof(int*));
    for(int i = 0; i <= couple->n ; i ++){
        Dist[i] = (int*) malloc((couple->m +1)* sizeof(int));
    }
    
    dist_1(couple->x,couple->y,couple->n,couple->m,Dist);

    Alignement* res = sol_1(couple->x,couple->y,couple->n, couple->m,Dist);


    for(int i = 0; i < couple->n+1 ; i ++){
        free(Dist[i]);
    }
    free(Dist);

    return res;
}


