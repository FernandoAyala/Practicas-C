#include"cola.h"

#define minimo(X,Y)     ((X) <= (Y) ? (X) : (Y) )

void crearCola(tCola *p)
{
    p->pri = NULL;
    p->ult = NULL;
}

int colaLlena(const tCola *p, unsigned tam)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void  *info = malloc(tam);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int ponerEnCola(tCola *p, const void *d, unsigned tam)
{
    tNodo *nue = (tNodo *)malloc(sizeof(tNodo));
    if(nue == NULL || (nue->info = malloc(tam)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, tam);
    nue->tamInfo = tam;
    if(p->ult)
        p->ult->sig = nue;
    else
        p->pri = nue;
    p->ult = nue;
    return 1;
}

int verPrimeroCola(const tCola *p, void *d, unsigned tam)
{
    if(p->pri == NULL)
        return 0;
    memcpy(d, p->pri->info, minimo(tam, p->pri->tamInfo));
    return 1;
}

int colaVacia(const tCola *p)
{
    return p->pri == NULL;
}

int sacarDeCola(tCola *p, void *d, unsigned tam)
{
    tNodo *aux = p->pri;
    if(aux == NULL)
        return 0;
    p->pri = aux->sig;
    memcpy(d, aux->info, minimo(aux->tamInfo, tam));
    free(aux->info);
    free(aux);
    if(p->pri == NULL)
        p->ult = NULL;
    return 1;
}

void vaciarCola(tCola *p)
{
    while(p->pri)
    {
        tNodo *aux= p->pri;
        p->pri = aux->sig;
        free(aux->info);
        free(aux);
    }
    p->ult = NULL;
}
