#include"methode_naive.h"


int lettres_concordantes(char a, char b){
    /*Renvoie vraie si a et b sont des lettres concordantes (dans l'alphabet {ACTG})*/
    switch (a)
    {
    case 'A':
        if (b=='T'){
            return 1;
        }
        else{
            return 0;
        }
        break;

    case 'C':
        if (b=='G'){
            return 1;
        }
        else{
            return 0;
        }
        break;
    case 'T':
        if (b=='A'){
            return 1;
        }
        else{
            return 0;
        }
        
        break;
    case 'G':
        if (b=='C'){
            return 1;
        }
        else{
            return 0;
        }
        break;
    }
}

int cout_substitution(char a, char b){
    /*Fonction retournant le coût de substitution de (a,b)*/
    if (a==b){
        return 0;
    }

    if(lettres_concordantes(a,b)){
        return C_SUB_CONCORDANT;
    }
    return C_SUB_NON_CONCORDANT;
}


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
            dist = dist_naif_rec (x, y, i+1, j+1, c + cout_substitution( x[i], y[j]),dist);     //Le sujet indiquait de le faire avec i+1 et j+1 mais cela ne fonctionnait pas

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