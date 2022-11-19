#ifndef METHODE_NAIVE_H
#define METHODE_NAIVE_H

#include<stdio.h>
#include<string.h>

/*Valeurs constantes*/
#define C_DEL 2                     //Coût de suppression
#define C_INS 2                     //Coût d'insertion
#define C_SUB_CONCORDANT 3          //Coût de substitution si lettres concordantes
#define C_SUB_NON_CONCORDANT 4      //Coût de substitution si lettres non concordantes

/*Fonction permettant de calculer le coût de substitution selon si a et b sont concordants*/
int lettres_concordantes(char a, char b);

/*Fonction permettant de calculer le cût de substitution de a en b*/
int cout_substitution(char a, char b);

/*Fonction permettant de calculer la distance d'édition de x et de y de manière naïve (appel à la fonction récursive)*/
int dist_naif(char* x, char* y);

/*Fonction permettant de calculer récursivement le coût du meilleur alignement de (x,y) connu après
 cet appel à partir de x et y deux mots, i un indice dans [0:|x|], j un indice dans[0;|y|], 
 c le coût de l'alignement de (x[0;i],y[0;j])*/
int dist_naif_rec(char*x,char*y,int i, int j, int c, int dist);

#endif