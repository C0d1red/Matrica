#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int m, n, i, k, i2, k2, min, minM, minN, m4, n4;
    printf("m and n:\n");
    scanf("%d%d", &m, &n);
    m4 = m-1;
    n4 = n-1;
    int matr[m][n], strS[n], strE[n], matr4[m4][n4];

    min = 9999999;
    minN = 9999999;
    minM = 9999999;

    srand( time(0) );

    printf("Matrica 1:\n");

    for (i = 0; i<m; i++){
        printf("\n");
        for(k = 0; k<n; k++){
            matr[i][k]=rand();
            if(matr[i][k]<min){
                min = matr[i][k];
                minM = i;
                minN = k;
            }
            printf("%d ", matr[i][k]);
        }
    }

    for(i = 0; i < n; i++){
        strS[i] = matr[0][n-i-1];
        strE[i] = matr[m-1][n-i-1];
    }

    for(i = 0; i<n; i++){
        matr[0][i] = strE[i];
        matr[n-1][i] = strS[i];
    }


    printf("\n\nMatrica 2:");

     for (i = 0; i<m; i++){
        printf("\n");
        for(k = 0; k<n; k++){
            printf("%d ", matr[i][k]);
        }
     }


    for(i=0; i<m; i++){
        matr[i][minN]= 0;
        matr[minM][i] = 0;
    }

     printf("\n\nMatrica 3:");

     for (i = 0; i<m; i++){
        printf("\n");
        for(k = 0; k<n; k++){
            printf("%d ", matr[i][k]);
        }
     }

     /* printf("\n\nMatrica 4:");





      for (i = 0; i<m; i++){
        for(k = 0; k<n; k++){
            if(matr[i][k]!=0){
                    for(i2 = 0; i2<m4; i2++){
                        for(k2 = 0; k2<n4; k2++){
                            matr4[i2][k2] = matr[i][k];
                        }
                    }
            }
        }
    }



          for (i = 0; i<m4; i++){
        printf("\n");
        for(k = 0; k<n4; k++){
            printf("%d ", matr4[i][k]);
        }
    }

    */


    return 0;
}
