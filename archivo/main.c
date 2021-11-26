#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"


int main()
{
    FILE * pf1, * pf2, *pfLv, *pfLf, *pfTab ;
//    t_empleados empleado;
    t_estudiantes estudiante;

    ///todo: validar se hayan cargado los arch
    // cargarArchivoEstudiantes("alu1.dat");
    // cargarArchivoEmpleados("alu2.dat");
    ///
//    pf1 = fopen("alu1.dat", "rb");
//    if (!pf1)
//    {
//        return 1;
//    }
//    pf2 = fopen("alu2.dat", "r+b");
//    if (!pf2)
//    {
//        fclose(pf1);
//        return 2;
//    }
//    pfLv = fopen("LV.txt", "rt");
//    if (!pfLv)
//    {
//        fclose(pfLv);
//        return 3;
//    }
    pfLf = fopen("LF.txt", "rt");
    if (!pfLf)
    {
        fclose(pfLf);
        return 4;
    }
    pfTab = fopen("estudiantes.dat", "w+b");
    if (!pfTab)
    {
        fclose(pfTab);
        return 5;
    }

//     fclose(pf1);
//      fclose(pf2);
//    crearArchivosTxt(pf1,pfLv,pfLf);
//    actualizarSueldo(pf1,pf2);

//    pf2 = fopen("alu2.dat", "rb");
//    if (!pf2)
//    {
//        return 1;
//    }

//while(leerEstudianteTxtLv(pfLv, &estudiante))
//{
//    printf("%d|%s|%s|%.2f\n", estudiante.dni,estudiante.apellido,estudiante.nombre,estudiante.promedio);
//}
    leerEstudianteTxtLf(pfLf, &estudiante);
        printf("%-6s%-6s%03d\n", estudiante.nroPed,estudiante.codProd,estudiante.cantPed);

         leerEstudianteTxtLf(pfLf, &estudiante);
        printf("%-6s%-6s%03d\n", estudiante.nroPed,estudiante.codProd,estudiante.cantPed);
        // fwrite(&estudiante,sizeof(t_estudiantes),1,pfTab);


//
//    fread(&empleado, sizeof(t_empleados), 1, pf2);
//    while (!feof(pf2))
//    {
//        printf("\ndni %d, ap %s, nom %s, sueldo %.2f ", empleado.dni,empleado.apellido,empleado.nombre,empleado.sueldo);
//        fread(&empleado, sizeof(t_empleados), 1, pf2);
//    }
//    fclose(pfTab);
//    pfTab = fopen("estudiantes.dat", "rb");
//    if (!pfTab)
//    {
//        fclose(pfTab);
//        return 5;
//    }
//    fread(&estudiante, sizeof(t_estudiantes), 1, pfTab);
//    while (!feof(pfTab))
//    {
//        printf("\ndni %d ap %s nom %s promedio%.2f ", estudiante.dni,estudiante.apellido,estudiante.nombre,estudiante.promedio);
//        fread(&estudiante, sizeof(t_estudiantes), 1, pfTab);
//    }
//    fclose(pf2);
    fclose(pf1);
    fclose(pfLv);
    fclose(pfLf);
    fclose(pfTab);
    return 0;
}
