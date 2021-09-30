#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia,
        mes,
        anio;
}tFecha;

int esFechaValida(const tFecha * f);
int cantDiasMes(int mes, int anio);
int esBisiesto(int anio);
int diaSiguiente(tFecha *f);

#endif // FECHA_H_INCLUDED
