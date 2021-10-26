#include<lista.h>
#include<stdlib.h>
#include<stdio.h>
#define SIN_MEM 0
#define CLA_DUP 2

///ARREGLAR ESTA FUNCION DEL ORTO

int instertar_prim5_lista(t_lista * plista, const t_info * pinfo, t_cmp_lista comp)
{
        t_nodo *nue;
    int cont = 0;
    while(*plista && comp(&(*plista)->info, pinfo) < 0  && cont<=5)
       {
        cont++;
        plista = &(*plista)->psig;
       }
    nue = (t_nodo *)malloc(sizeof(t_nodo));
    if(nue == NULL)
        return SIN_MEM;
    nue->info = *pinfo;
    nue->psig = *plista;
    *plista = nue;
    cont++;
    while(*plista && cont <= 5)
        {

            plista = &(*plista)->psig;
            cont++;
        }
        if(cont >= 5)
        {
            free(*plista);
            *plista = NULL;
        }


    return OK;
}
