#include "pilaestatica.h"
#include <string.h>

void crear_pila(tPila * pp)
{
    pp->tope = TAM_PILA;
}

int poner_en_pila(tPila * pp, const void * pd, unsigned tamDato)
{
    if(pp->tope<(tamDato+sizeof(unsigned)))
    {
        return 0;///PILA_LLENA
    }
    pp->tope-=tamDato;
    memcpy(pp->pila+pp->tope, pd, tamDato);
    pp->tope-=sizeof(unsigned);
    memcpy(pp->pila+pp->tope, &tamDato, sizeof(unsigned));
    return 1; ///OK
}

int sacar_de_pila(tPila * pp, void * pd, unsigned tamDato)
{
    unsigned tamDatoPila;
    if(pp->tope>=TAM_PILA)
    {
        return 0; ///PILA_VACIA
    }
    memcpy(&tamDatoPila, pp->pila+pp->tope, sizeof(unsigned));
    pp->tope+= sizeof(unsigned);
    memcpy(pd, pp->pila+pp->tope, MINIMO(tamDatoPila,tamDato));
    pp->tope+=tamDatoPila;
    return 1; ///OK
}

int ver_tope_pila(const tPila * pp, void * pd, unsigned tamDato)
{
    unsigned tamDatoPila;
    if(pp->tope>=TAM_PILA)
    {
        return 0; ///PILA_VACIA
    }
    memcpy(&tamDatoPila, pp->pila+pp->tope, sizeof(unsigned));
    memcpy(pd, pp->pila + pp->tope+sizeof(unsigned), MINIMO(tamDatoPila,tamDato));
    return 1; ///OK
}

int pila_vacia(const tPila * pp)
{
    return pp->tope>=TAM_PILA;
}

int pila_llena(const tPila * pp, unsigned tamDato)
{
    return pp->tope<(tamDato+sizeof(unsigned));
}
