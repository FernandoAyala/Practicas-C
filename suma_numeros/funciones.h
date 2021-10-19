#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "pila.h"

void llenar_pila(FILE *arch, tPila *pila);
void sumar_pilas(tPila *pila1, tPila *pila2, tPila *pila_res);
void grabar_resultado(FILE *arch, tPila *pila_res);
#endif // FUNCIONES_H_INCLUDED
