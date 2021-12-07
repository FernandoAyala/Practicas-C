#include <tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <arbol.h>

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))


int insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,
                         int (*cmp)(const void *, const void *))
{
    int rc;
    tNodoArbol * nue;

    while(*p)
    {
        if((rc = cmp(d, (*p)->info)) < 0)
            p = &(*p)->izq;
        else if(rc > 0)
            p = &(*p)->der;
        else
            return DUPLICADO;
    }

    nue = (tNodoArbol *)malloc(sizeof(tNodoArbol));
    if(!nue)
        return SIN_MEM;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info, d, tam);
    nue->tamInfo = tam;
    nue->izq = nue->der = NULL;

    *p = nue;

    return TODO_OK;
}


tNodoArbol ** buscarNodoArbolBinBusq(tArbolBinBusq *p, const void *d, int(*cmp)(const void *, const void *))
{
    int rc;

    while(*p && (rc = cmp(d, (*p)->info)))
    {
        if(rc < 0)
            p = &(*p)->izq;
        else
            p = &(*p)->der;
    }
    if(!(*p))
        return NULL;

    return (tNodoArbol **)p;
}



tNodoArbol ** mayorNodoArbolBinBusq(const tArbolBinBusq * p)
{
    if(!*p)
        return NULL;

    while((*p)->der)
        p = &(*p)->der;

    return (tNodoArbol **)p;
}


tNodoArbol ** menorNodoArbolBinBusq(const tArbolBinBusq * p)
{
    if(!*p)
        return NULL;

    while((*p)->izq)
        p = &(*p)->izq;

    return (tNodoArbol **)p;
}


unsigned alturaArbolBin(const tArbolBinBusq * p)
{
    int hi,
        hd;

    if(!*p)
        return 0;

    hi = alturaArbolBin(&(*p)->izq);
    hd = alturaArbolBin(&(*p)->der);

    return (hi > hd ? hi : hd) + 1;
}


int eliminarRaizArbolBinBusq(tArbolBinBusq * p)
{
    tNodoArbol ** remp,
                * elim;

    if(!(*p))
        return 0; /// arbol vacio

    free((*p)->info);
    if(!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p = NULL;
        return 1; /// OK
    }
    remp = alturaArbolBin(&(*p)->izq) > alturaArbolBin(&(*p)->der) ?
           mayorNodoArbolBinBusq(&(*p)->izq) : menorNodoArbolBinBusq(&(*p)->der);

    elim = *remp;

    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;
    *remp = elim->izq ? elim->izq : elim->der;
    free(elim);

    return 1;
}


/// resp = eliminarElemArbolBinBusq(pa, &reg_ind, sizeof(tRegInd), cmp_alu_dni);
int eliminarElemArbolBinBusq(tArbolBinBusq *p, void *d, unsigned tam,
                             int(*cmp)(const void *, const void *))
{
    if(!(p = buscarNodoArbolBinBusq(p, d, cmp)))
       return NO_EXISTE;
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return eliminarRaizArbolBinBusq(p);
}


void recorrerEnOrdenRecArbolBinBusq_mio(const tArbolBinBusq * p, unsigned n, void * params,
                                 void (*accion)(void *, unsigned, unsigned, void *))
{
    if(!*p)
        return;
    recorrerEnOrdenRecArbolBinBusq_mio(&(*p)->izq, n+1, params, accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenRecArbolBinBusq_mio(&(*p)->der, n+1, params, accion);
}


///  recorrerEnOrdenArbolBinBusq(pa, arch, buscar_y_mostrar_alumno);
void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq * p, void * params,
                                 void (*accion)(void *, unsigned, unsigned, void *))
{
    recorrerEnOrdenRecArbolBinBusq_mio(p, 0, params, accion);
}

