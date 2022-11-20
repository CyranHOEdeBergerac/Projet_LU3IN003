#ifndef TACHE_C_H
#define TACHE_C_H

#include"../Fonctions_generales/outils.h"

/*Fonction qui calcule la distance d'édition entre x et y de taille n et m en utilisant un tableau de taille n x m également passé en paramètres
Cette fonction utilise un tableau de taille 2*m pour améliorer la complexité spatiale de la solution par programmation dynamique.*/
int Dist_2(char*x,char*y,int n, int m, int** Distances);


#endif