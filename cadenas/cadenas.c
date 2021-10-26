#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

char *mi_strstr(const char *s1, const char *s2)
{
    while(*s1)
    {
        s1++;
        if(*s1==*s2)
        {
            s2++;
            if(*s2)
                return (char *)s1;
        }
    }
    return (char *)s1;
}

int mi_strlen(const char *s)
{
    int suma = 0;
    while(*s)
    {
        s++;
        suma++;
    }
    return suma;
}

char *mi_strchr(char *s, int c)
{
    while(*s)
    {
        if(*s == c)
            return s;
        s++;
    }
    return 0;
}

char *mi_strrchr(char *s, int c)
{
    while(*s)
        s++;
    s--;
    while(*s)
    {
        if(*s==c)
            return s;
        s--;
    }
    return 0;
}

char *mi_strcpy(char *s1, const char *s2)
{
    char *p = s1;
    while(*s2)
    {
        *s1=*s2;
        s2++;
        s1++;
    }
    *s1='\0';
    return p;
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

int validar_nro_cuenta(t_movimiento_banco * c1)
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
    c1->cod_cta[6]='/';
    c1->cod_cta[7]=num1 + '0';
    printf("%s",c1->cod_cta);
    if(c1->cod_cta[7] == (num1+48))
        return 1;
    return 0;
}
// En Proceso
//void *mi_memcpy(void *s1, const void *s2, size_t n)
//{
//    for(int i = 0; i<= n ; i++)
//    {
//        *s1=*s2;
//    }
//    return s1;
//}
