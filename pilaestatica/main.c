#include <stdio.h>
#include <stdlib.h>
#include "pilaestatica.h"

int main()
{
    int elem =1;
    int i;
    tPila pila_ent; /// === tNodo * pila_ent;
    crear_pila(&pila_ent);
    for(i=0; i<8;i++)
    {
        int r = poner_en_pila(&pila_ent, &i, sizeof(i));
        if(!r)
        {
            printf("Pila llena!\n");
        }
    }
    system("pause");
    while(!pila_vacia(&pila_ent))
    {
        sacar_de_pila(&pila_ent, &elem, sizeof(elem));
        printf("-%d", elem);
    }
    return 0;
}
