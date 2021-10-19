#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define PILA_LLENA 0
#define PILA_VACIA PILA_LLENA
#define OK 1

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))

typedef struct sNodo
{
    void * info;        ///guardo el dato (8 bytes)
    unsigned tamInfo;   ///sizeof del dato (8 bytes)
    struct sNodo * sig; ///puntero al próximo nodo (8 bytes)
}tNodo;

typedef tNodo* tPila; ///puntero a la pila o tope

void crear_pila(tPila * pp);

int poner_en_pila(tPila * pp, const void * pd, unsigned tamDato);
int sacar_de_pila(tPila * pp, void * pd, unsigned tamDato);
int ver_tope_pila(const tPila * pp, void * pd, unsigned tamDato);///

int pila_vacia(const tPila * pp);
int pila_llena(const tPila * pp, unsigned tamDato);

void vaciar_pila(tPila * pp);///

#endif // PILA_H_INCLUDED
