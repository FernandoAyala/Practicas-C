#include "matriz.h"

int sumatoriaDiagonalPrincipal( int mat[][TAM],int orden)
{
    int sumatoria= 0;
    for(int i=0; i<orden; i++)
        sumatoria+=mat[i][i];
    return sumatoria;
}

int sumatoriaSupDiaPpal(int mat [][TAM], int orden)
{
    int sumatoria= 0;
    for(int i=0; i<orden; i++)
    {
        for(int j= i+1; j<orden ; j++)
            sumatoria+=mat[i][j];
    }
    return sumatoria;
}

int sumatoriaDiaPpal(int mat [][TAM], int orden)
{
    int sumatoria= 0;
    for(int i=0; i<orden; i++)
    {
        for(int j= i; j<orden ; j++)
            sumatoria+=mat[i][j];
    }
    return sumatoria;
}

int sumatoriaDiagonalSecundaria(int mat [][TAM], int orden)
{
    int sumatoria = 0;
    for (int i=0; i<orden; i++)
        for(int j=orden-1; j>=0; j--)
            if(j+i == orden-1)
            sumatoria+=mat[i][j];
    return sumatoria;
}

int sumatoriaDiaSec(int mat [][TAM], int orden)
{
    int sumatoria = 0;
    for (int i=0; i<orden; i++)
        for(int j=0; j<orden-i; j++)/*-1 al final me excluye los de la diagonal sec*/
            sumatoria+=mat[i][j];
    return sumatoria;
}

