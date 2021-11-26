#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//typedef struct
//{
//    int dni;
//    char apellido[30];
//    char nombre[30];
//    float promedio;
//
//} t_estudiantes;

typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    double sueldo;

} t_empleados;

typedef struct
{
	char nroPed[6];
	char codProd[6];
	int cantPed;
}t_estudiantes;


int cargarArchivoEstudiantes(char *nombre);
int cargarArchivoEmpleados(char *nombre);
int actualizarSueldo(FILE *est, FILE *emp);
void crearArchivosTxt(FILE * fpbin, FILE *fpLF, FILE *fpLV);
int leerEstudianteTxtLv(FILE *pf, t_estudiantes *est );
int leerEstudianteTxtLf(FILE *pf, t_estudiantes *est );
#endif // ARCHIVO_H_INCLUDED
