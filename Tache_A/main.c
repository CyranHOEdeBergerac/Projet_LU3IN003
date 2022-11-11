#include<stdio.h>
#include<string.h>
#include<time.h>
#include<dirent.h>

#include"fonctions_lecture.h"
#include"methode_naive.h"




int main(){ 

    /*Variables nécessaires*/
    clock_t temps_init;
    clock_t temps_fin;
    double temps_calcul_distance = 0;
    Couple_chaine* chaine_cour;
    int dist_cour;
    int dist;



    int choix;
    printf("Que faire avec le main ? \n0 : rien\n1 : tester les fonctions de lecture\n2 : tester dist_naif_rec\n3: étudier le temps utilisé en mémoire\n");

    scanf("%d",&choix);

    switch (choix)
    {
    case 0:
        return 0;
        break;

    case 1:
        /*Test des fonctions de lecture*/
        printf("Test de la fonction de lecture avec l'instance 0000010_8\n");
        Couple_chaine* test = lire_genome("../Instances_genome/Inst_0000010_8.adn");
        afficher_couple_chaine(test);
        supprimer_couple_chaine(test);
        break;

    case 2:
        /*Test de notre methode naïve sur quelques valeurspermettant de tester notre méthode naïve*/
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
        break;

    case 3:
        /*Calcul de la taille maximale de l'instance pour laquelle le résultat se fait en moins d'une minute avec les instances fournies*/

    #if 0 
        TROUVER UN MOYEN DE FAIRE LA LECTURE AUTOMATIQUE
        while ( (temps_calcul_distance < 60)  ) {

            printf("Donner un nom d'instance à regarder : \n");

            scanf("%s",nom_fichier);
            
            chaine_cour = lire_genome(nom_fichier);

            temps_init = clock();
            dist_cour = dist_naif(chaine_cour->x,chaine_cour->y);
            temps_fin = clock();

            temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
            printf("Temps calculé : %.2f",temps_calcul_distance);
            supprimer_couple_chaine(chaine_cour);
           
        }
    #endif 
            chaine_cour = lire_genome("../Instances_genome/Inst_0000012_32.adn");

            temps_init = clock();
            dist_cour = dist_naif(chaine_cour->x,chaine_cour->y);
            temps_fin = clock();

            temps_calcul_distance = (temps_fin - temps_init) / CLOCKS_PER_SEC;
            printf("Temps calculé pour  12_32: %.2f", temps_calcul_distance);
            supprimer_couple_chaine(chaine_cour);

        
        break;
    default:
        break;
    }
    return 0;    
}