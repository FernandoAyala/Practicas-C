#include "matriz.h"

/** Ejercicio 29,30**/
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

/** Ejercicio 29,30**/

/** Ejercicio 31 ***/
int determinarMatrizDiagonal( int mat [][TAM],int orden)
{
    for (int i=0;i <orden ; i++)
    {
        if(mat[i][i] == 0)
        {
            return 0;
        }
        for(int j=0; j<orden ; j++)
        {
            if( j!=i && mat[i][j] !=0)
            {
                return 0;
            }
        }
    }
    return 1;
}


/** Ejercicio 32 ***/
int determinarMatrizIdentidad( int mat [][TAM],int orden)
{
    for (int i=0;i <orden ; i++)
    {
        if(mat[i][i] != 1)
        {
            return 0;
        }
        for(int j=0; j<orden ; j++)
        {
            if( j!=i && mat[i][j] !=0)
            {
                return 0;
            }
        }
    }
    return 1;
}

