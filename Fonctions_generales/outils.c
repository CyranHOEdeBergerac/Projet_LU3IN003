#include"outils.h"


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

int min3(int a, int b, int c){
    if (a < b){
        if (a < c) {
            return a;
        }
        else{
            return c;
        }
    }
    else{ 
        if(b < c){
            return b;
        }
        else{
            return c;
        }
    }
}