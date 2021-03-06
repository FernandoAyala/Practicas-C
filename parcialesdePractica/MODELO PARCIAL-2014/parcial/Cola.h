#ifndef COLA_H
#define COLA_H

#include "Defs.h"
#include "Tipos.h"



typedef struct
{
	t_dato vcola[TAM];
	int frente;
	int fondo;
	int ce;
}
t_cola;



void crear_cola(t_cola* pcola);
int poner_en_cola(t_cola* pcola, const t_dato* pd);
int sacar_de_cola(t_cola* pcola, t_dato* pd);
int frente_de_cola(const t_cola* pcola, t_dato* pd);
int cola_vacia(const t_cola* pcola);
int cola_llena(const t_cola* pcola);
void vaciar_cola(t_cola* pcola);


#endif // COLA_H
