#include<stdio.h>
#include<string.h>
#include"fonctions_lecture.h"
#include"methode_naive.h"



int main(){
   /*Main permettant de tester notre méthode naïve*/
    
    int dist;
   
    dist = dist_naif("TATATGAGTC","TATTT");
    printf("Distance d'édition pour TATATGAGTC et TATT: %d\n",dist);

    dist = dist_naif("TGGGTGCTAT","GGGGTTCTAT");
    printf("Distance d'édition pour TGGGTGCTAT et GGGGTTCTAT: %d\n",dist);
    
    dist = dist_naif("AACTGTCTTT","AACTGTTTT");
    printf("Distance d'édition pour AACTGTCTTT et AACTGTTTT: %d\n",dist);

    
    return 0;    
}