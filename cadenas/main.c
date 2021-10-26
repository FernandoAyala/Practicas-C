#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "cadenas.h"
#include <string.h>
/*
strstr Listo
strcmp Listo
strcpy Listo
strlen Listo
strchr Listo
strrchr Listo
memcpy
*/
int main()
{
    char texto[TAM] = "puntero a puntero es forma punteros encadenamiento123456 de punteros.";
    char primera[TAM];
    char pala[5]="Ho";
    char pala1[5]="la";
    char pala2[20]="Holacuates";
    char copi[TAM];
    int val;

    t_movimiento_banco mov ={"637043",'D',404.4};

   val = validar_nro_cuenta(&mov);

   printf("\nVal %d \n",val);

    int cantLetras,apariciones, cant_palabras, cmp/*, long_palabra*/;

    primera_palabra(texto,primera);
    apariciones=cuantas_veces_aparece(texto,primera);
    cant_palabras=cuantas_palabras_tiene_el_texto(texto);
    //long_palabra=longitud_de_la_palabra_mas_larga(texto);
    printf("LA PRIMERA PALABRA ES:                   %s\n\n",primera);
    printf("LA PRIMERA PALABRA APARECE:              %d veces\n\n",apariciones);
    printf("CANTIDAD DE PALABRAS:                    %d \n\n",cant_palabras);
    //printf("LONGITUD DE LA PALABRA MAS LARGA:        %d caracteres",long_palabra);

    cantLetras = mi_strlen(pala);

    printf("\nCantidad de letras: %d", cantLetras);

    char s[13] = "Hola amigos";
    char c = 'a';

    printf("\n%s \ny \n%c \n=> \n%s",s,c,mi_strrchr(s,c));

    printf("\nCopia : %s\n",mi_strcpy(copi,pala));

    cmp = mi_strcmp(copi,s);
    if(cmp == 0)
    {
        printf("Iguales");
    }
    else if(cmp > 0)
    {
        printf("Mayor");
    }
    else
    {
        printf("Menor");
    };

    printf("\n/**STRSTR**/\n%s \ny \n%s \n=> \n%s",pala1,pala2,mi_strstr(pala2,pala1));
    printf("\n/**STRSTR REAL**/\n%s \ny \n%s \n=> \n%s",pala1,pala2, strstr(pala2,pala1));
    return 0;
}
