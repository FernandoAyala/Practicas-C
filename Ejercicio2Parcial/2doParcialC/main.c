#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <lista.h>

#define PATH_ARCH_ALUMNOS "../archivos/alumnos.dat"
#define PATH_ARCH_INDICE "../archivos/alumnos.idx"

void imprimir_mensaje(int res);
void op_alta(FILE * arch, t_lista * pindice);
void op_baja(FILE * arch, t_lista * pindice);
void op_listar_indice(t_lista * pindice);
void op_listar_alumnos(FILE * arch);
void op_listar_alumnos_ordenado(FILE * arch, t_lista * pindice);
void op_compactar_y_reindexar(FILE ** arch, t_lista * pindice, const char * path);

int main()
{
    FILE * arch;
    const char opciones [][TAM_MENU] = {"ABILMCS",
                                        "Alta",
                                        "Baja",
                                        "Listar Indice",
                                        "Listar Alumnos",
                                        "Listar Alumnos Ordenado por DNI",
                                        "Compactar Archivo y Reindexar",
                                        "Salir"};
    char op;
    t_lista indice;

    ///Descomente esta linea para restaurar las pruebas
    ///restaurar_prueba_res(PATH_ARCH_ALUMNOS, PATH_ARCH_INDICE);

    arch = fopen(PATH_ARCH_ALUMNOS, "r+b");
    if (!arch)
        exit(1);

    crear_lista_res(&indice);

    if(cargar_lista_de_archivo_ordenado_res(&indice, PATH_ARCH_INDICE)==ERROR_ARCHIVO)
        exit(1);
    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                op_alta(arch, &indice);
                break;
            case 'B':
                op_baja(arch, &indice);
                break;
            case 'I':
                op_listar_indice(&indice);
                break;
            case 'L':
                op_listar_alumnos(arch);
                break;
            case 'M':
                op_listar_alumnos_ordenado(arch, &indice);
                break;
            case 'C':
                op_compactar_y_reindexar(&arch, &indice, PATH_ARCH_ALUMNOS);
                break;
        }
    }while(op!='S');

    grabar_lista_en_archivo_ordenado_res(&indice, PATH_ARCH_INDICE);

    vaciar_lista_res(&indice);
    fclose(arch);
    return 0;
}

void op_alta(FILE * arch, t_lista * pindice)
{
    int res;
    t_alumno alu;
    ingresar_alumno_res(&alu);
    //res= alta_res(&alu, arch, pindice);
    res= alta(&alu, arch, pindice);
    imprimir_mensaje(res);
}

void op_baja(FILE * arch, t_lista * pindice)
{
    int res;
    t_alumno alu;
    ingresar_dni_alumno_res(&alu);
    //res= baja_res(&alu, arch, pindice);
    res= baja(&alu, arch, pindice);
    imprimir_mensaje(res);
}


void op_listar_indice(t_lista * pindice)
{
    printf("\n\n");

    while(*pindice)
    {
        printf("\n\nDNI: %d\nNro reg: %d", (*pindice)->info.dni, (*pindice)->info.nro_reg);
        pindice = &(*pindice)->psig;
    }

    pausa("\n\n");
}

void op_listar_alumnos(FILE * arch)
{
    printf("\n\n");
    imprimir_archivo_res(arch);
    pausa("\n\n");
}

void op_listar_alumnos_ordenado(FILE * arch, t_lista * pindice)
{
    printf("\n\n");
    //imprimir_archivo_ordenado_res(arch, pindice);
    imprimir_archivo_ordenado(arch, pindice);
    pausa("\n\n");
}

void op_compactar_y_reindexar(FILE ** arch, t_lista * pindice, const char * path)
{
    int res;
    res= compactar_y_reindexar_res(arch, pindice, path);
    imprimir_mensaje(res);
}

void imprimir_mensaje(int res)
{
    switch(res)
    {
        case TODO_OK: pausa("Operacion realizada correctamente.");
                break;
        case SIN_MEM: pausa("Error de memoria.");
                break;
        case ERROR_ARCHIVO: pausa("Error en el archivo.");
                break;
        case DUPLICADO: pausa("Resgistro duplicado.");
                break;
        case NO_EXISTE: pausa("Resgistro inexistente.");
                break;
    }
}
