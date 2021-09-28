#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define minimo(X, Y) ((X) < (Y)? (X) : (Y))
#define FALSO 0
#define VERDADERO 1

void crear_pila(tPila *p)
{
    p->tope = TAM_PILA;
}

int pila_llena(const tPila *p, unsigned tam)
{
    return p->tope < (tam + sizeof(unsigned));
}

int poner_en_pila(tPila *p, const void *d, unsigned tam)
{
    if(p->tope < (tam + sizeof(unsigned)))
    {
        return 0; ///PILA LLENA
    }
    p->tope -= tam;
    memcpy(p->pila + p->tope, d, tam);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &tam, sizeof(unsigned));
    return 1; ///OK
}

int ver_tope(const tPila *p, void *d, unsigned tam)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
    {
        return 0; ///PILA VACIA
    }
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), minimo(tam, tamInfo));
    return 1; ///OK
}

int pila_vacia(const tPila *p)
{
    return p->tope == TAM_PILA;
}

int sacar_de_pila(tPila *p, void *d, unsigned tam)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
    {
        return 0; ///PILA VACIA
    }
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(tam, tamInfo));
    p->tope += tamInfo;
    return 1; ///OK
}

void vaciar_pila(tPila *p)
{
    p->tope = TAM_PILA;
}
