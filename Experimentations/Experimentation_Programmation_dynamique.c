#include"../Programmation_dynamique/Tache_B.h"
#include"../Programmation_dynamique/Tache_C.h"

#include"../Fonctions_generales/outils.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"

#include"../Outils_pour_experimentation/Manipulation_fichiers_genomes.h"


#define NOMBRE_INSTANCES_A_TESTER 10
#define TAILLE_X_MINIMALE_RETENUE 10

int main(){
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;

    double temps_calcul_distance_1 = 0;
    double temps_calcul_distance_2 = 0;

    Couple_chaine* chaine_cour;
    Alignement* res;
    int dist_cour;
    char nom_a_lire[256];
    int choix;
    int dist;

    int** tab_Dist_2;
    int** tab_Dist_1;


    int i;
    int k;

    Tableau_fichiers * tab_tests = lire_noms_fichiers_taille_x("../Instances_genome",NOMBRE_INSTANCES_A_TESTER,TAILLE_X_MINIMALE_RETENUE);
    
    FILE* fichier_ecriture_2 = fopen("Temps_programmation_dynamique_2.txt","w");
    do
    {
        printf("\n=====Que faire ?=====\n0: Sortie\n1: Complexité de prog dyn\n2: Complexité de Dist_2 comparée à celle de Dist_1\n3: Mémoire utilisée par prog_dyn_\n4: Mémoire utilisée par Dist_2\n");

        scanf("%d",&choix);
        FILE* fichier_ecriture_2;
        FILE* fichier_ecriture_1;


        switch (choix)
        {
        case 1:
        /*Complexité temporelle de prog dyn*/
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

                supprimer_alignement(res);
                supprimer_couple_chaine(chaine_cour);
            }
            fclose(fichier_ecriture_1);
            break;

        case 2:
            /*Comparaison entre Dist_1 et Dist_2*/    
            i = 0;
            fichier_ecriture_2 = fopen("Temps_programmation_dynamique_2.txt","w");

            while (i < NOMBRE_INSTANCES_A_TESTER)  {
                    sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
                    chaine_cour = lire_genome(nom_a_lire);

                    /*Temps de Dist_2*/
                    tab_Dist_2 = (int**) malloc(2*sizeof(int*));
                    tab_Dist_2[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
                    tab_Dist_2[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));

                    temps_init = clock();
                    dist = Dist_2(chaine_cour->x,chaine_cour->y,chaine_cour->n,chaine_cour->m,tab_Dist_2);
                    temps_fin = clock();

                    temps_calcul_distance_2 = (temps_fin - temps_init) / CLOCKS_PER_SEC;
                    
                    /*Temps de Dist_1*/
                    int** tab_Dist_1 = (int **) malloc((chaine_cour->n +1)* sizeof(int*));
                    for(k = 0; k <= chaine_cour->n ; k ++){
                        tab_Dist_1[k] = (int*) malloc((chaine_cour->m +1)* sizeof(int));
                    }
                    
                    
                    temps_init = clock();
                    dist_1(chaine_cour->x,chaine_cour->y,chaine_cour->n,chaine_cour->m,tab_Dist_1);
                    temps_fin = clock();
                    temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;



                    fprintf(fichier_ecriture_2,"%d\t%.15f\t%.15f\n",tab_tests->tableau[i]->taille_x, temps_calcul_distance_1,temps_calcul_distance_2);
                    i++;

                    free(tab_Dist_2[0]);
                    free(tab_Dist_2[1]);
                    free(tab_Dist_2);

                
                    for(k = 0 ; k <= chaine_cour->n  ; k ++){
                        free(tab_Dist_1[k]);
                    }
                    free(tab_Dist_1);
                    
                    supprimer_couple_chaine(chaine_cour);
            }
            fclose(fichier_ecriture_2);
            break;

        case 3 : 
            chaine_cour = lire_genome("../Instances_genome/Inst_0015000_20.adn");

                
            res = prog_dyn(chaine_cour);
            i++;

            supprimer_alignement(res);
            supprimer_couple_chaine(chaine_cour);
            
            break;
        case 4 :
            chaine_cour = lire_genome("../Instances_genome/Inst_0015000_20.adn");
            tab_Dist_2 = (int**) malloc(2*sizeof(int*));
            tab_Dist_2[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
            tab_Dist_2[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));

            dist = Dist_2(chaine_cour->x,chaine_cour->y,chaine_cour->n,chaine_cour->m,tab_Dist_2);

            supprimer_couple_chaine(chaine_cour);
            free(tab_Dist_2[0]);
            free(tab_Dist_2[1]);
            free(tab_Dist_2);

            break;
        case 0:
            break;
        default:
            break;
        }
        
    } while (choix);

    /*Prologue et désallocation*/
    supprimer_S_tableau_fichiers(tab_tests);

}