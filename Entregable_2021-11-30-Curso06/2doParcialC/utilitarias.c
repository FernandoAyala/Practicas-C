#include<utilitarias.h>
#include<string.h>
#include<varias.h>

int baja (tAlumno * alu, FILE * arch, tArbolBinBusq* pa)
{

    tRegInd regInd;

    regInd.dni = alu->dni;

 if(eliminarElemArbolBinBusq_res(pa, &regInd, sizeof(tRegInd), compDni) !=1)
    {
        printf("No existe");
        return 0;
    }
    fseek(arch, regInd.nro_reg * sizeof(tAlumno), SEEK_SET );
    fread(alu ,sizeof(tAlumno),1,arch);
          alu->estado = 'B';
          fseek(arch, -(int)sizeof(tAlumno),SEEK_CUR);
          fwrite(alu,sizeof(tAlumno),1,arch);
          return 1;
}

int baja_ultimo (FILE * arch, tArbolBinBusq* pa)
{
    tAlumno alu;
    tRegInd registro;
    if(mayorElemNoClaveArbolBinBusq_res(pa,&registro,sizeof(tRegInd),cmpRegistro)!=TODO_OK)
        return NO_EXISTE;

    eliminarElemArbolBinBusq_res(pa,&registro,sizeof(tRegInd),compDni);
    fseek(arch,registro.nro_reg*sizeof(tAlumno),SEEK_SET);
    fread(&alu,sizeof(tAlumno),1,arch);
    alu.estado='B';
    fseek(arch,(-1)*registro.nro_reg*sizeof(tAlumno),SEEK_CUR);
    fwrite(&alu,sizeof(tAlumno),1,arch);
    printf("\n Eliminado : \n DNI: %d \n ApyN: %s \n Cant Materias : %d \n Promedio: %.2f \n Estado: %c \n",alu.dni,alu.apyn,alu.cant_materias,alu.promedio,alu.estado);
    return 1;
}

int alta (tAlumno * alu, FILE * arch, tArbolBinBusq* pa)
{
    tRegInd registro;
    int res;
    fseek(arch,0L,SEEK_END);
    registro.dni=alu->dni;
    registro.nro_reg=ftell(arch)/sizeof(tAlumno);
    res=insertarRecArbolBinBusq(pa,&registro,sizeof(tRegInd),compDni);
    if(res!=TODO_OK)
        return res;
    fwrite(alu,sizeof(tAlumno),1,arch);
    return res;

}

int compactarYReindexar(FILE ** arch, tArbolBinBusq * pindice, const char * path)
{
    ///recibe &arch, &indice, PATH_ARCH_ALUMNOS
    FILE *pf;
    tAlumno alumno;
    tRegInd dato;
    int nroReg=0;
    fclose(*arch);
    rename(path,"../archivos/alumnos_old.dat");
    *arch=fopen(path,"w+b");
    pf=fopen("../archivos/alumnos_old.dat","rb");
    if(!arch||!pf)
        return ERROR_ARCHIVO;
    vaciarArbolBin_res(pindice);
    fread(&alumno,sizeof(tAlumno),1,pf);
    while(!feof(pf))
    {
        if(alumno.estado=='A')
        {
            fwrite(&alumno,sizeof(tAlumno),1,*arch);
            dato.dni=alumno.dni;
            dato.nro_reg=nroReg;
            insertarRecArbolBinBusq(pindice,&dato,sizeof(tRegInd),compDni);
        }
        nroReg++;
        fread(&alumno,sizeof(tAlumno),1,pf);
    }
    fclose(pf);
    remove("../archivos/alumnos_old.dat");
    return TODO_OK;
}



int compDni(const void *al1, const void *al2)
{
    tRegInd *c1 = (tRegInd*)al1;
    tRegInd *c2 = (tRegInd*)al2;
    return c1->dni - c2->dni;
}

int cmpRegistro(const void* reg1, const void* reg2)
{
    tRegInd *r1=(tRegInd*)reg1;
    tRegInd *r2=(tRegInd*)reg2;
    return r1->nro_reg-r2->nro_reg;
}
