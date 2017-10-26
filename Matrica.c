#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    int m, n, m2, n2, i, k, j, i2, k2, min, minM, minN;
    printf("m and n:\n");
    scanf("%d %d", &m, &n );
    m2 = n2 = 20;
    i2 = k2 = 0;
    int matr[m][n], strS[n], strE[n], matr2[20][20], matrItog[m-1][n2];
    char matrS2[1000];

    min = 9999999;
    minN = 9999999;
    minM = 9999999;

    srand( time(0) );

    printf("Matrix 1:\n");


    for (i = 0; i<m; i++){      /* Fill matriz and print matrix M x N, search min line and column */
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

    for(i = 0; i < n; i++){     /* Two cycle for change lines and invert */
        strS[i] = matr[0][n-i-1];
        strE[i] = matr[m-1][n-i-1];
    }

    for(i = 0; i<n; i++){
        matr[0][i] = strE[i];
        matr[n-1][i] = strS[i];
    }


    printf("\n\nMatrix 2:");

     for (i = 0; i<m; i++){
        printf("\n");
        for(k = 0; k<n; k++){
            printf("%d ", matr[i][k]);
        }
     }



      printf("\n\nMatrix 3:");



      for (i = minM; i<(m-1); i++){     /* Delete line with min element */
        for(k = 0; k<n; k++){
            matr[i][k] = matr[i+1][k];
        }
      }

        for (i = 0; i<(m-1); i++){      /* Delete column with min element */
            for(k = minN; k<(n-1); k++){
                matr[i][k] = matr[i][k+1];
        }
            }



    for (i = 0; i<(m-1); i++){
        printf("\n");
        for(k = 0; k<(n-1); k++){
            printf("%d ", matr[i][k]);
        }
    }


    printf("\n");

    for(i = 0; i<1000; i++){                /* Cycle for create your matrix */

            scanf("%c", &matrS2[i]);

        if (isdigit(matrS2[i])){
                matr2[i2][k2] = matrS2[i] - '0';
        }
            else
            switch(matrS2[i]){
                case ' ':
                    k2++;
                    break;
                case ',':
                    i2++;
                    k2 = 0;
                    break;
                case '.':
                    i = 1001;
                    break;
                default:
                    break;
        }
    }

    printf("\nMatrix 4\n");

    for (i = 0; i<i2+1; i++){
        printf("\n");
        for(k = 0; k<k2+1; k++){
            printf("%d ", matr2[i][k]);
        }
     }




    if(n-1==i2+1){      /* Cycle for add matrix */
        for(i = 0; i < m-1; i++){
            for(j = 0; j < k2+1; j++){
                matrItog[i][j] = 0;
                for(k = 0; k < n-1; k++){
                    matrItog[i][j] += matr[i][k] * matr2[k][j];
                }
            }
        }

        printf("\nMatrix 5:\n");

        for (i = 0; i<m-1; i++){
            printf("\n");
                for(k = 0; k<k2+1; k++){
                    printf("%d ", matrItog[i][k]);
                }
        }
    }
    else
        printf("\n\nError, impossible to add these matrix\n");

    return 0;
}
