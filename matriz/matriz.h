#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int sumatoriaDiagonalPrincipal( int mat[][TAM],int orden);
int sumatoriaSupDiaPpal(int mat [][TAM], int orden);
int sumatoriaDiaPpal(int mat [][TAM], int orden);
int sumatoriaDiagonalSecundaria(int mat [][TAM], int orden);
int sumatoriaDiaSec(int mat [][TAM], int orden);
int determinarMatrizIdentidad( int mat [][TAM], int orden);
int determinarMatrizDiagonal( int mat [][TAM],int orden);
#endif // MATRIZ_H_INCLUDED
