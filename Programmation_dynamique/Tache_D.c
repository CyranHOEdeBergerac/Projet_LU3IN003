#include"Tache_D.h"





char* mot_gaps(int k){
    char * res = (char*) malloc( (k +1) * sizeof(char));
    int i;
    for(i = 0 ; i < k ; i++){
        res[i] = '-';
    }
    res[k] = '\0';
    return res;
}

Alignement* align_lettre_mot(char x, char* y, int m){
    Alignement* res = (Alignement*) malloc(sizeof(Alignement));
    int place_x = -1;                            //indice où placer x dans l'alignement
    int j;                                  //Parcourt dans y
    int cout_sub_courant;
    /*On cherche la place où mettre x dans l'alignement*/
    for(j = 0; j < m ; j++){

        if (lettres_concordantes(x,y[j]) || (x==y[j])){                 
        //Utiliser le cas général en regardant les différents coûts ne marchait pas alors nous allons nous restreindre à 
        //l'hypothèse selon laquelle une substitution concordante est plus avantageuse qu'une insertion et une suppression

            place_x = j;
        }

        
    }

    if(place_x == -1){
        res->taille = m +1;
        res->x = (char*) malloc( (res->taille +1) * sizeof(char));
        res->y =  (char*) malloc( (res->taille +1) *sizeof(char));

        res->x[0] = x;
        res->y[0] = '-';

        for(j = 1 ; j <= res->taille ; j++){
            res->x[j] = '-';                     //Utiliser mot_gaps n'est pas pratique par rapport au langage utilisé
            res->y[j] = y[j-1];
        }
    }

    else{
        res->taille = m;
        res->x = (char*) malloc( (res->taille +1) * sizeof(char));
        res->y =  (char*) malloc( (res->taille +1) *sizeof(char));

        for(j = 0 ; j < res->taille ; j++){

            if(j == place_x){
                res->x[j] = x;
                res->y[j] = y[j];
            }
            else{
                res->x[j] = '-';
                res->y[j] = y[j];
            }
        }
    }
    
    res->x[res->taille] = '\0';
    res->y[res->taille] = '\0';
    
    return res;
}


Alignement * SOL_2(char * x, char* y, int n, int m, int** Dist, int** I){


    Alignement* algn_res = (Alignement*) malloc(sizeof(Alignement));

    if(n == 0){
        algn_res->x = mot_gaps(m);
        algn_res->y = strdup(y);
    
    }
    else if (m == 0){
        algn_res->x = strdup(x);
        algn_res->y = mot_gaps(n);
        
    }
    else if( n == 1 ){
        algn_res = align_lettre_mot(x[0],y,m);               
    }
    
    else if (m == 1){

        /*on inverse les deux chaînes pour pouvoir utiliser align lettre mot*/
        algn_res = align_lettre_mot(y[0],x,n);


        /*On réinverse le résultat*/
        char* tmp = algn_res->x;
        algn_res->x = algn_res->y;
        algn_res->y = tmp;
    }
    else{
        int j = coupure(x,y,n,m,Dist,I)-1;              //Attention : Les indices dans les mots dans coupure sont entre 1 et m
        int i = n/2;
        char* x_gauche = (char*) malloc((i+1)*sizeof(char));
        char* y_gauche = (char*) malloc((j+1)*sizeof(char));

        for(int k = 0; k < i ; k++){
            x_gauche[k] = x[k];
        }
        for(int k = 0; k < j ; k++){
            y_gauche[k] = y[k];
        }
        x_gauche[i] = '\0';
        y_gauche[i] = '\0';

        /*On fait nos deux sous alignements avec la coupure*/
        Alignement* algn_1 = SOL_2(x_gauche,y_gauche,i,j,Dist,I);
        Alignement* algn_2 = SOL_2(x+i,y+j,n-i,m-j,Dist,I);

        free(x_gauche);
        free(y_gauche);

        /*On les combine*/
        algn_res = concatener_alignements(algn_1,algn_2);
    }

    return algn_res;
}

int coupure(char * x, char* y, int n, int m, int** Dist, int ** I){
    int i_etoile = n/2;
    int i;
    int j;
    int chemin_pris;
    for (i = 0 ; i <= n ; i ++){
        for (j = 0 ; j <= m ; j++){
            if(i < i_etoile){
                I[1][j] = 0;
            }
            else if (i == i_etoile){
                I[1][j] = j;
            }

            else{
                Dist_2(x,y,i,m,Dist);

                if( j== 0){
                    I[1][j] = 2 + I[0][j];
                }
                else{
                    chemin_pris = min3(Dist[0][j],Dist[0][j-1],Dist[1][j-1]);
                    if(chemin_pris == Dist[0][j]){
                        I[1][j] = I[0][j];
                    }
                    else if (chemin_pris == Dist[0][j-1]){
                        I[1][j] = I[0][j-1];
                    }
                    else if (chemin_pris == Dist[1][j-1]){

                        I[1][j] = I[1][j-1];
                    }
                    else{
                        printf("Erreur dans la coupure !");
                    }
                }
            }
        }
        for(j = 0 ; j <= m ; j++){
            I[0][j] = I[1][j];
        }
    }
    return I[1][m];
}

