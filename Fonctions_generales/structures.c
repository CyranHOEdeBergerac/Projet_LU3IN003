#include"structures.h"


Couple_chaine* creer_couple_chaine(char*x, char* y, int n, int m){
    Couple_chaine* res = (Couple_chaine*) malloc ( sizeof(Couple_chaine) );

    if(res ==NULL){
        printf("Erreur d'allocation\n");
        return NULL;
    }

    res->x = x;
    res->y = y;
    res->n = n;
    res->m = m;

    return res;
}

void supprimer_couple_chaine(Couple_chaine* couple){
    free(couple->x);
    free(couple->y);
    free(couple);

}

void afficher_couple_chaine(Couple_chaine* couple){
    printf("n = %d, m = %d\n x = %s.\n y = %s.\n",couple->n,couple->m,couple->x,couple->y);
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
    for(int i = algn->curseur +1; i < algn->taille; i ++){
        printf("%c",algn->x[i]);
    }
    printf("\n");
    for(int i = algn->curseur +1; i <algn->taille; i++){
        printf("%c",algn->y[i]);
    }
    printf("\nDistance d'édition = %d\n",algn->distance_edition);
}

void supprimer_alignement(Alignement* algn){
    free(algn->x);
    free(algn->y);
    free(algn);
}

