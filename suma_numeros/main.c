#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "funciones.h"

int main()
{
    FILE *arch = fopen("ARCHIVO_NUMEROS.txt", "r+");
    tPila pila1, pila2, pila_res;

    ///abrir archivo
    if(!arch){
        printf("Error de apertura de archivo");
        return 1;
    }
    ///crear pilas
    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pila_res);

    ///llenar pilas
    llenar_pila(arch, &pila1);
    llenar_pila(arch, &pila2);

    ///sumar y armar otra pila con el resultado
    sumar_pilas(&pila1, &pila2, &pila_res);

    ///grabar archivo con el resultado
    grabar_resultado(arch, &pila_res);


    ///cerrar archivo
    fclose(arch);

    return 0;
}
