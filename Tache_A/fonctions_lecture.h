#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct _Couple_chaine
{
    char* x;
    char* y;
    int n;
    int m;
} Couple_chaine;

/*Fonction permettant de créer une structure couple de chaînes de caractères avec leurs tailles respectives*/
Couple_chaine* creer_couple_chaine(char*x, char* y, int n, int m);

/*Fonction permettant de supprimer en désallouant toutes les allocations dynamiques un couple de chaînes de caractères*/
void supprimer_couple_chaine(Couple_chaine* couple);

/*Fonction permettant d'afficher un couple de chaines*/
void afficher_couple_chaine(Couple_chaine* couple);

/*Fonction permettant de lire l'échantillon de génome contenu dans le fichier file_name*/
Couple_chaine* lire_genome(char* file_name);