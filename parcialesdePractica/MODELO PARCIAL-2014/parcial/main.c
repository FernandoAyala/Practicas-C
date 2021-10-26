#include <stdio.h>
#include <stdlib.h>
#include "Tipos.h"
#include "Cola.h"
#include "Utilitarias.h"

int main()
{
    ///abrir o crear archivos
    FILE *arch_prod = fopen("../Archivos/Productos.dat","rb");
    FILE *arch_prod_mas_1000 = fopen("../Archivos/ProductosMas1000.dat","wb");
    FILE *arch_prod_menos_1000 = fopen("../Archivos/ProductosMenos1000.dat","wb");

    if( !arch_prod || !arch_prod_mas_1000 || !arch_prod_menos_1000 ){
        printf("Error de archivos");
        return 0;
    }

    printf("Archivo Productos\n");
    mostrar_archivo_prod(arch_prod);
    fseek(arch_prod, 0L, 0);

    ///proceso el archivo maestro
    procesar_arch_productos(arch_prod, arch_prod_mas_1000, arch_prod_menos_1000);

    fclose(arch_prod);
    fclose(arch_prod_mas_1000);
    fclose(arch_prod_menos_1000);

    ///muestro
    arch_prod_mas_1000 = fopen("../Archivos/ProductosMas1000.dat","rb");
    arch_prod_menos_1000 = fopen("../Archivos/ProductosMenos1000.dat","rb");

    if( !arch_prod_mas_1000 || !arch_prod_menos_1000 ){
        printf("Error lectura de archivos");
        return 0;
    }

    printf("Archivo Productos con costo mayor a 1000\n");
    mostrar_archivo_prod(arch_prod_mas_1000);

    printf("Archivo Productos con costo menor a 1000\n");
    mostrar_archivo_prod(arch_prod_menos_1000);

    fclose(arch_prod_mas_1000);
    fclose(arch_prod_menos_1000);

    return 0;
}
