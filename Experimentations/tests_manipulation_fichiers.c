#include "Manipulation_fichiers_genomes.h"


int main(){
    Nom_taille_x** tableau_noms_fichiers = lire_noms_fichiers("../Instances_genome");
    for(int i = 0 ; i < NOMBRE_FICHIERS_LUS_MAX ; i ++){
        printf("%s avec taille de x = %d\n",tableau_noms_fichiers[i]->nom,tableau_noms_fichiers[i]->taille_x);
    }
}