#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"

#include"Tache_A.h"

int main(){ 

    /*Variables nécessaires*/
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;
    Couple_chaine* chaine_cour;
    int dist_cour;
    int dist;




        /*Test de notre methode naïve sur quelques valeurs*/
        printf("\nTest des la méthode naïve de calcul de distance d'édition\n");

        Couple_chaine* inst_10_8 = lire_genome("../Instances_genome/Inst_0000010_8.adn");
        dist = dist_naif(inst_10_8->x,inst_10_8->y);
        printf("Distance d'édition pour 10_8: %d\nRésultat valide :%d\n",dist,(dist==2));
        supprimer_couple_chaine(inst_10_8);

        Couple_chaine* inst_10_7 = lire_genome("../Instances_genome/Inst_0000010_7.adn");
        dist = dist_naif(inst_10_7->x,inst_10_7->y);
        printf("Distance d'édition pour 10_7: %d\nRésultat valide :%d\n",dist,(dist==8));
        supprimer_couple_chaine(inst_10_7);

        Couple_chaine* Inst_10_44 = lire_genome("../Instances_genome/Inst_0000010_44.adn");
        dist = dist_naif(Inst_10_44->x,Inst_10_44->y);
        printf("Distance d'édition pour 10_44: %d\nRésultat valide :%d\n",dist,(dist==10));
        supprimer_couple_chaine(Inst_10_44);
        

  
    return 0;    
}