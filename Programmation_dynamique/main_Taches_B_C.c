#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"

#include"Tache_B.h"
#include"Tache_C.h"

int main(){
    /*Test de notre solution sur un alignement*/
    Couple_chaine* couple = lire_genome("../Instances_genome/Inst_0000012_56.adn");

    afficher_couple_chaine(couple);

    int** D = (int**) malloc(2*sizeof(int*));
    D[0] = (int*) malloc((couple->m +1)* sizeof(int));
    D[1] = (int*) malloc((couple->m +1)*sizeof(int));
    printf("\n\n");
    int dist_2 = Dist_2(couple->x,couple->y,couple->n,couple->m, D);
    printf("Calcul de distance d'édition optimisé : %d\n\n=====\n",dist_2);

    Alignement* res = prog_dyn(couple);

    afficher_alignement(res);


}