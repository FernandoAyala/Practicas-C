#include "Cadena.h"

Cadena::Cadena(const char *cad)
{
    pal = new char[strlen(cad)+1];
    strcpy(pal,cad);
}

Cadena::Cadena()
{
    pal= NULL;
}

Cadena::~Cadena()
{
    delete[] pal;
}

ostream &operator<<(ostream &sal, const Cadena &obj)
{
    sal << obj.pal;
    return sal;
}

istream &operator>>(istream &en, Cadena &obj)
{
    char aux[200];
    en.getline(aux, 200, '\n');
    delete[] obj.pal;
    obj.pal = new char[strlen(aux) + 1];
    strcpy(obj.pal, aux);
    return en;
}

Cadena& Cadena::operator=(const char * cad)
{
    delete[] pal;
    pal = new char[strlen(cad +1)];
    strcpy(pal, cad);
    return *this;
}

Cadena Cadena::operator+(const Cadena &obj) const
{
    Cadena sum;
    sum.pal = new char[strlen(pal) + strlen(obj.pal) + 1];
    strcpy(sum.pal, pal);
    strcat(sum.pal, obj.pal);
    delete[] obj.pal;
    return sum.pal;
}

bool Cadena::operator==( const char *cad) const
{
    return strcmp(pal, cad);
}

bool Cadena::operator!=( const Cadena &obj) const
{
    return !strcmp(pal, obj.pal);
}

Cadena& Cadena::operator+=(const char *cad)
{
    strcat(pal, cad);
    return *this;
}

Cadena operator+(const char *cad,const Cadena &obj)
{
    Cadena sum;
    sum.pal = new char[strlen(cad) + strlen(obj.pal) +1];
    strcpy(sum.pal, cad);
    strcat(sum.pal , obj.pal);
    delete[] obj.pal;
    return sum.pal;
}
