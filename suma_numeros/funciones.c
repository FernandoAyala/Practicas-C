#include <stdio.h>
#include <string.h>

#include "funciones.h"
#include "pila.h"
#define TAM 20

void llenar_pila(FILE *arch, tPila *pila)
{
    ///7159821832\n
    char registro[TAM], *preg;
    int dato, i;

    fgets(registro, TAM, arch);

    preg = strchr(registro, '\n');
    *preg = '\0';

    for(i = 0; i < strlen(registro); i++){
        if( !pila_llena(pila, sizeof(dato)) ){
            dato = registro[i] - '0';
            poner_en_pila(pila, &dato, sizeof(dato));
        }
    }
}


void sumar_pilas(tPila *pila1, tPila *pila2, tPila *pila_res)
{
    ///7159821832
    ///  35432120
    int dato1, dato2, dato3, acarreo = 0;

    while( !pila_vacia(pila1) && !pila_vacia(pila2) ){
        sacar_de_pila(pila1, &dato1, sizeof(dato1));
        sacar_de_pila(pila2, &dato2, sizeof(dato2));

        dato3 = (dato1 + dato2 + acarreo)%10;
        acarreo = (dato1 + dato2 + acarreo)/10;

        poner_en_pila(pila_res, &dato3, sizeof(dato3));
    }

    ///pila2 termino
    while(!pila_vacia(pila1)){
        sacar_de_pila(pila1, &dato1, sizeof(dato1));

        dato3 = (dato1 + acarreo)%10;
        acarreo = (dato1 + acarreo)/10;

        poner_en_pila(pila_res, &dato3, sizeof(dato3));
    }

    ///pila1 termino
    while(!pila_vacia(pila2)){
        sacar_de_pila(pila2, &dato2, sizeof(dato2));

        dato3 = (dato2 + acarreo)%10;
        acarreo = (dato2 + acarreo)/10;

        poner_en_pila(pila_res, &dato3, sizeof(dato3));
    }
    if(acarreo){
        poner_en_pila(pila_res, &acarreo, sizeof(acarreo));
    }
}


void grabar_resultado(FILE *arch, tPila *pila_res)
{
    int dato;

    ///fprintf(arch, "%d", dato);
    fseek(arch, 0L, 1);
    while( !pila_vacia(pila_res) ){
        sacar_de_pila(pila_res, &dato, sizeof(dato));
        fputc(dato + '0', arch);
    }
}
