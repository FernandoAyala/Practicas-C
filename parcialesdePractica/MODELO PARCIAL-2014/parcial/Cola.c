#include "Cola.h"



void crear_cola(t_cola* pcola)
{
	pcola->frente = 0;
	pcola->fondo = -1;
	pcola->ce = 0;
}



int poner_en_cola(t_cola* pcola, const t_dato* pd)
{
	if(pcola->ce == TAM)
		return FALSO;

	pcola->fondo = (pcola->fondo + 1) % TAM;

	pcola->vcola[pcola->fondo] = *pd;

	pcola->ce++;

	return VERDADERO;
}



int sacar_de_cola(t_cola* pcola, t_dato* pd)
{
	if(pcola->ce == 0)
		return FALSO;

	*pd = pcola->vcola[pcola->frente];

	pcola->frente = (pcola->frente + 1) % TAM;

	pcola->ce--;

	return VERDADERO;
}



int frente_de_cola(const t_cola* pcola, t_dato* pd)
{
	if(pcola->ce == 0)
		return FALSO;

	*pd = pcola->vcola[pcola->frente];

	return VERDADERO;
}



int cola_vacia(const t_cola* pcola)
{
	return pcola->ce == 0;
}



int cola_llena(const t_cola* pcola)
{
	return pcola->ce == TAM;
}



void vaciar_cola(t_cola* pcola)
{
	pcola->frente = 0;
	pcola->fondo = -1;
	pcola->ce = 0;
}


