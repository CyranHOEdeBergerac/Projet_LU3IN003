#include "Manipulation_fichiers_genomes.h"



int lire_taille_x(const char* nom_fichier){
    char nom_avec_repertoire[256];
    sprintf(nom_avec_repertoire,"../Instances_genome/%s",nom_fichier);
    FILE* fichier = fopen(nom_avec_repertoire,"r");

    if(fichier==NULL){
        printf("Erreur de lecture du fichier\n");
        return 0;
    }

    int n;
    char buffer[256];

    fgets(buffer,256,fichier);
    
    if(sscanf(buffer,"%d",&n)!=1){
        printf("Erreur de lecture de n\n");
        return 0;
    }
    fclose(fichier);
    return n;
}


Tableau_fichiers * lire_noms_fichiers(const char* nom_dossier, int nb_max){
    int i = 0;

    Nom_taille_x** tableau_noms_fichiers = (Nom_taille_x**) malloc(nb_max*sizeof(Nom_taille_x*));
    DIR* rep = opendir(nom_dossier);

    struct dirent * fichier = NULL;    

    if(rep == NULL){
        printf("Erreur dans la lecture du dossier, on ne lira aucun fichiers\n");
        return NULL;
    }
    while ((i < nb_max) && ((fichier = readdir(rep)) !=NULL)){
        if ( ( strcmp(fichier->d_name,".") != 0 ) && (strcmp(fichier->d_name,"..") != 0) ){      //répertoire actuel et répertoire dans lequel il est inclus
            
            tableau_noms_fichiers[i] = (Nom_taille_x*) malloc(sizeof(Nom_taille_x));
            tableau_noms_fichiers[i]->nom = strdup(fichier->d_name);
            tableau_noms_fichiers[i]->taille_x = lire_taille_x(fichier->d_name);

            i++;
        }
    }
    closedir(rep);

    qsort(tableau_noms_fichiers,i,sizeof(Nom_taille_x*),Comparateur_fichier);

    Tableau_fichiers* res = (Tableau_fichiers*) malloc(sizeof(Tableau_fichiers));
    res->tableau = tableau_noms_fichiers;
    res->nombre_fichiers_lus = i;
    
    return res;  
}

Tableau_fichiers * lire_noms_fichiers_taille_x(const char* nom_dossier, int nb_max, int taille_x_min){
    int i = 0;
    int taille_x;

    Nom_taille_x** tableau_noms_fichiers = (Nom_taille_x**) malloc(nb_max*sizeof(Nom_taille_x*));
    DIR* rep = opendir(nom_dossier);

    struct dirent * fichier = NULL;    

    if(rep == NULL){
        printf("Erreur dans la lecture du dossier, on ne lira aucun fichiers\n");
        return NULL;
    }
    while ((i < nb_max) && ((fichier = readdir(rep)) !=NULL)){
        if ( ( strcmp(fichier->d_name,".") != 0 ) && (strcmp(fichier->d_name,"..") != 0) ){      //répertoire actuel et répertoire dans lequel il est inclus
            
            taille_x = lire_taille_x(fichier->d_name);

            if(taille_x >= taille_x_min){
            
                tableau_noms_fichiers[i] = (Nom_taille_x*) malloc(sizeof(Nom_taille_x));
                tableau_noms_fichiers[i]->nom = strdup(fichier->d_name);
                tableau_noms_fichiers[i]->taille_x = taille_x;
                
                i++;
            }
        }
    }
    closedir(rep);

    qsort(tableau_noms_fichiers,i,sizeof(Nom_taille_x*),Comparateur_fichier);

    Tableau_fichiers* res = (Tableau_fichiers*) malloc(sizeof(Tableau_fichiers));
    res->tableau = tableau_noms_fichiers;
    res->nombre_fichiers_lus = i;
    
    return res; 
}

int Comparateur_fichier(const void* Fichier_1,const void* Fichier_2){

    int x1 = (* (Nom_taille_x**) Fichier_1)->taille_x;
    int x2 = (* (Nom_taille_x**) Fichier_2)->taille_x;

    return x1-x2;
}