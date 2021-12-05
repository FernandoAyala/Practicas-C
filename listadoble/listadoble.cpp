#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadoble.h"


void crearListaD(tListaD* pl)
{
    *pl = NULL;
}

int ponerOrdListaD(tListaD* pl, const void * pd, unsigned tam, int (*cmp)(const void*, const void*))
{
    tNodoD* auxSig = *pl,
            * auxAnt = auxSig? auxSig->ant : NULL,
              * nue;

    while(auxSig && cmp(pd, auxSig->info)>0)
    {
        auxAnt = auxSig;
        auxSig = auxSig->sig;
    }
    while(auxAnt && cmp(pd, auxAnt->info)<0)
    {
        auxSig = auxAnt;
        auxAnt = auxAnt->ant;
    }
    if((auxSig && cmp(pd, auxSig->info)==0) || (auxAnt && cmp(pd, auxAnt->info)==0))
    {
        return 0; ///Duplicado
    }
    if ((nue = (tNodoD*)malloc(sizeof(tNodoD)))==NULL || (nue->info = malloc(tam))==NULL)
    {
        free(nue);
        return 0; ///Sin Memoria
    }
    memcpy(nue->info, pd, tam);
    nue->tamInfo = tam;
    nue->sig = auxSig;
    nue->ant = auxAnt;
    if (auxSig)
        auxSig->ant = nue;
    if (auxAnt)
        auxAnt->sig = nue;

    *pl = nue;
    return 1;
}

int ponerPrimeroListaD(tListaD * pl, const void * pd, unsigned tam)
{
    tNodoD* aux = *pl;
    tNodoD* nue;

    if ((nue = (tNodoD*)malloc(sizeof(tNodoD)))==NULL || (nue->info = malloc(tam))==NULL)
    {
        free(nue);
        return 0; ///Sin Memoria
    }

    while(aux->ant != NULL)
        aux= aux->ant;

    memcpy(nue->info,pd,tam);
    nue->tamInfo = tam;
    nue->sig=aux;
    nue->ant=NULL;

    if(aux)
       aux->ant= nue;

    *pl=nue;

    return 1;
}

int sacarPrimeroListaD(tListaD * pl, void * pd, unsigned tam)
{
    tNodoD* aux = *pl;

    if(aux==NULL)
    {
        return 0; ///lista vacia
    }

    while(aux->ant != NULL)
        aux = aux->ant;

    memcpy(pd, aux->info, tam);

    if(aux->sig)
        {
            aux->sig->ant = NULL;
            free(aux->info);
            free(aux);
            *pl= aux->sig;
        }

    return 1;
}

int sacarUltimoListaD(tListaD * pl, void * pd, unsigned tam)
{
    tNodoD* aux = *pl;

    if(aux==NULL)
    {
        return 0; ///lista vacia
    }

    while(aux->sig != NULL)
        aux = aux->sig;

    memcpy(pd, aux->info, tam);

    if(aux->ant)
    {
        aux->ant->sig = NULL;
        free(aux->info);
        free(aux);
        *pl= aux->ant;
    }
    else
    {
        *pl = NULL;
    }

    return 1;

}

int ponerUltimoListaD(tListaD * pl, const void * pd, unsigned tam)
{
    tNodoD* aux = *pl;
    tNodoD* nue;

    if ((nue = (tNodoD*)malloc(sizeof(tNodoD)))==NULL || (nue->info = malloc(tam))==NULL)
    {
        free(nue);
        return 0; ///Sin Mem
    }

    while(aux->sig != NULL)
        aux= aux->sig;

    memcpy(nue->info,pd,tam);
    nue->tamInfo = tam;
    nue->ant=aux;
    nue->sig=NULL;

    if(aux)
       aux->sig= nue;

    *pl=nue;

    return 1;
}

int ponerPosListaD(tListaD * pl, const void * pd, unsigned tam, unsigned pos)
{
    tNodoD* aux = *pl;
    tNodoD* auxAnt = aux? aux->ant : NULL;
    tNodoD * nue;



    while(aux->ant != NULL)
        aux = aux->ant;

    while(aux->sig && pos)
    {
        auxAnt=aux;
        aux = aux->sig;
        pos--;
    }

    if(pos)
    {
        return 0; ///Pos invalida (depende del ejercicio)
    }

    if ((nue = (tNodoD*)malloc(sizeof(tNodoD)))==NULL || (nue->info = malloc(tam))==NULL)
    {
        free(nue);
        return 0; ///Sin Mem
    }

    memcpy(nue->info, pd, tam);
    nue->tamInfo = tam;
    nue->sig = aux;
    nue->ant = auxAnt;

    if (aux)
        aux->ant = nue;
    if (auxAnt)
        auxAnt->sig = nue;

    *pl = nue;
    return 1;
}

int eliminarDatoListaD(tListaD* pl, void * pd, unsigned tam, int (*cmp)(const void*, const void*))
{
    tNodoD* elim = *pl;

    int val;

    if(elim==NULL)
    {
        return 0;
    }

    while(elim->sig && cmp(pd, elim->info)>0)
    {
        elim = elim->sig;
    }
    while(elim->ant && cmp(pd, elim->info)<0)
    {
        elim = elim->ant;
    }

    val= cmp(pd,elim->info);

    if(val==0)
    {
        if(elim->ant)
            elim->ant->sig = elim->sig;

        if(elim->sig)
        {
            elim->sig->ant = elim->ant;
            *pl= elim->sig;

        }
        else
            *pl= elim->ant;

        free(elim->info);
        free(elim);
    }

    return 1;

}

int listaVacia(tListaD* pl)
{
    return *pl == NULL;
}

void vaciarListaD(tListaD* pl)
{
    tNodoD* aux = *pl;
    tNodoD* aux2;

    if(aux!=NULL)
    {
        while(aux->ant != NULL)
            aux = aux->ant;

        while(aux!=NULL)
        {
            aux2 = aux->sig;

            free(aux->info);
            free(aux);

            aux=aux2;
        }

        *pl=NULL;
    }
}

void recorrerListaD(tListaD * pl, void (*accion)(void*, void*), void* param)
{
    tNodoD* aux = *pl;

    while(aux->ant != NULL)
        aux = aux->ant;

    while(aux!=NULL)
    {
       accion(aux->info, param);
       aux=aux->sig;
    }
}
