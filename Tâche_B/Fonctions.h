#include<stdio.h>
#include <stdlib.h>
#include"../Tache_A/methode_naive.h"

typedef struct _Alignement{
    char* x;
    char* y;
   
    int curseur_x;
    int curseur_y;

    int distance_edition;
}Alignement ;


/*Fonction calculant le minimum entre trois valeurs entières a, b, et c*/
int min3(int a, int b, int c);

/*Fonction qui calcule la distance d'édition entre x et y de taille n et m en utilisant un tableau de taille n x m également passé en paramètres*/
int dist_1(char * x, char* y, int n, int m, int * Distances[][]);


/*Fonction retournant l'alignement de coût minimum de x et y deux mots de taille m et d'un tableau de distances d'édition préalablement rempli*/
Alignement* sol_1(char* x, char* y, int n, int m, int* Distances[][]);
