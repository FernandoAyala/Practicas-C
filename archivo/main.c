#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"


int main()
{
    FILE * pf1, * pf2, *pfLv, *pfLf ;
//    t_empleados empleado;
    t_estudiantes estudiante;

    ///todo: validar se hayan cargado los arch
    cargarArchivoEstudiantes("alu1.dat");
    cargarArchivoEmpleados("alu2.dat");
    ///
    pf1 = fopen("alu1.dat", "rb");
    if (!pf1)
    {
        return 1;
    }
//    pf2 = fopen("alu2.dat", "r+b");
//    if (!pf2)
//    {
//        fclose(pf1);
//        return 2;
//    }
    pfLv = fopen("LV.txt", "rt");
    if (!pfLv)
    {
        fclose(pfLv);
        return 3;
    }
    pfLf = fopen("LF.txt", "rt");
    if (!pfLf)
    {
        fclose(pfLf);
        return 4;
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
while(leerEstudianteTxtLf(pfLf, &estudiante))
{
    printf("%010d%-30s%-30s%010.2f\n", estudiante.dni,estudiante.apellido,estudiante.nombre,estudiante.promedio);
}


//
//    fread(&empleado, sizeof(t_empleados), 1, pf2);
//    while (!feof(pf2))
//    {
//        printf("\ndni %d, ap %s, nom %s, sueldo %.2f ", empleado.dni,empleado.apellido,empleado.nombre,empleado.sueldo);
//        fread(&empleado, sizeof(t_empleados), 1, pf2);
//    }
//    fclose(pf2);
    fclose(pf1);
    fclose(pfLv);
    fclose(pfLf);
    return 0;
}
