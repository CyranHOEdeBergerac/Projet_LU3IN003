#ifndef TACHE_A
#define TACHE_A

#include"../Fonctions_generales/outils.h"

/*Fonction retournant la distance d'édition de (x,y)*/
int dist_naif(char*x,char*y);

/*Fonction permettant de calculer récursivement le coût du meilleur alignement de (x,y) connu après
 cet appel à partir de x et y deux mots, i un indice dans [0:|x|], j un indice dans[0;|y|], 
 c le coût de l'alignement de (x[0;i],y[0;j])*/
int dist_naif_rec(char*x,char*y,int i, int j, int c, int dist);



#endif