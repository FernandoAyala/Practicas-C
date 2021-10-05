#include <stdio.h>
#include <stdlib.h>

//char *_strstr(const char *s1, const char *s2)
//{
//    ///return null;
//}

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
