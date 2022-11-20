#ifndef MANIPULATION_FICHIERS_GENOME_H
#define MANIPULATION_FICHIERS_GENOME_H

#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/*Structure notant les informations utiles pour un fichier*/

typedef struct _Nom_taille_x{
    char* nom;
    int taille_x;
}Nom_taille_x;

/*Structure nous permettant de manipuler un tableau de fichiers. La structure a son intérêt car le tableau n'est pas toujours de taille maximum, selon
le nombre de fichiers dans le dossier.*/
typedef struct _Tableau_fichiers{
    Nom_taille_x** tableau;
    int nombre_fichiers_lus;
}Tableau_fichiers;

/*Fonction permettant de lire la taille de x dans le fichier nom_fichier*/
int lire_taille_x(const char* nom_fichier);

/*Fonction permettant de lire les noms de fichiers du dossier nom_dossier et de les retourner dans un tableau de couple (nom,taille de x)
qui contiendra au maximum nb_max noms (selon ceux disponibles dans le répertoire). Ce tableau est trié.*/
Tableau_fichiers* lire_noms_fichiers(const char* nom_dossier,int nb_max);


/*Fonction qui permet de comparer deux fichiers entre eux selon la taille de x*/
int Comparateur_fichier(const void* Fichier_1,const void* Fichier_2);



#endif 