#include"../Approche_naive/Tache_A.h"

#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"

#include"../Outils_pour_experimentation/Manipulation_fichiers_genomes.h"

int main(){

    /*Variables nécessaires*/
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;
    Couple_chaine* chaine_cour;
    int dist_cour;
    int dist;
    char nom_a_lire[256];

    int i = 0;

    Tableau_fichiers * tab_tests = lire_noms_fichiers("../Instances_genome",3);

    while ( (i < tab_tests->nombre_fichiers_lus) && (temps_calcul_distance < 60)) {

        sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
        chaine_cour = lire_genome(nom_a_lire);

        temps_init = clock();
        dist_cour = dist_naif(chaine_cour->x,chaine_cour->y);
        temps_fin = clock();
        temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
        printf("Temps calculé : %.2f",temps_calcul_distance);
        supprimer_couple_chaine(chaine_cour);
        i++;
    }

}