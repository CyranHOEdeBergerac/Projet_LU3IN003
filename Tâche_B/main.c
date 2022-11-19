#include"Fonctions.h"
#include"../Tache_A/fonctions_lecture.h"
/*FAIRE LE MAKEFILE*/

int main(){
    /*Test de notre solution sur un alignement*/
    printf("Coucou si là ça bug tires toi une balle\n");
    Couple_chaine* couple = lire_genome("../Instances_genome/Inst_0000010_7.adn");

    afficher_couple_chaine(couple);
    printf("Là on vient de lire le génome\n");
    Alignement* res = prog_dyn(couple);

    printf("Là on vient d'utiliser prog dyn\n");
    afficher_alignement(res);

    //supprimer_alignement(res);

}