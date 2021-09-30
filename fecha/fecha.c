#include "fecha.h"

/****Ejercicio 14 ******/

int esFechaValida (const tFecha *f)
{
    if(f->anio>1600)
        if(f->mes>=1 && f->mes<=12)
            if(f->dia>=1 && f->dia <= cantDiasMes(f->mes,f->anio))
                return 1;
    return 0;
}

int cantDiasMes (int mes, int anio)
{
    static const int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return esBisiesto(anio) && mes == 2 ? 29 : diasMes[mes-1];
}

int esBisiesto (int anio)
{
    return anio%400 == 0 || (anio%4 == 0 && anio% 100 != 0);
}

/*****Ejercicio 15 *********/

int diaSiguiente(tFecha *f)
{
    f->dia++;
    if(f->dia > cantDiasMes(f->mes,f->anio))
    {
        f->dia=1;
        f->mes++;
        if(f->mes>12)
        {
            f->mes =1;
            f->anio++;
        }
    }
    return 1;
}

/*****Ejercicio 16 *********/
