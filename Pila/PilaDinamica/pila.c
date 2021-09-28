#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define minimo(X, Y) ((X) < (Y)? (X) : (Y))
#define FALSO 0
#define VERDADERO 1

void crear_pila(tPila *p)
{
    *p = NULL;
}

int pila_llena(const tPila *p, unsigned tam)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(tam);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int poner_en_pila(tPila *p, const void *d, unsigned tam)
{
    tNodo *nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; ///PILA_LLENA
    }
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0; ///PILA_LLENA
    }

    memcpy(nue->info, d, tam);
    nue->tamInfo = tam;
    nue->sig = *p;
    *p = nue;
    return 1; /// OK
}

int ver_tope(const tPila *p, void *d, unsigned tam)
{
    if(*p == NULL)
        return 0;

    memcpy(d, (*p)->info, minimo(tam, (*p)->tamInfo));
    return 1;
}

int pila_vacia(const tPila *p)
{
    return *p == NULL;
}

int sacar_de_pila(tPila *p, void *d, unsigned tam)
{
    tNodo *aux = *p;

    if(aux == NULL)
        return 0; ///PILA VACIA

    *p = aux->sig;
    memcpy(d, aux->info, minimo(tam, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1; ///OK
}

void vaciar_pila(tPila *p)
{
    while(*p)
    {
        tNodo *aux= *p;

        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
