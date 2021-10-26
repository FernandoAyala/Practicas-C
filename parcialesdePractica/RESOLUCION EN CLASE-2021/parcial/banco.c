#include<banco.h>
#include<utilitarias.h>
#include<string.h>
#include<stdlib.h>
#include<cola_estatica.h>

int actualizar_cuentas(const char * path_ctas, const char * path_movs, const char * clave)
{
    FILE *arch_cuentas, *arch_movs, *arch_movs_desc;
    ///char path_movs_desc[100];
    t_cuenta_banco cuenta;
    t_movimiento_banco mov, mov_cola;
    int lectura_mov;
    tCola cola_movs;

    crear_cola(&cola_movs);

    arch_cuentas = fopen(path_ctas, "r+b");

    if(!arch_cuentas){
        return 1;
    }

    arch_movs = fopen(path_movs, "rt");

    if(!arch_movs){
        fclose(arch_cuentas);
        return 1;
    }

    ///strcpy(path_movs_desc, path_movs);
    ///strcpy( strchr(path_movs_desc, '.'), "_descubierto.txt");

    arch_movs_desc = fopen("../Archivos/movimientos_descubierto.txt", "wt");

    if(!arch_movs_desc){
        fclose(arch_cuentas);
        fclose(arch_movs);
        return 1;
    }

    fread(&cuenta, sizeof(t_cuenta_banco),1,arch_cuentas);
    lectura_mov = leer_movimiento(&mov, arch_movs, clave);

    while( !feof(arch_cuentas) && lectura_mov ){
        if( strcmp(mov.cod_cta,cuenta.cod_cta) < 0 ){
            lectura_mov = leer_movimiento(&mov, arch_movs, clave);
        }
        else if( strcmp(mov.cod_cta,cuenta.cod_cta) > 0) {
            fread(&cuenta, sizeof(t_cuenta_banco),1,arch_cuentas);
        }
        else {
            while( strcmp(mov.cod_cta,cuenta.cod_cta) == 0 && lectura_mov){
                if(mov.tipo_mov == 'C'){
                    cuenta.saldo+=mov.importe;
                }
                else {
                    cuenta.saldo -=mov.importe;
                }
                poner_en_cola(&cola_movs,&mov, sizeof(t_movimiento_banco));
                lectura_mov = leer_movimiento(&mov, arch_movs, clave);
            }
            fseek(arch_cuentas, - (int)sizeof(t_cuenta_banco),SEEK_CUR);
            fwrite(&cuenta, sizeof(t_cuenta_banco), 1, arch_cuentas);
            fseek(arch_cuentas, 0L, SEEK_CUR);

            if(cuenta.saldo < 0){
                ///sacar de cola y poner en el archivo
                while( sacar_de_cola(&cola_movs, &mov_cola, sizeof(t_movimiento_banco)) ){
                    fprintf(arch_movs_desc, "%7s %c %09.2f\n", mov_cola.cod_cta, mov_cola.tipo_mov, mov_cola.importe);
                }
            }
            else {
                vaciar_cola(&cola_movs);
            }

            fread(&cuenta, sizeof(t_cuenta_banco),1,arch_cuentas);
        }
    }

    fclose(arch_cuentas);
    fclose(arch_movs);
    fclose(arch_movs_desc);

    return 0;
}

