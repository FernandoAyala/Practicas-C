#include <string.h>
#include "funciones.h"

void primera_palabra(const char *texto, char *primera)
{
    while(*texto != ' ')
    {
        *primera = *texto;

        primera++;
        texto++;
    }

    *primera = '\0';
}

int cuantas_veces_aparece(const char *texto, const char *palabra)
{
    char aux[TAM], *paux = aux;
    int i, cantidad=0;

    while(*texto != '.')
    {
        i=0;
        while(*texto != '.' && *texto != ' ')
        {
            *paux = *texto;
            paux++;
            texto++;
            i++;
        }

        *paux='\0';
        paux -= i*sizeof(char);

        if( strcmp(paux, palabra) == 0 )
        {
            cantidad ++;
        }

        if(*texto != '.')
            texto++;
    }
    return cantidad;

}

int cuantas_palabras_tiene_el_texto(const char *texto)
{
    int cont_palabras = 0;
    while(*texto != '\0')
    {
        if(*texto == ' ' || *texto== '.')
            cont_palabras++;
        texto++;
    }
    return cont_palabras;
}

int longitud_de_la_palabra_mas_larga(const char *texto)
{
    int cont_long = 0, cont_aux = 0, cont_may = 0;

    while(*texto != '\0')
    {
        if(*texto != ' ')
        {
            cont_long++;
        }

        texto++;
    }
    return cont_may;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//char* normalizar(char * cad);
//int main()
//{
//    char cad[] = "    pErEz      GomEz   , JoSe    albeRTO          ";
//    printf("*%s*", normalizar(cad));
//    return 0;
//}
//
//char* normalizar(char * cad)
//{
//    char * lect = cad, * esc = cad;
//    int primeraLetraPalabra;
//    while(*lect)
//    {
//        while(isspace(*lect))
//            lect++;
//        if(*lect)
//        {
//            primeraLetraPalabra = 1;
//            while(*lect && !isspace(*lect))
//            {
//                *esc = primeraLetraPalabra? toupper(*lect) : tolower(*lect);
//                primeraLetraPalabra = 0;
//                esc++;
//                lect++;
//            }
//            *esc = ' ';
//            esc++;
//        }
//    }
//    *(esc-1) = '\0';
//    return cad;
//}
