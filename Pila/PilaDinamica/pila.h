#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

///PILA DINAMICA
#include <stdlib.h>


typedef struct sNodo
{
    void        *info;
    unsigned  tamInfo;
    struct sNodo *sig;
}tNodo;
typedef tNodo *tPila;

void crear_pila(tPila *p);
int pila_llena(const tPila *p, unsigned tam);
int poner_en_pila(tPila *p, const void *d, unsigned tam);
int ver_tope(const tPila *p, void *d, unsigned tam);
int pila_vacia(const tPila *p);
int sacar_de_pila(tPila *p, void *d, unsigned tam);
void vaciar_pila(tPila *p);


#endif // PILA_H_INCLUDED
