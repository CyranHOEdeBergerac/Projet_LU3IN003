#include "Tache_D.h"

int main(){

    int** Dist = (int**) malloc(2*sizeof(int*));
    int** I = (int**) malloc(2 * sizeof(int*));

    Dist[0] = (int*) malloc(4*sizeof(int));
    Dist[1] = (int*) malloc(4*sizeof(int));
    I[0] = (int*) malloc(4*sizeof(int));
    I[1] = (int*) malloc(4*sizeof(int));

    //Alignement* resultat = SOL_2("ATTCA","TGCCA",5,5,Dist,I);

    //printf("On a l'alignement\n%s\n%s\n",resultat->x,resultat->y);

    int coup;
    coup = coupure("ATTGTA","ATCTTA",6,6,Dist,I); 
    


   
}