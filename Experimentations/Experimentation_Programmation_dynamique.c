#include"../Programmation_dynamique/Tache_B.h"
#include"../Programmation_dynamique/Tache_C.h"

#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"

#include"../Outils_pour_experimentation/Manipulation_fichiers_genomes.h"


#define NOMBRE_INSTANCES_A_TESTER 5
/*À REVOIR, PROBLÈME DE MALLOC*/
int main(){
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;
    Couple_chaine* chaine_cour;
    Alignement* res;
    int dist_cour;
    int dist;
    char nom_a_lire[256];

    int i = 0;
    Tableau_fichiers * tab_tests = lire_noms_fichiers("../Instances_genome",NOMBRE_INSTANCES_A_TESTER);
    
    FILE* fichier_ecriture = fopen("Temps_programmation_dynamique_1.txt","w");


    while (i < NOMBRE_INSTANCES_A_TESTER)  {
        printf("On entre dans la boucle avec i = %d\n",i);
        sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
        chaine_cour = lire_genome(nom_a_lire);
        printf("Valeur de n : %d\n",chaine_cour->n);
        printf("Avant le timer\n");
        temps_init = clock();
        res = prog_dyn(chaine_cour);
        temps_fin = clock();
        temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
        //fprintf(fichier_ecriture,"%d\t%.2f\n",tab_tests->tableau[i]->taille_x, temps_calcul_distance);
        i++;
    }

}