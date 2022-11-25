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
    Alignement* res = (Alignement*) malloc (sizeof(Alignement));
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

Alignement* concatener_alignements(Alignement*algn_1, Alignement* algn_2){
    algn_1->taille = algn_1->taille + algn_2->taille;

    algn_1->x = (char *) realloc(algn_1->x,algn_1->taille);
    algn_1->y = (char *) realloc(algn_1->y, algn_1->taille);            //On réalloue les chaînes de algn_1 pour qu'elles puissent contenir algn_2

    
    strcat(algn_1->x,algn_2->x);
    strcat(algn_1->y,algn_2->y);

    supprimer_alignement(algn_2);

    return algn_1;
}

void supprimer_S_nom_taille_x (Nom_taille_x* ntx){
    free(ntx->nom);
    free(ntx);

}

void supprimer_S_tableau_fichiers(Tableau_fichiers* tab){
    int i;

    for(i = 0 ; i < tab->nombre_fichiers_lus ; i++){
        supprimer_S_nom_taille_x(tab->tableau[i]);
    }

    free(tab->tableau);
    free(tab);

}