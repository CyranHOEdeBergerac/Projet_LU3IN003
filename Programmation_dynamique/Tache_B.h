#ifndef TACHE_B_H
#define TACHE_B_H

#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"

/*Fonction qui calcule la distance d'édition entre x et y de taille n et m en utilisant un tableau de taille n x m également passé en paramètres*/
int dist_1(char * x, char* y, int n, int m, int ** Distances);


/*Fonction retournant l'alignement de coût minimum de x et y deux mots de taille m et d'un tableau de distances d'édition préalablement rempli*/
Alignement* sol_1(char* x, char* y, int n, int m, int** Distances);

/*Fonction prog dyn retournant à la fois l'alignement optimal pour le couple et la distance d'édition dans la structure Alignement retournée.*/
Alignement* prog_dyn(Couple_chaine* couple);


#endif