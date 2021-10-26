#include <stdio.h>
#include <stdlib.h>
#include "piladinamica.h"


int main()
{
//    int elem;
//    int i, elint;
//   int elchar;
//    int el1= 1;
//    int el2 = 45;
//    tPila pila_mez;
//    crear_pila(&pila_mez);
//    poner_en_pila(&pila_mez,&el1,sizeof(el1));
//    poner_en_pila(&pila_mez,&el2,sizeof(el2));
//    sacar_de_pila(&pila_mez,&elchar,sizeof(elchar));
//    printf("\n%d",elchar);
//    sacar_de_pila(&pila_mez,&elint,sizeof(elint));
//    printf("\n %d",elint);
//    tPila pila_ent; /// === tNodo * pila_ent;
//    crear_pila(&pila_ent);
//    for(i=0; i<8; i++)
//    {
//        int r = poner_en_pila(&pila_ent, &i, sizeof(i));
//        if(!r)
//        {
//            printf("Pila llena!\n");
//        }
//    }
//    system("pause");
//    while(!pila_vacia(&pila_ent))
//    {
//        sacar_de_pila(&pila_ent, &elem, sizeof(elem));
//        printf("-%d", elem);
//    }
/*** Ejercicio que compara tope de pila con los elementos de la otra pila.
tPila pila_destino;
tPila pila_comp;
int tope = 4;
int vertope;
int comp;
crear_pila(&pila_destino);
poner_en_pila(&pila_destino, &tope, sizeof(tope));
crear_pila(&pila_comp);

for(int i=0; i<=10; i++)
{
    poner_en_pila(&pila_comp,&i, sizeof(i));
}


ver_tope(&pila_destino,&vertope, sizeof(vertope));
printf("EL tope de destino es %d\n", vertope);

while(!pila_vacia(&pila_comp))
{
    ver_tope(&pila_comp,&comp,sizeof(comp));

    if(comp > vertope)
    {
        sacar_de_pila(&pila_comp,&comp,sizeof(comp));
        printf("\n%d",comp);
    }
    else{
        sacar_de_pila(&pila_comp,&comp,sizeof(comp));
    }
}

**/
/*** cargar desde teclado pila1 y pasar a piladestino todos aquellos
elementos distintos a 8(ocho)***/

tPila pila1, pilaDestino;
int entero=0, sacent,sacdes, cont=0;
crear_pila(&pila1);
crear_pila(&pilaDestino);
while(entero !=1)
      {
          scanf("%d",&entero);
          printf("\n");
          poner_en_pila(&pila1,&entero,sizeof(entero));
          if(entero == 8)
            {
          sacar_de_pila(&pila1,&sacent,sizeof(sacent));
          poner_en_pila(&pilaDestino,&sacent,sizeof(sacent));
      }
      }
      while(!pila_vacia(&pilaDestino))
{
        cont++;
        sacar_de_pila(&pilaDestino,&sacdes,sizeof(sacdes));
        printf("\n%d\n sacamos: %d",sacdes,cont);
}

    return 0;
}
