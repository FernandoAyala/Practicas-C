#include <stdio.h>
#include <stdlib.h>

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
// En Proceso
//void *mi_memcpy(void *s1, const void *s2, size_t n)
//{
//    for(int i = 0; i<= n ; i++)
//    {
//        *s1=*s2;
//    }
//    return s1;
//}
