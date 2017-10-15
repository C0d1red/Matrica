#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    int m, n, m2, n2, i, k, i2, k2, i3, k3, min, minM, minN;
    printf("m and n:\n");
    scanf("%d %d", &m, &n );
    m2 = n2 = 20;
    i2 = k2 = 0;
    int matr[m][n], strS[n], strE[n], matr2[m2][n2], matrItog[m][n2];
    char matrS2[1000];

    min = 9999999;
    minN = 9999999;
    minM = 9999999;

    srand( time(0) );

    printf("Matrica 1:\n");


    for (i = 0; i<m; i++){      /* Zapolnenie i vivod matrici M x N, poisk min stroki i stolbca */
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

    for(i = 0; i < n; i++){     /* Dva cikla dlya perevorota strok i ix perestavleniya */
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



      printf("\n\nMatrica 3:");



      for (i = minM; i<(m-1); i++){     /* Udalenie stroki s naim elementom */
        for(k = 0; k<n; k++){
            matr[i][k] = matr[i+1][k];
        }
      }

        for (i = 0; i<(m-1); i++){      /* Udalenie stolbca s naim elementom */
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

    for(i = 0; i<1000; i++){                /* Cikl sozdaniya proizvolnoy matrici */

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

    printf("\nMatrica 4\n");

    for (i = 0; i<i2+1; i++){
        printf("\n");
        for(k = 0; k<k2+1; k++){
            printf("%d ", matr2[i][k]);
        }
     }

/*
     if(n==(i2+1)){
        for(i = 0; i<m; i++){
            for(k = 0; k<n; i++){
                matrItog[i3][k3] += matr[i][k]*matr2[k][i];
            }
            i3++;
            k3 = 0;
        }

    for (i = 0; i<m; i++){
        printf("\n");
        for(k = 0; k<n2; k++){
            printf("%d ", matrItog[i][k]);
        }
     }
     }

*/

    return 0;
}
