#include "piladinamica.h"
#include <stdlib.h>
#include <string.h>

void crear_pila(tPila * pp)
{
    *pp = NULL;
}
int poner_en_pila(tPila * pp, const void * pd, unsigned tam)
{
    tNodo * nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; ///PILA_LLENA
    }
    nue->info = malloc(tam);
    if (!nue->info)
    {
        free(nue);
        return 0; ///PILA_LLENA
    }
    nue->tamInfo = tam;
    nue->sig = *pp;
    memcpy(nue->info, pd, tam);
    *pp = nue;
    return 1; ///OK
}
int sacar_de_pila(tPila * pp, void * pd, unsigned tam)
{
    tNodo * elim = *pp;
    if(!*pp)
    {
        return 0; ///PILA_VACIA
    }
    memcpy(pd, elim->info, MINIMO(elim->tamInfo, tam));
    *pp = elim->sig;
    free(elim->info);
    free(elim);
    return 1; ///OK
}

///int ver_tope_pila(const tPila * pp, void * pd, unsigned tamDato);

int pila_vacia(const tPila * pp)
{
    return *pp == NULL;
}

int pila_llena(const tPila * pp, unsigned tam)
{
    void * nodo = malloc(sizeof(tNodo));
    void * info = malloc(tam);
    free(nodo);
    free(info);
    return !nodo || !info;
}

///void vaciar_pila(tPila * pp);
