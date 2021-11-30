#include<utilitarias.h>
#include<string.h>
#include<varias.h>

int alta (t_alumno * alu, FILE * arch, t_lista* pa)
{
    t_reg_ind reg_ind;
    int resp;

    reg_ind.dni = alu->dni;

    fseek(arch, 0L, SEEK_END);
    reg_ind.nro_reg = ftell(arch)/sizeof(t_alumno);
    ///insertar en el indice
    resp = instertar_lista_res(pa,&reg_ind, cmp_alumno);

    if(resp != TODO_OK){
        return resp;
    }

    ///insertar en archivo maestro
    fwrite(alu,sizeof(t_alumno),1,arch);

    return TODO_OK;
}


int baja (t_alumno * alu, FILE * arch, t_lista* pa)
{
    t_reg_ind reg_ind;
    int resp;

    ///eliminar del indice
    reg_ind.dni = alu->dni;

    resp = eliminar_lista_res(pa, &reg_ind, cmp_alumno);

    if(resp != TODO_OK){
        printf("resp: %d", resp);
        return resp;
    }

    ///darlo de baja en el archivo maestro
    ///estoy parado al principio del archivo maestro

    fseek(arch, reg_ind.nro_reg *sizeof(t_alumno), SEEK_SET);
    fread(alu, sizeof(t_alumno), 1, arch);
    alu->estado = 'B';
    fseek(arch, -(int)sizeof(t_alumno), SEEK_CUR);
    fwrite(alu, sizeof(t_alumno), 1, arch);

    return TODO_OK;
}


int cmp_alumno(const t_reg_ind *r1, const t_reg_ind *r2)
{
    return r1->dni - r2->dni;
}


void imprimir_archivo_ordenado(FILE * arch, t_lista* pa)
{
    recorrer_lista_res(pa, buscar_y_mostrar_alumno, arch);
}

void buscar_y_mostrar_alumno(t_reg_ind *reg_ind, void *arch)
{
    t_alumno alu;

    fseek(arch, reg_ind->nro_reg * sizeof(t_alumno), SEEK_SET);
    fread(&alu, sizeof(t_alumno), 1, arch);
    imprimir_alumno_res(&alu);
}
