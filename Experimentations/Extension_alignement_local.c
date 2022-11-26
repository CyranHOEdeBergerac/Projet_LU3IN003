#include"../Programmation_dynamique/Tache_C.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/outils.h"

int main(){
    Couple_chaine* couple_test = lire_genome("../Instances_genome/Instance_x_plus_grand_que_y.adn");

    int** tab_Dist_2 = (int**) malloc(2*sizeof(int*));
    tab_Dist_2[0] = (int*) malloc( (couple_test->m+1) *  sizeof(int));
    tab_Dist_2[1] = (int*) malloc( (couple_test->m +1) * sizeof(int));

    int distance = Dist_2(couple_test->x,couple_test->y,couple_test->n,couple_test->m,tab_Dist_2);

    printf("Distance d'édition pour une instance où n = %d, m = %d, %d\n",couple_test->n,couple_test->m,distance);

}