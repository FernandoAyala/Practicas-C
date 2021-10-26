#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <utilitarias.h>
#include <banco.h>

void texto_a_movimiento(const char * cadena,t_movimiento_banco * pmov)
{
    sscanf(cadena, "%7s%c%9f", pmov->cod_cta,&pmov->tipo_mov, &pmov->importe);
    pmov->cod_cta[7] = pmov->cod_cta[6];
    pmov->cod_cta[6] = '/';
    pmov->cod_cta[8] = '\0';
}

void invertir(char * ini, char * fin)
{
    char aux;
    while(ini<fin){
        aux=*ini;
        *ini=*fin;
        *fin=aux;
        ini++;
        fin--;
    }
}
/**
c: caracter de la cadena 10
e: caracter de la clave 11
**/
void desencriptar_caracter(char* c, char e)
{
    static char caras [] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int posc = isdigit(*c)? *c-'0':isupper(*c)? *c-'A'+10: *c-'a'+36;
    int pose = isdigit(e)? e-'0':isupper(e)? e-'A'+10: e-'a'+36;

    int dif;
    if (isalnum(*c))
        *c = caras[(dif=(posc-pose))>=0? dif : dif + (sizeof(caras)-1)];
}

void desencriptar_por_palabra_clave(char*cad, const char*clave)
{
    char *aux=cad;
    int i =0, largoClave=strlen(clave);
    while(*aux)
    {
        desencriptar_caracter(aux, clave[i%largoClave]);
        aux++;
        i++;
    }
}

char * desencriptar(char * cad, const char * clave)
{
    char * fin=cad, *aux=cad;
    desencriptar_por_palabra_clave(cad, clave);

    while(*fin)
        fin++;
    fin--;

    aux = fin-(*fin-'0');
    invertir(aux, fin-1);
    aux = cad+(*cad-'0');
    invertir(cad+1, aux);
    return cad;
}

int leer_movimiento(t_movimiento_banco * mov, FILE * arch_mov, const char * clave)
{
    char texto[50],
        * aux;
    fgets(texto,50,arch_mov);

    if( !feof(arch_mov) )
    {
        aux = strchr(texto,'\n');
        *aux = '\0';
        texto_a_movimiento(desencriptar(texto, clave),mov);
        return 1;
    }
    return 0;
}

