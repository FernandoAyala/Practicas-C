#include "pila.h"
#include <stdlib.h>
#include <string.h>


void crear_pila(tPila * pp)
{
    *pp = NULL; //inicializa puntero a la pila
}


int pila_vacia(const tPila * pp)
{
    return *pp == NULL; //Si el puntero a la pila es nulo, está vacia
}


int pila_llena(const tPila * pp, unsigned tam)
{
    ///vnodo = (tNodo *) malloc(50*sizeof(tNodo))

    void * vnodo = malloc(sizeof(tNodo)); /// asigno memoria
                                        ///   para un nodo
    void * vinfo = malloc(tam);          ///  asigno memoria para
                                        ///   info
    free(vnodo);
    free(vinfo);

    return !vnodo || !vinfo;
}

///Antes verificar !pila_llena
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

    nue->tamInfo = tam;         ///asigno sizeof del dato al nuevo nodo
    nue->sig = *pp;             ///al nodo anterior
    memcpy(nue->info, pd, tam);///copio la información de pd al nuevo nodo

    *pp = nue;                 ///el nuevo tope es el último nodo ingresado,
                              ///apunto a la pila al ultimo
                              ///recien ingresado
    return 1; ///OK
}

///Antes verificar !pila_vacia
int sacar_de_pila(tPila * pp, void * pd, unsigned tam)
{
    tNodo * elem = *pp;
    if(!*pp)
    {
        return 0; ///PILA_VACIA
    }

    memcpy(pd, elem->info, MINIMO(elem->tamInfo, tam));
    *pp = elem->sig;

    free(elem->info);
    free(elem);
    return 1; ///OK
}

///Antes verificar !pila_vacia
///int ver_tope_pila(const tPila * pp, void * pd, unsigned tamDato);
int ver_tope_pila(const tPila * pp, void * pd, unsigned tamDato)
{
    if(!*pp)
    {
        return 0;
    }

    memcpy(pd, (*pp)->info, MINIMO(tamDato, (*pp)->tamInfo));
    ///como el dato que esta en la pila puede ser de distinto tamano
    ///que la ref de memoria que te estan pasando, hay que asegurarse:
    /// (1) si el de la pila es mas chico, no leer memoria de mas
    /// (2) si el de la pila es mas grande, no pisar memoria al usuario
    ///copiando de mas
    return 1;
}

///Antes verificar !pila_vacia
///void vaciar_pila(tPila * pp);
void vaciar_pila(tPila * pp)
{
    while(*pp){
        tNodo *aux = *pp;
        *pp = aux->sig;
        free(aux->info);
        free(aux);
    }
}
