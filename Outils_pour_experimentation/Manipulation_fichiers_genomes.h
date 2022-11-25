#ifndef MANIPULATION_FICHIERS_GENOME_H
#define MANIPULATION_FICHIERS_GENOME_H

#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#include"../Fonctions_generales/structures.h"

/*Fonction permettant de lire la taille de x dans le fichier nom_fichier*/
int lire_taille_x(const char* nom_fichier);

/*Fonction permettant de lire les noms de fichiers du dossier nom_dossier et de les retourner dans un tableau de couple (nom,taille de x)
qui contiendra au maximum nb_max noms (selon ceux disponibles dans le répertoire). Ce tableau est trié.*/
Tableau_fichiers* lire_noms_fichiers(const char* nom_dossier,int nb_max);


/*Fonction qui permet de comparer deux fichiers entre eux selon la taille de x*/
int Comparateur_fichier(const void* Fichier_1,const void* Fichier_2);

/*Fonction permettant de lire les noms de fichiers du dossier entré en paramètre s'ils ont une taille de x supérieure ou égale à taille_x_min*/
Tableau_fichiers * lire_noms_fichiers_taille_x(const char* nom_dossier, int nb_max, int taille_x_min);



#endif 