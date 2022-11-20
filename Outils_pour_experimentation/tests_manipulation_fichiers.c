#include "Manipulation_fichiers_genomes.h"
#define NOMBRE_FICHIERS_LUS_MAX 5

int main(){
    Tableau_fichiers* tableau_noms_fichiers = lire_noms_fichiers("../Instances_genome",NOMBRE_FICHIERS_LUS_MAX);
    
    for(int i = 0 ; i < NOMBRE_FICHIERS_LUS_MAX ; i ++){
        printf("%s avec taille de x = %d\n",tableau_noms_fichiers->tableau[i]->nom,tableau_noms_fichiers->tableau[i]->taille_x);
    }
}