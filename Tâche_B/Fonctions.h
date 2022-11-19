#include<stdio.h>
#include <stdlib.h>
#include"../Tache_A/fonctions_lecture.h"

#if 0
#include"../Tache_A/methode_naive.h"
#include"../Tache_A/fonctions_lecture.h"
#endif

#define C_DEL 2                     //Coût de suppression
#define C_INS 2                     //Coût d'insertion
#define C_SUB_CONCORDANT 3          //Coût de substitution si lettres concordantes
#define C_SUB_NON_CONCORDANT 4      //Coût de substitution si lettres non concordantes



typedef struct _Alignement{
    char* x;
    char* y;
   
    int curseur;
    int taille;
    int distance_edition;
}Alignement ;

int cout_substitution(char a, char b);

/*Fonction permettant de créer la structure qui contiendra un alignement*/
Alignement* creer_alignement(int n, int m);

/*Fonction qui permet de supprimer la mémoire allouée à un alignement*/
void supprimer_alignement(Alignement* algn);

#if 0
/*Fonction qui permet d'afficher un alignement*/
void afficher_alignement(Alignement* algn)
#endif
/*Fonction calculant le minimum entre trois valeurs entières a, b, et c*/
int min3(int a, int b, int c);

/*Fonction qui calcule la distance d'édition entre x et y de taille n et m en utilisant un tableau de taille n x m également passé en paramètres*/
int dist_1(char * x, char* y, int n, int m, int *** Distances);


/*Fonction retournant l'alignement de coût minimum de x et y deux mots de taille m et d'un tableau de distances d'édition préalablement rempli*/
Alignement* sol_1(char* x, char* y, int n, int m, int*** Distances);

/*Fonction prog dyn retournant à la fois l'alignement optimal pour le couple et la distance d'édition dans la structure Alignement retournée.*/
Alignement* prog_dyn(Couple_chaine* couple);
