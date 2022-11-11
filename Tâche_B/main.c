#include"Fonctions.h"
#include"../Tache_A/fonctions_lecture.h"
/*FAIRE LE MAKEFILE*/

int main(){
    /*Test de notre solution sur un alignement*/

    Couple_chaine* couple = lire_genome("../Instances_genome/Inst_0000010_7.adn");

    Alignement* res = prog_dyn(couple);
    afficher_alignement(res);

}