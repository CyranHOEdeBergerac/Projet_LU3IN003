#include"../Programmation_dynamique/Tache_D.h"
#include"../Programmation_dynamique/Tache_C.h"
#include"../Programmation_dynamique/Tache_B.h"
#include"../Fonctions_generales/structures.h"
#include"../Fonctions_generales/fonctions_lecture_ecriture.h"
#include"../Outils_pour_experimentation/Manipulation_fichiers_genomes.h"


#define NOMBRE_INSTANCES_A_TESTER 7
#define TAILLE_X_MINIMALE_RETENUE 10

int main(){
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;

    double temps_calcul_distance_2 = 0;
    Couple_chaine* chaine_cour;
    Alignement* res;
    int dist_cour;
    char nom_a_lire[256];
    int choix;
    int dist;

    int** tab_Dist_2;
    int** I;

    int i;


    Tableau_fichiers * tab_tests = lire_noms_fichiers_taille_x("../Instances_genome",NOMBRE_INSTANCES_A_TESTER,TAILLE_X_MINIMALE_RETENUE);


    do{
        printf("\n=====Que faire ?=====\n0: sortie\n1: Complexité temporelle SOL_2\n2: Comparaison de la complexité temporelle de SOL_1 et SOL_2\n3: Consommation mémoire\n");
        scanf("%d",&choix);

        FILE* fichier_ecriture_2;
        FILE* fichier_ecriture_1;


        switch (choix)
        {
        case 1:
            /* Complexité temporelle de SOL_2 */
            i = 0;
            fichier_ecriture_1 = fopen("Temps_diviser_mieux_regner.txt","w");

            while (i < NOMBRE_INSTANCES_A_TESTER)  {
                    sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
                    chaine_cour = lire_genome(nom_a_lire);


                    tab_Dist_2 = (int**) malloc(2*sizeof(int*));
                    tab_Dist_2[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
                    tab_Dist_2[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));

                    I =(int**) malloc(2*sizeof(int*));
                    I[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
                    I[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));


                    temps_init = clock();
                    res = SOL_2(chaine_cour->x,chaine_cour->y,chaine_cour->n,chaine_cour->m,tab_Dist_2,I);
                    temps_fin = clock();
                    
                    temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
                    
                    fprintf(fichier_ecriture_1,"%d\t%.15f\n",tab_tests->tableau[i]->taille_x, temps_calcul_distance);
                    i++;
                    
                    free(tab_Dist_2[0]);
                    free(tab_Dist_2[1]);
                    free(tab_Dist_2);
                    
                    free(I[0]);
                    free(I[1]);
                    free(I);
                    
                    supprimer_alignement(res);
                    supprimer_couple_chaine(chaine_cour);
            }
            fclose(fichier_ecriture_1);            
            break;
        
        case 2:
            /*Comparaison avec SOL_1*/
            i = 0;
            fichier_ecriture_2 = fopen("Temps_comp_SOL_1_SOL_2.txt","w");

            while (i < NOMBRE_INSTANCES_A_TESTER)  {
                    sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
                    chaine_cour = lire_genome(nom_a_lire);

                    /*SOL_2*/
                    tab_Dist_2 = (int**) malloc(2*sizeof(int*));
                    tab_Dist_2[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
                    tab_Dist_2[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));

                    I =(int**) malloc(2*sizeof(int*));
                    I[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
                    I[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));


                    temps_init = clock();
                    res = SOL_2(chaine_cour->x,chaine_cour->y,chaine_cour->n,chaine_cour->m,tab_Dist_2,I);
                    temps_fin = clock();

                    free(tab_Dist_2[0]);
                    free(tab_Dist_2[1]);
                    free(tab_Dist_2);
                    
                    free(I[0]);
                    free(I[1]);
                    free(I);
                    
                    supprimer_alignement(res);
                    
                    temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;


                    /*SOL_1*/
                    sprintf(nom_a_lire,"../Instances_genome/%s",tab_tests->tableau[i]->nom);
                    chaine_cour = lire_genome(nom_a_lire);

                    temps_init = clock();
                    res = prog_dyn(chaine_cour);
                    temps_fin = clock();

                    temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;

                    
                    fprintf(fichier_ecriture_2,"%d\t%.15f\t%.15f\n",tab_tests->tableau[i]->taille_x, temps_calcul_distance_2,temps_calcul_distance);
                    i++;
                    
                    supprimer_alignement(res);
                    supprimer_couple_chaine(chaine_cour);
            }
            fclose(fichier_ecriture_2);     
            break;
        
        case 3:
            chaine_cour = lire_genome("../Instances_genome/Inst_0015000_20.adn");
            tab_Dist_2 = (int**) malloc(2*sizeof(int*));
            tab_Dist_2[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
            tab_Dist_2[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));

            I =(int**) malloc(2*sizeof(int*));
            I[0] = (int*) malloc( (chaine_cour->m+1) *  sizeof(int));
            I[1] = (int*) malloc( (chaine_cour->m +1) * sizeof(int));


            res = SOL_2(chaine_cour->x,chaine_cour->y,chaine_cour->n,chaine_cour->m,tab_Dist_2,I);

            supprimer_couple_chaine(chaine_cour);
            free(tab_Dist_2[0]);
            free(tab_Dist_2[1]);
            free(tab_Dist_2);
            free(I[0]);
            free(I[1]);
            free(I);

            supprimer_alignement(res);


            break;
        default:
            break;
        }
    } while (choix !=0);
    supprimer_S_tableau_fichiers(tab_tests);


}