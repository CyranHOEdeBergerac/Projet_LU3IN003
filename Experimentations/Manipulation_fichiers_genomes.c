#include "Manipulation_fichiers_genomes.h"

/*PROBLÈME AVEC L'OUVERTURE DU FICHIER (ET DU NOM C'EST DES ERREURS DE LECTURE)*/
int lire_taille_x(const char* nom_fichier){
    char nom_avec_repertoire[256];
    sprintf(nom_avec_repertoire,"../Instances_genome/%s\n",nom_fichier);
    printf("nom du fichier à ouvrir : %s",nom_avec_repertoire);
    FILE* fichier = fopen(nom_avec_repertoire,"r");
    if(fichier==NULL){
        printf("Erreur de lecture\n");
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


Nom_taille_x ** lire_noms_fichiers(const char* nom_dossier){
    int i = 0;

    Nom_taille_x** tableau_noms_fichiers = (Nom_taille_x**) malloc(NOMBRE_FICHIERS_LUS_MAX*sizeof(Nom_taille_x*));
    printf("Là ?\n");
    DIR* rep = opendir(nom_dossier);

    struct dirent * fichier = NULL;    

    if(rep == NULL){
        printf("Erreur dans la lecture du dossier, on ne lira aucun fichiers\n");
        return NULL;
    }
    while ((i < NOMBRE_FICHIERS_LUS_MAX) && ((fichier = readdir(rep)) !=NULL)){
        if ( ( strcmp(fichier->d_name,".") != 0 ) && (strcmp(fichier->d_name,"..") != 0) ){      //répertoire actuel et répertoire dans lequel il est inclus
            tableau_noms_fichiers[i] = (Nom_taille_x*) malloc(sizeof(Nom_taille_x));
            tableau_noms_fichiers[i]->nom = strdup(fichier->d_name);
            tableau_noms_fichiers[i]->taille_x = lire_taille_x(fichier->d_name);

            i++;
        }
    }
    closedir(rep);
    return tableau_noms_fichiers;  
}

Nom_taille_x** tri_fichiers_taille_x(Nom_taille_x** liste_noms_fichiers){

}