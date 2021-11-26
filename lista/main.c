#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
}tPersona;
typedef struct
{
    char codigo[10];
    unsigned stock;
    float precioUnitario;
}tProducto;
int cmp_ent(const void * v1, const void *v2);
int cmp_pers_dni(const void * v1, const void *v2);
int cmp_pers_apyn(const void * v1, const void *v2);
void mostrarEntero(void * vEnt, void * pf);
void guardarEntero(void * vEnt, void * pf);
void mostrarPersona(void * vPer, void * pf);
void probarEliminarDuplicados();
void probarPersonas();
int main()
{
    probarPersonas();
    //probarEliminarDuplicados();
}
void probarPersonas()
{
    FILE * pf;
    tLista lista_ent, lista_per;
    int vec[] = {2,8,4,6,5,9,7,4,1,3},
        i,
        dato;
    tPersona vPer[]= {  {2, "Persona 5", 'X'},
                        {8, "Persona 7", 'X'},
                        {4, "Persona 3", 'X'},
                        {6, "Persona 8", 'X'},
                        {5, "Persona 1", 'X'},
                        {9, "Persona 10", 'X'},
                        {7, "Persona 2", 'X'},
                        {4, "Persona 4", 'X'},
                        {1, "Persona 9", 'X'},
                        {3, "Persona 6", 'X'}};
    crear_lista(&lista_ent);
    for(i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        poner_orden_lista(&lista_ent, vec+i, sizeof(int), cmp_ent);
        //poner_primero_lista(&lista_ent, vec+i,sizeof(int));
        printf("\n\n");
        mostrar_lista(&lista_ent);
    }
    printf("\n\n*****************\n");
    dato = 54;
    poner_pos_lista(&lista_ent, &dato, sizeof(int), 9);
    mostrar_lista(&lista_ent);
    printf("\n\n*****************");
    FILE * arch = fopen("arch.txt", "wt");
    if (!arch)
        return;
    for(i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        sacar_elem_ord_lista(&lista_ent, vec+i, sizeof(int), cmp_ent);
        fprintf(arch, "\n\n");
        printf("\n\n");
        //mostrar_lista(&lista_ent);
        recorrerLista(&lista_ent, mostrarEntero, NULL);
        recorrerLista(&lista_ent, guardarEntero, arch);
    }
    fclose(arch);
    crear_lista(&lista_per);
    printf("\n\n*****Prueba Ordenar Seleccion**********\n\n");
    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++)
    {
        //poner_orden_lista(&lista_per, vPer+i, sizeof(tPersona), cmp_pers_dni);
        poner_ultimo_lista(&lista_per, vPer+i, sizeof(tPersona));
    }
    ordenar_sel_lista(&lista_per, cmp_pers_apyn);
    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++)
    {
        tPersona p1;
        p1.dni = vPer[i].dni;
        strcpy(p1.apyn, "xxxxxxx");
        sacar_primero_lista(&lista_per, &p1, sizeof(tPersona));
        printf("\n");
        printf("  -%d %s", p1.dni, p1.apyn);
    }
    printf("\n\n*****Prueba insertar ordenado**********\n\n");
    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++)
    {
        poner_orden_lista(&lista_per, vPer+i, sizeof(tPersona), cmp_pers_dni);
    }
    if (!(pf=fopen("pers.txt", "wt")))
    {
        exit(1);
    }
    printf("\n\n*****************\n");
    recorrerLista(&lista_per, mostrarPersona, pf);
    printf("\n\n*****************\n");
    fclose(pf);
    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++)
    {
        tPersona p1;
        p1.dni = vPer[i].dni;
        strcpy(p1.apyn, "xxxxxxx");
        sacar_elem_ord_lista(&lista_per, &p1, sizeof(tPersona), cmp_pers_dni);
        printf("\n");
        printf("  -%d %s", p1.dni, p1.apyn);
    }
}
int cmp_ent(const void * v1, const void *v2)
{
    int * e1 = (int *) v1,
        * e2 = (int *) v2;
    return *e1-*e2;
}
int cmp_pers_dni(const void * v1, const void *v2)
{
    tPersona * p1 = (tPersona*) v1,
             * p2 = (tPersona*) v2;
    return p1->dni-p2->dni;
}
int cmp_pers_apyn(const void * v1, const void *v2)
{
    tPersona * p1 = (tPersona*) v1,
             * p2 = (tPersona*) v2;
    return strcmpi(p1->apyn,p2->apyn);
}
void mostrarEntero(void * vEnt, void * pf)
{
    ///printf("*%d*", *((int*)vEnt));
    int * ent = (int*)vEnt;
    printf("*%d*", *ent);
}
void guardarEntero(void * vEnt, void * pf)
{
    ///printf("*%d*", *((int*)vEnt));
    int * ent = (int*)vEnt;
    fprintf((FILE*)pf, "*%d*", *ent);
}
void mostrarPersona(void * vPer, void * param)
{
    tPersona * per = (tPersona*) vPer;
    FILE * pf = (FILE*) param;
    fprintf(pf, "\n  -%d %s", per->dni, per->apyn);
}
void mostrarProducto(void * vProd, void * param)
{
    tProducto * prod = (tProducto*) vProd;
    FILE * pf = (FILE*) param;
    fprintf(pf, "\n  -%s %d $%.2f", prod->codigo, prod->stock, prod->precioUnitario);
}
int cmpProductoCod(const void * v1, const void *v2)
{
    tProducto * p1 = (tProducto*) v1,
              * p2 = (tProducto*) v2;
    return strcmpi(p1->codigo,p2->codigo);
}
void acumularStockProducto(void * v1, const void *v2)
{
    tProducto * p1 = (tProducto*) v1;
    const tProducto * p2 = (const tProducto*) v2;
    p1->stock += p2->stock;
    p1->precioUnitario = p1->precioUnitario<p2->precioUnitario?p2->precioUnitario:p1->precioUnitario;
}
void probarEliminarDuplicados()
{
    tProducto productos[] ={
        { "DESTOR", 5, 20.5},
        { "ESPA", 22, 55.5},
        { "ESPA", 11, 55.5},
        { "ESPA", 3, 55.5},
        { "MART", 20, 50.2},
        { "MART", 30, 52.2},
        { "PALA", 5, 200.2},
        { "PICO", 2, 150.7},
        { "PICO", 2, 150.7},
        { "PICO", 2, 150.7},
        { "PICO", 2, 150.7},
        { "PICO", 2, 150.7},
        { "PINC", 2, 77.8},
        { "RODI", 100, 20.8},
        { "RODI", 2, 20.8},
        { "SERRU", 10, 29.9},
        { "SERRU", 11, 29.9},
        { "SERRU", 12, 29.9},
        { "SIERRA", 2, 15.5},
        { "SIERRA", 8, 15.5}
    };
    tLista lProd;
    int ce = sizeof(productos)/sizeof(tProducto);
    int i;
    crear_lista(&lProd);
    for(i=0;i<ce;i++)
    {
        poner_primero_lista(&lProd, &productos[ce-1-i], sizeof(tProducto));
    }
    printf("Lista de productos con duplicados: \n\n");
    recorrerLista(&lProd, mostrarProducto, stdout);
    eliminarDuplicadosListaOrdenada(&lProd, cmpProductoCod, acumularStockProducto);
    printf("\n\nLista de productos sin duplicados: \n\n");
    recorrerLista(&lProd, mostrarProducto, stdout);
}
