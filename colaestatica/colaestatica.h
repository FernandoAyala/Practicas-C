#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#define TAM_COLA 300

typedef struct{
    char cola[TAM_COLA];
    unsigned pri,
             ult,
             tamDisp;
}tCola;

void crear_cola(tCola * pc);
int poner_en_cola(tCola * pc, const void * pd, unsigned tam);
int sacar_de_cola(tCola * pc, void * pd, unsigned tam);
int frente_de_cola(const tCola * pc, void * pd, unsigned tam);
int cola_llena(const tCola * pc, unsigned tam);
int cola_vacia(const tCola * pc);
void vaciar_cola(tCola * pc);

#endif // COLAESTATICA_H_INCLUDED
