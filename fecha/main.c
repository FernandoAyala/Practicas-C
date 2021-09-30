#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main()
{
    tFecha fecha = {28,02,2020};

    if(esFechaValida(&fecha))
        printf("La fecha %d/%d/%d es valida", fecha.dia,fecha.mes,fecha.anio);
    else
        printf("Fecha invalida");

    diaSiguiente(&fecha);
    printf("\nLa fecha dia sig es: %d/%d/%d", fecha.dia,fecha.mes,fecha.anio);

    return 0;
}
