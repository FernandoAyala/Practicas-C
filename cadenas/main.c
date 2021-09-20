#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/*
strstr
strcmp
strcpy
strlen
strchr
strrchr
*/
int main()
{
    char texto[TAM] = "puntero a puntero es forma punteros encadenamiento123456 de punteros.";
    char primera[TAM];

    int apariciones, cant_palabras, long_palabra;

    primera_palabra(texto,primera);
    apariciones=cuantas_veces_aparece(texto,primera);
    cant_palabras=cuantas_palabras_tiene_el_texto(texto);
    long_palabra=longitud_de_la_palabra_mas_larga(texto);
    printf("LA PRIMERA PALABRA ES:                   %s\n\n",primera);
    printf("LA PRIMERA PALABRA APARECE:              %d veces\n\n",apariciones);
    printf("CANTIDAD DE PALABRAS:                    %d \n\n",cant_palabras);
    printf("LONGITUD DE LA PALABRA MAS LARGA:        %d caracteres",long_palabra);

    return 0;
}
