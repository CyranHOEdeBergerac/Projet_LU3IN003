#include"Tache_A.h"

int dist_naif(char*x,char*y){
    /*Retourne la distance d'édition de (x,y)*/
    return dist_naif_rec(x,y,0,0,0,-1);
}

int dist_naif_rec(char*x,char*y,int i, int j, int c, int dist){
    int len_x = strlen(x);                          //Opérations de coût négligable vis à vis de notre complexité
    int len_y = strlen(y);
    if (( i == len_x ) && ( j == len_y)){
        if ((c <dist) || (dist == -1)){
            dist = c;
        }
    }
    else{
        if (( i < len_x) && (j < len_y)){
            dist = dist_naif_rec (x, y, i+1, j+1, c + cout_substitution( x[i], y[j]),dist);

        }
        if (i < len_x){
            dist = dist_naif_rec(x,y,i+1,j,c+ C_DEL, dist);
        }
        if(j < len_y){
            dist = dist_naif_rec(x, y, i, j+1, c + C_INS, dist);
        }
    }
    return dist;
}