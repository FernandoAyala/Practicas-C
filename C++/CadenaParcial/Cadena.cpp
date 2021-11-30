#include "Cadena.h"

Cadena::Cadena()
{
    cad = NULL;
};

Cadena::~Cadena()
{
    delete[]cad;
}

Cadena::Cadena(const char *c)
{
    cad = new char[strlen(c)+1];
    strcpy(cad, c);
}

ostream &operator<<(ostream &os, const Cadena &obj)
{
    os << obj.cad;
    return os;
}

Cadena& Cadena::operator=(const char *c)
{
    cad = new char[strlen(c)+1];
    strcpy(cad, c);
    return *this;
}

Cadena Cadena::operator+(const Cadena &obj) const
{
    Cadena suma;
    suma.cad = new char[strlen(cad) + strlen(obj.cad)+1];
    strcpy(suma.cad, cad);
    strcat(suma.cad, obj.cad);
    return suma.cad;
}

bool Cadena::operator==(const char *c) const
{
    return strcmp(cad, c);
}

bool Cadena::operator!=(const Cadena &obj) const
{
    return !strcmp(cad, obj.cad);
}

istream &operator>>(istream &is, Cadena &obj)
{
    char aux[200];
    is.getline(aux, 200, '\n');
    delete[]obj.cad;
    obj.cad =  new char[strlen(aux)+1];
    strcpy(obj.cad, aux);
    return is;
}

Cadena& Cadena::operator+=(const char *c)
{

    strcat(cad, c);
    return *this;
}

Cadena operator+(const char *c, const Cadena &obj)
{
    Cadena suma;
    suma.cad = new char[strlen(c) + 1 + (strlen(obj.cad) + 1)];
    strcpy(suma.cad, c);
    strcat(suma.cad, obj.cad);
    return suma.cad;
}

