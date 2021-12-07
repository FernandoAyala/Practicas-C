#include<utilitarias.h>
#include<string.h>
#include<varias.h>

///int(*cmp)(const void *, const void *);
///cmp(d, (*p)->info);
int cmp_alu_dni(const void * v1, const void * v2)
{
    tRegInd * a1 = (tRegInd*)v1;
    tRegInd * a2 = (tRegInd*)v2;
    return a1->dni - a2->dni;
}

///res= alta(&alu, arch, pindice);
int alta (tAlumno * alu, FILE * arch, tArbolBinBusq* pa)
{
    tRegInd reg_ind;
    int resp;

    reg_ind.dni = alu->dni;

    fseek(arch, 0L, SEEK_END);

    reg_ind.nro_reg = ftell(arch) / sizeof(tAlumno);

    resp = insertarArbolBinBusq(pa, &reg_ind, sizeof(tRegInd), cmp_alu_dni);

    if(resp != TODO_OK)
        return resp;

    fwrite(alu, sizeof(tAlumno), 1, arch);

    return TODO_OK;
}


/// res= baja(&alu, arch, pindice);
int baja (tAlumno * alu, FILE * arch, tArbolBinBusq* pa)
{
    tRegInd reg_ind;
    int resp;

    reg_ind.dni = alu->dni;

    resp = eliminarElemArbolBinBusq(pa, &reg_ind, sizeof(tRegInd), cmp_alu_dni);
    if(resp != TODO_OK)
        return resp;

    fseek(arch, reg_ind.nro_reg * sizeof(tAlumno), SEEK_SET);

    fread(alu, sizeof(tAlumno), 1, arch);

    alu->estado = 'B';

    fseek(arch, -(long)sizeof(tAlumno), SEEK_CUR);

    fwrite(alu, sizeof(tAlumno), 1, arch);

    return TODO_OK;
}


void imprimirAlumno(tAlumno * alu)
{
    printf("\n\nDNI: %d\nApellido y nombre: %s\nMaterias: %d    Promedio: %.2f\nEstado: %c",
           alu->dni, alu->apyn, alu->cant_materias, alu->promedio, alu->estado);
}


///accion((*p)->info, (*p)->tamInfo, n, params);
///void (*accion)(void *, unsigned, unsigned, void *)) - params: arch
void buscar_y_mostrar_alumno(void * info, unsigned tamInfo, unsigned n, void * params)
{
    tRegInd * reg_ind = (tRegInd *)info;
    FILE * arch = (FILE *)params;
    tAlumno alu;

    fseek(arch, reg_ind->nro_reg * sizeof(tAlumno), SEEK_SET);
    fread(&alu, sizeof(tAlumno), 1, arch);
    imprimirAlumno(&alu);
}


/// imprimirArchivoOrdenado(arch, pindice);
void imprimir_archivo_ordenado(FILE * arch, tArbolBinBusq* pa)
{
    recorrerEnOrdenArbolBinBusq(pa, arch, buscar_y_mostrar_alumno);
}

