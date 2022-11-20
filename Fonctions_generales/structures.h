#ifndef STRUCTURES_H
#define STRUCTURES_H

#include"outils.h"

/*Stucture nous permettant de manipuler simultanément deux chaînes de caractères*/
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

/*Structure nous permettant de manipuler des alignements de génôme*/
typedef struct _Alignement{
    char* x;
    char* y;
   
    int curseur;
    int taille;
    int distance_edition;
}Alignement ;


/*Fonction permettant de créer la structure qui contiendra un alignement*/
Alignement* creer_alignement(int n, int m);

/*Fonction qui permet de supprimer la mémoire allouée à un alignement*/
void supprimer_alignement(Alignement* algn);


/*Fonction qui permet d'afficher un alignement*/
void afficher_alignement(Alignement* algn);



#endif