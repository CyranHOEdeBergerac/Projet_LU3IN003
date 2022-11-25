#include"../Programmation_dynamique/Tache_B.h"
#include"../Programmation_dynamique/Tache_C.h"

#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"

#include"../Outils_pour_experimentation/Manipulation_fichiers_genomes.h"


#define NOMBRE_INSTANCES_A_TESTER 10
#define TAILLE_X_MINIMALE_RETENUE 10

/*Voir pour faire une fonction qui ne prend que des grandes instances ?*/
int main(){
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;
    Couple_chaine* chaine_cour;
    Alignement* res;
    int dist_cour;
    char nom_a_lire[256];
    int choix;
    int dist;

    int** tab_Dist_2;

    int i;
    Tableau_fichiers * tab_tests = lire_noms_fichiers_taille_x("../Instances_genome",NOMBRE_INSTANCES_A_TESTER,TAILLE_X_MINIMALE_RETENUE);
    
    FILE* fichier_ecriture_2 = fopen("Temps_programmation_dynamique_2.txt","w");
    do
    {


        printf("\n=====Que faire ?=====\n0: Sortie\n1: Complexité de prog dyn\n2: Complexité de Dist_2\n");

        scanf("%d",&choix);
        FILE* fichier_ecriture_2;
        FILE* fichier_ecriture_1;


        switch (choix)
        {
        case 1:
            fichier_ecriture_1 = fopen("Temps_programmation_dynamique_1.txt","w");
            i = 0;
            while (i < NOMBRE_INSTANCES_A_TESTER)  {

                sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
                chaine_cour = lire_genome(nom_a_lire);

                temps_init = clock();
                res = prog_dyn(chaine_cour);
                temps_fin = clock();

                temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
                fprintf(fichier_ecriture_1,"%d\t%.15f\n",tab_tests->tableau[i]->taille_x, temps_calcul_distance);

                i++;
            }
            fclose(fichier_ecriture_1);
            break;
        case 2:
            i = 0;
            fichier_ecriture_2 = fopen("Temps_programmation_dynamique_2.txt","w");

            while (i < NOMBRE_INSTANCES_A_TESTER)  {
                    sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
                    chaine_cour = lire_genome(nom_a_lire);

                    tab_Dist_2 = (int**) malloc(2*sizeof(int*));
                    tab_Dist_2[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
                    tab_Dist_2[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));

                    temps_init = clock();
                    dist = Dist_2(chaine_cour->x,chaine_cour->y,chaine_cour->n,chaine_cour->m,tab_Dist_2);
                    printf("Le résultat est %d\n",dist);
                    temps_fin = clock();

                    temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
                    fprintf(fichier_ecriture_2,"%d\t%.15f\n",tab_tests->tableau[i]->taille_x, temps_calcul_distance);
                    i++;

                    free(tab_Dist_2[0]);
                    free(tab_Dist_2[1]);
                    free(tab_Dist_2);
            }
            fclose(fichier_ecriture_2);
            break;
        case 0:
            break;
        default:
            supprimer_S_tableau_fichiers(tab_tests);
            break;
        }
        
    } while (choix);



}