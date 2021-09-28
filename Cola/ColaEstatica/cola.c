#include "cola.h"

#define minimo(X,Y)     ((X) <= (Y) ? (X) : (Y) )

void crearCola(tCola *p)
{
    p->pri      = TAM_COLA - 70;
    p->ult      = TAM_COLA - 70;
    p->tamDisp  = TAM_COLA;
}

int colaLlena(const tCola *p, unsigned tam)
{
    return p->tamDisp < tam + sizeof(unsigned);
}

int ponerEnCola(tCola *p, const void *d, unsigned tam)
{
    unsigned ini,
             fin;

    if(p->tamDisp < sizeof(unsigned) + tam)
        return 0;
    p->tamDisp -= sizeof(unsigned) + tam;
    if((ini = minimo(sizeof(tam), TAM_COLA - p->ult)) != 0)
        memcpy(p->cola + p->ult, &tam, ini);
    if((fin = sizeof(tam) - ini) != 0)
        memcpy(p->cola, ((char *)&tam) + ini, fin);
    p->ult = fin ? fin : p->ult + ini;
    if((ini = minimo(tam, TAM_COLA - p->ult)) != 0)
        memcpy(p->cola + p->ult, d, ini);
    if((fin = tam - ini) != 0)
        memcpy(p->cola, ((char *)d) + ini, fin);
    p->ult = fin ? fin : p->ult + ini;
    return 1;

}

int verPrimeroCola(const tCola *p, void *d, unsigned tam)
{
    unsigned tamInfo,
             ini,
             fin,
             pos = p->pri;
    if(p->tamDisp == TAM_COLA)
        return 0;
    if((ini = minimo(sizeof(unsigned), TAM_COLA - pos)) !=0 )
        memcpy(&tamInfo, p->cola + pos, ini);
    if((fin = sizeof(unsigned) - ini) !=0 )
        memcpy(((char *)&tamInfo) + ini, p->cola, fin);
    pos = fin ? fin : pos + ini;
    tamInfo = minimo(tamInfo , tam);
    if((ini = minimo(tamInfo, TAM_COLA - pos)) !=0 )
        memcpy(d, p->cola + pos, ini);
    if((fin = tamInfo - ini) !=0 )
        memcpy(((char *)d) + ini, p->cola, fin);
    return 1;
}

int colaVacia(const tCola *p)
{
    return p->tamDisp == TAM_COLA;
}

int sacarDeCola(tCola *p, void *d, unsigned tam)
{
    unsigned    tamInfo,
                ini,
                fin;

    if(p->tamDisp == TAM_COLA)
        return 0;
    if((ini = minimo(sizeof(unsigned), TAM_COLA - p->pri)) !=0)
        memcpy(&tamInfo, p->cola + p->pri, ini);
    if((fin = sizeof(unsigned) - ini) != 0 )
        memcpy(((char *)&tamInfo) + ini, p->cola, fin);
    p->pri = fin ? fin : p->pri + ini;
    p->tamDisp += sizeof(unsigned) + tamInfo;
    tamInfo = minimo(tamInfo, tam);
    if((ini = minimo(tamInfo, TAM_COLA - p->pri)) != 0)
        memcpy(d, p->cola + p->pri, ini);
    if((fin = tamInfo - ini) != 0)
        memcpy(((char *)d) + ini, p->cola, fin);
    p->pri = fin ? fin : p->pri + ini;
    return 1;
}

void vaciarCola(tCola *p)
{
    p->ult = p->pri;
    p->tamDisp = TAM_COLA;
}
