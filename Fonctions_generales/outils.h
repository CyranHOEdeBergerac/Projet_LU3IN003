#ifndef OUTILS_H
#define OUTILS_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*Valeurs constantes*/
#define C_DEL 2                     //Coût de suppression
#define C_INS 2                     //Coût d'insertion
#define C_SUB_CONCORDANT 3          //Coût de substitution si lettres concordantes
#define C_SUB_NON_CONCORDANT 4      //Coût de substitution si lettres non concordantes

/*Fonction permettant de calculer le coût de substitution selon si a et b sont concordants*/
int lettres_concordantes(char a, char b);

/*Fonction permettant de calculer le cût de substitution de a en b*/
int cout_substitution(char a, char b);


/*Fonction calculant le minimum entre trois valeurs entières a, b, et c*/
int min3(int a, int b, int c);


#endif