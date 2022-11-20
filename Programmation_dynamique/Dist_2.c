#include"Dist_2.h"



int Dist_2(char*x,char*y,int n, int m, int** Distances){

    int i ;
    int j ;
    int cas_ins;
    int cas_del;
    int cas_sub;
#
    for( i = 0 ; i <= n ; i ++){
        for (j = 0 ; j <= m ; j++){
            if (i == 0) {
                if (j == 0) {
                    Distances[1][j] = 0;
                }
                else{
                    Distances[1][j] = j * C_INS;
                }
            }
            else{
                if (j == 0) {
                    Distances[1][j] = i * C_DEL;
                }
                else{
                    cas_ins = Distances[1][j-1] + C_INS;
                    cas_del = Distances[0][j] + C_DEL;
                    cas_sub = Distances[0][j-1] + cout_substitution(x[i-1] , y[j-1]);     //Attention : les chaînes de caractère commencent à l'indice 0 !

                    Distances[1][j] = min3(cas_ins , cas_del , cas_sub);
                }
            }

           
            printf("%d\t",Distances[1][j]);
        }
        for(j = 0 ; j <= m ; j++){
            Distances[0][j] = Distances[1][j];
        }
        printf("\n");
    }
    return Distances[1][m];

}


