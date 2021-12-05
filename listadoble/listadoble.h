#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

typedef struct sNodo
{
    void * info;
    unsigned tamInfo;
    struct sNodo * sig;
    struct sNodo * ant;
} tNodoD;

typedef tNodoD * tListaD;

void crearListaD(tListaD* pl);
void vaciarListaD(tListaD* pl);
void recorrerListaD(tListaD * pl, void (*accion)(void*, void*), void* param);
int ponerOrdListaD(tListaD* pl, const void * pd, unsigned tam, int (*cmp)(const void*, const void*));
int ponerPrimeroListaD(tListaD * pl, const void * pd, unsigned tam);
int ponerUltimoListaD(tListaD * pl, const void * pd, unsigned tam);
int ponerPosListaD(tListaD * pl, const void * pd, unsigned tam, unsigned pos);
int sacarPrimeroListaD(tListaD * pl, void * pd, unsigned tam);
int sacarUltimoListaD(tListaD * pl, void * pd, unsigned tam);
int eliminarDatoListaD(tListaD* pl, void * pd, unsigned tam, int (*cmp)(const void*, const void*));
int listaVacia(tListaD* pl);



#endif // LISTADOBLE_H_INCLUDED
