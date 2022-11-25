#ifndef TACHE_D_H
#define TACHE_D_H
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/outils.h"
#include"Tache_C.h"

/*Fonction retournant une chaîne de caractères contenant k gaps*/
char* mot_gaps(int k);

/*Fonction retournement l'alignement d'une lettre x avec la chaîne y contenant m lettres */
Alignement* align_lettre_mot(char x, char* y, int m);

/*Fonction implémentant la solution à notre problème en utilisant la méthode diviser pour mieux régner, Dist et I 
sont passés en paramètre afin qu'un seul tableau soit réutilisé à chaque appel, il est alloué plus tôt et ne sert que dans l'appel à coupure.*/
Alignement * SOL_2(char * x, char* y, int n, int m, int** Dist, int** I);

/*Fonction trouvant l'indice optimal où couper y en utilisant de la programmation dynamique avec Dist et I passés en paramètres.*/
int coupure(char * x, char* y, int n, int m, int** Dist, int ** I);


#endif