#include<banco.h>
#include<lista.h>
#include<utilitarias.h>
#include<string.h>
#include<stdlib.h>

void actualizar_cuentas(FILE * arch_ctas, FILE * arch_movs, FILE * arch_err, t_lista *plista)
{
    t_movimiento_banco movimiento;
    t_cuenta_banco cuenta;
    char linea[TAM_LINEA];

    while(fgets(linea, sizeof(linea), arch_movs))
    {
        texto_a_movimiento(linea,&movimiento);
        rewind(arch_ctas);
        fread(&cuenta, sizeof(t_cuenta_banco), 1, arch_ctas);
        while(!feof(arch_ctas) && strcmp(cuenta.cod_cta, movimiento.cod_cta))
            fread(&cuenta, sizeof(t_cuenta_banco), 1, arch_ctas);
        if(!feof(arch_ctas))
        {
            if(movimiento.tipo_mov == 'd' || movimiento.tipo_mov == 'D')
                cuenta.saldo -= movimiento.importe;
            else
                cuenta.saldo += movimiento.importe;
            fseek(arch_ctas, -1L*sizeof(cuenta), SEEK_CUR);
            fwrite(&cuenta, sizeof(cuenta), 1, arch_ctas);
        }
        else
            fprintf(arch_err, "%8s, %2c, %.2f \n", movimiento.cod_cta, movimiento.tipo_mov, movimiento.importe);
    }
    rewind(arch_ctas);
    crear_lista_res(plista);
    fread(&cuenta, sizeof(cuenta), 1, arch_ctas);
    while(!feof(arch_ctas))
    {
        instertar_prim5_lista(plista, &cuenta, compararXImporte);
        fread(&cuenta, sizeof(cuenta), 1, arch_ctas);
    }
}

int validar_nro_cuenta(const t_movimiento_banco * c1)
{
    char aux[4];
    int num1,
        num2;
    aux[0] = c1->cod_cta[0];
    aux[1] = c1->cod_cta[2];
    aux[2] = c1->cod_cta[4];
    aux[3] = '\0';
    num1 = atoi(aux);
    aux[0] = c1->cod_cta[1];
    aux[1] = c1->cod_cta[3];
    aux[2] = c1->cod_cta[5];
    aux[3] = '\0';
    num2 = atoi(aux);
    num1 -= num2;
    num1 = (num1/100)+((num1%100)/10)+(num1%10);
    num1 = (num1/10)+(num1%10);
    if(c1->cod_cta[7] == (num1+48))
        return 1;
    return 0;
}
