#include"fonctions_lecture.h"


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

Couple_chaine* lire_genome(char* file_name){
    FILE* fichier = fopen(file_name,"r");

    if(fichier == NULL){
        printf("Erreur de lecture\n");
        return NULL;
    }

    int n;
    int m; 

    char buffer[256];

    fgets(buffer,256,fichier);
    if(sscanf(buffer,"%d",&n)!=1){
        printf("Erreur de lecture de n\n");
        return NULL;
    }

    fgets(buffer,256,fichier);
    if(sscanf(buffer,"%d",&m)!=1){
        printf("Erreur de lecture de m\n");
        return NULL;
    }

    char buffer_x[2*n +1];
    fgets(buffer_x,2*n,fichier);

    /*Boucle servant à aller à la ligne suivante*/
    char ligne_suiv = fgetc(fichier);
    while(ligne_suiv!='\n'){
        ligne_suiv = fgetc(fichier);
    }

    
    char buffer_y[2*m + 1];
    fgets(buffer_y,2*m,fichier);
    char* x = (char*) malloc( (n+1) * sizeof(char));
    char* y = (char*) malloc ( (m+1) * sizeof(char));

    int i;
    int j = 0;
    for(i = 0 ; i < 2*n ; i = i + 2){
        x[j] = buffer_x[i];
        j++;
    }

    j = 0;
    for(i = 0 ; i < 2*m ; i = i +2){
        y[j] = buffer_y[i];
        j++;
    }

    x[n] = '\0';
    y[m] = '\0';

    Couple_chaine* res = creer_couple_chaine(x,y,n,m);

    fclose(fichier);
    return res;
}
