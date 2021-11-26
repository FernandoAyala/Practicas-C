#include "archivo.h"

int cargarArchivoEstudiantes(char *nombre)
{
    t_estudiantes estudiantes[] =
    {
        {"12345", "0001a", 10},
        {"54321", "0001a", 40},
        {"11122", "0001b", 20},
        {"22233", "0001c", 30},
        {"33322", "0002a", 100},
        {"00011", "0004a", 35},
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

//int actualizarSueldo(FILE *est, FILE *emp)
//{
//    t_estudiantes estudiante;
//    t_empleados empleado;
//
//    fread(&estudiante, sizeof(t_estudiantes), 1, est);
//    fread(&empleado, sizeof(t_empleados), 1, emp);
//    while(!feof(est)&&!feof(emp))
//    {
//        if(estudiante.dni == empleado.dni)
//        {
//            if(estudiante.promedio >= 7)
//            {
//                empleado.sueldo*=1.0728;
//                fseek(emp,(long)-sizeof(t_empleados),SEEK_CUR);
//                fwrite(&empleado,sizeof(t_empleados),1,emp);
//                fseek(emp,0,SEEK_CUR);
//                fread(&estudiante,sizeof(t_estudiantes),1,est);
//
//            }
//        }
//        else
//        {
//            fread(&empleado,sizeof(t_empleados),1,emp);
//            fread(&estudiante,sizeof(t_estudiantes),1,est);
//        }
//    }
//    fclose(est);
//    fclose(emp);
//    return 1;
//}

void crearArchivosTxt(FILE *fpbin,FILE *fplv,FILE *fplf)
{
    t_estudiantes tAux;
    rewind(fpbin);
    fread(&tAux,sizeof(t_estudiantes),1,fpbin);
    while(!feof(fpbin))
    {
        /**LV**/
        fprintf(fplv,"%s|%s|%d\n",tAux.nroPed,tAux.codProd,tAux.cantPed);
        /**LF**/
        fprintf(fplf,"%-5s%-5s%03d\n",tAux.nroPed,tAux.codProd,tAux.cantPed);
        fread(&tAux,sizeof(t_estudiantes),1,fpbin);
    }
}
//
//int leerEstudianteTxtLv(FILE *pf, t_estudiantes *est )
//{
//    return fscanf(pf,"%d|%[^|\n]|%[^|\n]|%f\n",&est->dni,est->apellido,est->nombre,&est->promedio) ==4;
//}
//
//int leerEstudianteTxtLf(FILE *pf, t_estudiantes *est )
//{
//    return fscanf(pf,"%010d%29[^\n]%29[^\n]%010f\n",&est->dni,est->apellido,est->nombre,&est->promedio) ==4;
//}

int leerEstudianteTxtLf(FILE *pf, t_estudiantes *est )
{
    return fscanf(pf,"%5[^\n]%5[^\n]%03d\n",est->nroPed,est->codProd,&est->cantPed) ==3;
}
