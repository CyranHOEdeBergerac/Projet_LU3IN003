#ifndef MANIPULATION_FICHIERS_GENOME_H
#define MANIPULATION_FICHIERS_GENOME_H

#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/*Constante nous permettant de savoir combien on va lire de fichiers au maximum*/
#define NOMBRE_FICHIERS_LUS_MAX 10


/*Structure nous permettant d'accéder rapidement à la taille de x d'un fichier pour nos algorithmes de tri*/

typedef struct _Nom_taille_x
{
    char* nom;
    int taille_x;
}Nom_taille_x;

/*Fonction permettant de lire la taille de x dans le fichier nom_fichier*/
int lire_taille_x(const char* nom_fichier);

/*Fonction permettant de lire les noms de fichiers du dossier nom_dossier et de les retourner dans un tableau de couple (nom,taille de x) de taille NOMBRE_FICHIERS_LU_MAX*/
Nom_taille_x ** lire_noms_fichiers(const char* nom_dossier);

/*Fonction permettant de trier les noms de fichiers par taille de x*/
Nom_taille_x** tri_fichiers_taille_x(Nom_taille_x** liste_noms_fichiers);


#endif 