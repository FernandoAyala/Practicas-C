#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
# define TAM 3

int main()
{
    int sumadiag = 0;
    int tras[][TAM]=
    {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    int mat[][TAM]=
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    if(determinarMatrizIdentidad(mat,3) == 1)
        printf("\nes Identidad");
    if(determinarMatrizDiagonal(mat,3) == 1)
        printf("\nes Diagonal");
    determinarSimetria(mat,3);
    trasponerMatriz(mat,3);
    for(int i=0; i<TAM; i++)
    {
        printf("\n");
        for(int j=0; j<TAM; j++)
        {
            printf("%3d",mat[i][j]);
        }
    }

    sumadiag = sumatoriaDiaSec(mat,3);
    printf("\nLa suma de los numeros es: %d", sumadiag);

    return 0;
}
