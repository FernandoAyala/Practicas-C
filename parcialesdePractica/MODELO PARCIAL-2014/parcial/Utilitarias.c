#include <stdio.h>
#include <string.h>
#include "Tipos.h"
#include "Cola.h"
#include "Utilitarias.h"


void generar_archivo_productos()
{
    t_mat_prima_art mat_prima_art;
    FILE* arch_prod = fopen("Archivos/Productos.dat", "wb");


    ///630
    strcpy(mat_prima_art.cod_art, "HAMBUR");
    strcpy(mat_prima_art.cod_mat_pri, "CARNE");
    mat_prima_art.cantidad = 9;
    mat_prima_art.costo_unit = 70;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///2000
    strcpy(mat_prima_art.cod_art, "HAMBUR");
    strcpy(mat_prima_art.cod_mat_pri, "GRASA");
    mat_prima_art.cantidad = 25;
    mat_prima_art.costo_unit = 80;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///120
    strcpy(mat_prima_art.cod_art, "HAMBUR");
    strcpy(mat_prima_art.cod_mat_pri, "CONDIM");
    mat_prima_art.cantidad = 6;
    mat_prima_art.costo_unit = 20;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///150
    strcpy(mat_prima_art.cod_art, "HAMBUR");
    strcpy(mat_prima_art.cod_mat_pri, "SOJA");
    mat_prima_art.cantidad = 10;
    mat_prima_art.costo_unit = 15;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
    ///Total: 2270


    ///560
    strcpy(mat_prima_art.cod_art, "MILANG");
    strcpy(mat_prima_art.cod_mat_pri, "CARNE");
    mat_prima_art.cantidad = 8;
    mat_prima_art.costo_unit = 70;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///160
    strcpy(mat_prima_art.cod_art, "MILANG");
    strcpy(mat_prima_art.cod_mat_pri, "GRASA");
    mat_prima_art.cantidad = 2;
    mat_prima_art.costo_unit = 80;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///80
    strcpy(mat_prima_art.cod_art, "MILANG");
    strcpy(mat_prima_art.cod_mat_pri, "CONDIM");
    mat_prima_art.cantidad = 4;
    mat_prima_art.costo_unit = 20;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///150
    strcpy(mat_prima_art.cod_art, "MILANG");
    strcpy(mat_prima_art.cod_mat_pri, "REBOSA");
    mat_prima_art.cantidad = 5;
    mat_prima_art.costo_unit = 30;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
    ///Total: 950


    ///480
    strcpy(mat_prima_art.cod_art, "PANVIE");
    strcpy(mat_prima_art.cod_mat_pri, "HARINA");
    mat_prima_art.cantidad = 12;
    mat_prima_art.costo_unit = 40;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///60
    strcpy(mat_prima_art.cod_art, "PANVIE");
    strcpy(mat_prima_art.cod_mat_pri, "CONDIM");
    mat_prima_art.cantidad = 3;
    mat_prima_art.costo_unit = 20;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///240
    strcpy(mat_prima_art.cod_art, "PANVIE");
    strcpy(mat_prima_art.cod_mat_pri, "GRASA");
    mat_prima_art.cantidad = 3;
    mat_prima_art.costo_unit = 80;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
    ///Total: 780


    ///700
    strcpy(mat_prima_art.cod_art, "VIENA");
    strcpy(mat_prima_art.cod_mat_pri, "CARNE");
    mat_prima_art.cantidad = 10;
    mat_prima_art.costo_unit = 70;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///1600
    strcpy(mat_prima_art.cod_art, "VIENA");
    strcpy(mat_prima_art.cod_mat_pri, "GRASA");
    mat_prima_art.cantidad = 20;
    mat_prima_art.costo_unit = 80;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);

    ///140
    strcpy(mat_prima_art.cod_art, "VIENA");
    strcpy(mat_prima_art.cod_mat_pri, "CONDIM");
    mat_prima_art.cantidad = 7;
    mat_prima_art.costo_unit = 20;
    fwrite(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
    ///Total: 2440


    fclose(arch_prod);
}



void procesar_arch_productos(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000)
{
    t_mat_prima_art mat_prima_art, mat_prima_ant, mat_prima_cola;
    float costo_prod;
    t_cola cola;
    FILE *arch_a_grabar;

    crear_cola(&cola);

    fread(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
    while(!feof(arch_prod)){
        costo_prod = 0;
        mat_prima_ant = mat_prima_art;
        while( !feof(arch_prod) && !strcmp(mat_prima_ant.cod_art, mat_prima_art.cod_art) ){
            costo_prod += mat_prima_art.cantidad * mat_prima_art.costo_unit;
            poner_en_cola(&cola, &mat_prima_art);
            fread(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
        }

        arch_a_grabar = costo_prod > 1000 ? arch_prod_mas_1000 : arch_prod_menos_1000;

        while(!cola_vacia(&cola)){
            sacar_de_cola(&cola, &mat_prima_cola);
            fwrite(&mat_prima_cola, sizeof(t_mat_prima_art), 1, arch_a_grabar);
        }
    }
}




int mi_strcmp(const char *s1, const char *s2)
{
    int cmp;
    while(*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    cmp = *s1 - *s2;
    return cmp;
}


void procesar_arch_productos2(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000)
{
    t_mat_prima_art mat_pri, mat_pri_ant, mat_pri_cola;
    int costoprod =0;
    t_cola colaprod;
    crear_cola(&colaprod);

    fread(&mat_pri, sizeof(t_mat_prima_art),1,arch_prod);
    while(!feof(arch_prod))
    {
        mat_pri_ant = mat_pri;
        while(!feof(arch_prod) && !mi_strcmp(mat_pri.cod_art,mat_pri_ant.cod_art))
        {
            costoprod+= mat_pri.cantidad*mat_pri.costo_unit;
            poner_en_cola(&colaprod,&mat_pri);
            fread(&mat_pri, sizeof(t_mat_prima_art),1,arch_prod);
        }

        while(!cola_vacia(&colaprod))
        {
            if(costoprod > 1000)
            {
                sacar_de_cola(&colaprod,&mat_pri_cola);
                fwrite(&mat_pri_cola,sizeof(t_mat_prima_art),1,arch_prod_mas_1000);
            }
            else
            {
                sacar_de_cola(&colaprod,&mat_pri_cola);
                fwrite(&mat_pri_cola,sizeof(t_mat_prima_art),1,arch_prod_menos_1000);
            }
        }
        costoprod=0;
    }
}


void mostrar_archivo_prod(FILE* arch_prod)
{
    t_mat_prima_art mat_prima_art;

    fread(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
    while(!feof(arch_prod))
    {
        mostrar_mat_prima_art(&mat_prima_art);
        fread(&mat_prima_art, sizeof(t_mat_prima_art), 1, arch_prod);
    }
}



void mostrar_mat_prima_art(t_mat_prima_art* pmat_prima_art)
{
    printf("%s - %s - %d - %f\n", pmat_prima_art->cod_art, pmat_prima_art->cod_mat_pri, pmat_prima_art->cantidad, pmat_prima_art->costo_unit);
}
