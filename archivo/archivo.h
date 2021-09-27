#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    float promedio;

} t_estudiantes;

typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    double sueldo;

} t_empleados;

int cargarArchivoEstudiantes(char *nombre);
int cargarArchivoEmpleados(char *nombre);
int actualizarSueldo(FILE *est, FILE *emp);

#endif // ARCHIVO_H_INCLUDED
