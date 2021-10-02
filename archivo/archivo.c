#include "archivo.h"

int cargarArchivoEstudiantes(char *nombre)
{
    t_estudiantes estudiantes[] =
    {
        {110, "Alumno 1", "Aa", 8},
        {120, "Alumno 2", "Ab", 4},
        {130, "Alumno 3", "Ac", 8},
        {140, "Alumno 4", "Ad", 7.5},
        {150, "Alumno 5", "Ah", 4},
        {900, "Alumno 6", "Ba", 8.5},
        {980, "Alumno 7", "Bc", 8},
    };

    FILE * pf = fopen(nombre,"wb");
    if(!pf)
    {
        return 0;
    }
    fwrite(estudiantes,sizeof(estudiantes),1,pf);
    fclose(pf);
    return 1;
}

int cargarArchivoEmpleados(char *nombre)
{
    t_empleados empleados[] =
    {
        {110, "Alumno 1", "Aa", 15200},
        {120, "Alumno 2", "Ab", 55},
        {130, "Alumno 3", "Ac", 100},
        {140, "Alumno 4", "Ad", 1000},
        {150, "Alumno 5", "Ah", 1000},
        {900, "Alumno 6", "Ba", 10000},
        {980, "Alumno 7", "Bc", 100000},
    };

    FILE * pf = fopen(nombre,"wb");
    if(!pf)
    {
        return 0;
    }
    fwrite(empleados,sizeof(empleados),1,pf);
    fclose(pf);
    return 1;
}

int actualizarSueldo(FILE *est, FILE *emp)
{
    t_estudiantes estudiante;
    t_empleados empleado;

    fread(&estudiante, sizeof(t_estudiantes), 1, est);
    fread(&empleado, sizeof(t_empleados), 1, emp);
    while(!feof(est)&&!feof(emp))
    {
        if(estudiante.dni == empleado.dni)
        {
            if(estudiante.promedio >= 7)
            {
                empleado.sueldo*=1.0728;
                fseek(emp,(long)-sizeof(t_empleados),SEEK_CUR);
                fwrite(&empleado,sizeof(t_empleados),1,emp);
                fseek(emp,0,SEEK_CUR);
            }
        }
        else
        {
            fread(&empleado,sizeof(t_empleados),1,emp);
            fread(&estudiante,sizeof(t_estudiantes),1,est);
        }
        fread(&empleado,sizeof(t_empleados),1,emp);
        fread(&estudiante,sizeof(t_estudiantes),1,est);
    }
    fclose(est);
    fclose(emp);
    return 1;
}

void crearArchivosTxt(FILE *fpbin,FILE *fplv,FILE *fplf)
{
    t_estudiantes tAux;
    rewind(fpbin);
    fread(&tAux,sizeof(t_estudiantes),1,fpbin);
    while(!feof(fpbin))
    {
        /**LV**/
        fprintf(fplv,"%d|%s|%s|%.2f\n",tAux.dni,tAux.apellido,tAux.nombre,tAux.promedio);
        /**LF**/
        fprintf(fplf,"%010d%-29s%-29s%010.2f\n",tAux.dni,tAux.apellido,tAux.nombre,tAux.promedio);
        fread(&tAux,sizeof(t_estudiantes),1,fpbin);
    }
}

int leerEstudianteTxtLv(FILE *pf, t_estudiantes *est )
{
    return fscanf(pf,"%d|%[^|\n]|%[^|\n]|%f\n",&est->dni,est->apellido,est->nombre,&est->promedio) ==4;
}

int leerEstudianteTxtLf(FILE *pf, t_estudiantes *est )
{
    return fscanf(pf,"%010d%29[^\n]%29[^\n]%010f\n",&est->dni,est->apellido,est->nombre,&est->promedio) ==4;
}
