#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main()
{
    tFecha fecha = {12,07,2021};

    if(esFechaValida(&fecha))
        printf("La fecha %d/%d/%d es valida", fecha.dia,fecha.mes,fecha.anio);
    else
        printf("Fecha invalida");

    return 0;
}
