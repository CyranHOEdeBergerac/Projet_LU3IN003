#include"fonctions_lecture.h"

Couple_chaine* creer_couple_chaine(char*x, char* y, int n, int m){
    printf("Là ?\n");
/*Fonction permettant de créer et intialiser un couple de chaîne de caractères*/
    Couple_chaine* res = (Couple_chaine*) malloc(sizeof(Couple_chaine));    //Allocation
    printf("Après l'allocation dans creer couple\n");
    res->x = x;                                                     //Remplissage des valeurs
    res->y = y;
    res->n = n;
    res->m = m;

    return res;                                                             //On retourne le résultat
}

void afficher_couple_chaine(Couple_chaine* couple){
    printf("%d\n%d\n%s\n%s",couple->n,couple->m, couple->x, couple->y);
}

Couple_chaine* lire_genome(char* file_name){
/*Fonction permettant de faire la lecture d'un fichier contenant un genome*/    
    FILE* genome = fopen(file_name,"r");

    if(genome==NULL){
        printf("Erreur de lecture du fichier\n");
        return NULL;
    }

    char* x;                    //Chaîne qui va contenir la valeur de x
    char* y;                    //Chaîne qui va contenir la valeur de y
    int n;                      //Taille de x
    int m;                      //Taille de y
    char buffer[256];           //Buffer nous permettant de récupérer chaque ligne

    fgets(buffer,256,genome);
    printf("Buffer : %s",buffer);
    if(sscanf(buffer,"%d",&n)!=1){
        printf("Erreur de lecture de la taille de x\n");
        return NULL;
    }

    fgets(buffer,256,genome);
    printf("Buffer : %s",buffer);
    if(sscanf(buffer,"%d",&m)!=1){
        printf("Erreur de lecture de la taille de y\n");
        return NULL;
    }

    x = (char*) malloc(n*sizeof(char));
    y = (char*) malloc(m*sizeof(char));

    fgets(buffer,256,genome);
    printf("Buffer : %s",buffer);
    strcpy(buffer,x);
    

    fgets(buffer,256,genome);
    printf("Buffer : %s",buffer);
    strcpy(buffer,y);
    

    Couple_chaine* res = creer_couple_chaine(x,y,n,m);

    return res;
}
