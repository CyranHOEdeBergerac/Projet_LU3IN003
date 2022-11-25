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

/*Fonction permettant de concaténer deux alignements*/
Alignement * concatener_alignements(Alignement* algn_1, Alignement* algn_2);


/*Structure notant les informations utiles pour un fichier*/

typedef struct _Nom_taille_x{
    char* nom;
    int taille_x;
}Nom_taille_x;

/*Fonction permettant de supprimer le couple contenu dans ntx*/
void supprimer_S_nom_taille_x (Nom_taille_x* ntx);


/*Structure nous permettant de manipuler un tableau de fichiers. La structure a son intérêt car le tableau n'est pas toujours de taille maximum, selon
le nombre de fichiers dans le dossier.*/
typedef struct _Tableau_fichiers{
    Nom_taille_x** tableau;
    int nombre_fichiers_lus;
}Tableau_fichiers;

/*Fonction permettantde supprimer un tableau de fichiers tab */
void supprimer_S_tableau_fichiers(Tableau_fichiers* tab);





#endif