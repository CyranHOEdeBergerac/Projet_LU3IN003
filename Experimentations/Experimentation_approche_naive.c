#include"../Approche_naive/Tache_A.h"

#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"

#include"../Outils_pour_experimentation/Manipulation_fichiers_genomes.h"

#define NOMBRE_INSTANCES_A_TESTER 5

int main(){

    /*Variables nécessaires*/
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;
    Couple_chaine* chaine_cour;
    int dist_cour;
    int dist;
    char nom_a_lire[256];
    int choix;
    int i = 0;
    Couple_chaine* inst_10_8;

    FILE* fichier_ecriture;

    Tableau_fichiers * tab_tests = lire_noms_fichiers("../Instances_genome",NOMBRE_INSTANCES_A_TESTER);


    do{
        printf("\n=====Que faire ?=====\n0: sortie\n1:chercher la taille pour que le temps de calcul dépasse la minute\n2: Test de la méthode sur Inst_0000012_32\n");
        scanf("%d",&choix);


        switch (choix)
        {
        case 1:
            fichier_ecriture = fopen("Temps_approche_naive.txt","w");

            while ( (i < NOMBRE_INSTANCES_A_TESTER) && (temps_calcul_distance < 60)) {

                sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
                chaine_cour = lire_genome(nom_a_lire);

                temps_init = clock();
                dist_cour = dist_naif(chaine_cour->x,chaine_cour->y);
                temps_fin = clock();
                temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
                fprintf(fichier_ecriture,"Temps calculé pour %s : %.2f\n",nom_a_lire,temps_calcul_distance);
                supprimer_couple_chaine(chaine_cour);
                i++;
            }

            fclose(fichier_ecriture);
            break;
        case 2 : 
            inst_10_8 = lire_genome("../Instances_genome/Inst_0000012_32.adn");
            dist = dist_naif(inst_10_8->x,inst_10_8->y);
            supprimer_couple_chaine(inst_10_8);
            break;

        case 0 : 
            break;
        default:
            break;
        }
        
    }while (choix);

}