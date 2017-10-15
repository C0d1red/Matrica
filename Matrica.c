#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int m, n, m2, n2, i, k, min, minM, minN;
    printf("m and n:\n");
    scanf("%d %d", &m, &n );
    m2 = n2 = 0;
    int matr[m][n], strS[n], strE[n], matr2[m2][n2];
    char matrS2[1000];

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



      printf("\n\nMatrica 3:");



      for (i = minM; i<(m-1); i++){
        for(k = 0; k<n; k++){
            matr[i][k] = matr[i+1][k];
                        }
                    }

        for (i = 0; i<(m-1); i++){
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

/*
    printf("\n");
    fgets(matrS2, 1000, stdin);

    for(i = 0; i<1000; i++){
        if (isdigit(matrS2[i])){
                matr2[m2][n2] = matrS2[i] - '0';
                printf("\n VVeli: %d\n", matr[m2][n2]);
        }
            else
            switch(matrS2[i]){
                case ' ':
                    n2++;
                    break;
                case ',':
                    m2++;
                    n2 = 0;
                    break;
                case '.':
                    i = 1001;
                    break;
                default:
                    break;
        }

        }

    printf("\nMatrica 4\n");

    for (i = 0; i<m2; i++){
        printf("\n");
        for(k = 0; k<n2; k++){
            printf("%d ", matr2[i][k]);
        }
     }
*/




    return 0;
}
