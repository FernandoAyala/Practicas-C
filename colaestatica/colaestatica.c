#include "colaestatica.h"
#include<string.h>
void crear_cola(tCola * pc)
{
    pc->pri = TAM_COLA - 70;
    pc->ult = TAM_COLA - 70;
    pc->tamDisp = TAM_COLA;
}
int poner_en_cola(tCola * pc, const void * pd, unsigned tam)
{
    int ini,
        fin;
    if((tam+sizeof(unsigned)) > pc->tamDisp)
    {
        return 0; ///COLA_LLENA
    }
//    memcpy(pc->cola+pc->ult, &tam, sizeof(unsigned));
//    pc->ult+=sizeof(unsigned);
 if((ini = MINIMO(TAM_COLA - pc->ult, sizeof(unsigned)))>0)
    memcpy(pc->cola+pc->ult, &tam, ini);
    if ((fin = sizeof(unsigned)-ini) != 0)
        memcpy(pc->cola, ((char*)&tam) + ini, fin);
    pc->ult = !fin ? pc->ult + sizeof(unsigned) : fin;
//    memcpy(pc->cola+pc->ult, pd, tam);
//    pc->ult+=tam;
 if((ini = MINIMO(TAM_COLA - pc->ult, tam))>0)
    memcpy(pc->cola+pc->ult, pd, ini);
    if ((fin = tam-ini) != 0)
        memcpy(pc->cola, pd + ini, fin);
    pc->ult = !fin ? pc->ult + tam : fin;
    pc->tamDisp -= (tam+sizeof(unsigned));
    return 1; ///OK
}

int sacar_de_cola(tCola * pc, void * pd, unsigned tam)
{
    unsigned tamInfoCola;
    int ini,
        fin;
    if(pc->tamDisp==TAM_COLA)
    {
        return 0; ///COLA_VACIA
    }
//    memcpy(&tamInfoCola, pc->cola + pc->pri, sizeof(unsigned));
//    pc->pri+=sizeof(unsigned);
  if ((ini = MINIMO(TAM_COLA - pc->pri, sizeof(unsigned))) > 0)
    memcpy(&tamInfoCola, pc->cola + pc->pri, ini);
    if ((fin = sizeof(unsigned) - ini) > 0)
        memcpy(((char*)&tamInfoCola) + ini, pc->cola, fin);
    pc->pri = fin ? fin : pc->pri + sizeof(unsigned);
//    memcpy(pd, pc->cola + pc->pri, MINIMO(tamInfoCola, tam));
//    pc->pri+=tamInfoCola;
 if ((ini = MINIMO(TAM_COLA - pc->pri, tamInfoCola)) > 0)
    memcpy(pd, pc->cola + pc->pri, MINIMO(ini, tam));
    if ((fin = tamInfoCola - ini) > 0 && tam-ini > 0)
        memcpy(pd + ini, pc->cola, MINIMO(fin, tam - ini));
    pc->pri = fin ? fin : pc->pri + tamInfoCola;
    pc->tamDisp += sizeof(unsigned) + tamInfoCola;
    return 1; ///OK
}

//int frente_de_cola(const tCola * pc, void * pd, unsigned tam);

int cola_llena(const tCola * pc, unsigned tam)
{
    return (tam+sizeof(unsigned)) > pc->tamDisp;
}
int cola_vacia(const tCola * pc)
{
    return pc->tamDisp == TAM_COLA;
}

//void vaciar_cola(tCola * pc);
