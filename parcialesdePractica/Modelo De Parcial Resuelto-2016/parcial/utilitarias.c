#include <stdio.h>
#include <string.h>
#include <utilitarias.h>
#include <banco.h>

void texto_a_movimiento(const char * cad,t_movimiento_banco * pmov)
{
    char *p = strrchr(cad, '|');
    sscanf(p+1,"%f", &pmov->importe);
    *p = '\0';
    p = strrchr(cad, '|');
    sscanf(p+1,"%c", &pmov->tipo_mov);
    *p = '\0';
    strcpy(pmov->cod_cta,cad);
}

int compararXImporte(const t_info *a, const t_info *b)
{
    return (a->saldo - b->saldo);
}
