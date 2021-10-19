#include"cadena.h"

Cadena::Cadena()
{
    _pal=NULL;
}

Cadena::~Cadena()
{
    delete[]_pal;
}

Cadena::Cadena(const char* pal)
{
    _pal= new char[strlen(pal)+1];
    strcpy(_pal,pal);
}

Cadena Cadena::operator+(const char *pal)
{
    Cadena sum;
    sum._pal= new char[strlen(_pal) + strlen(pal) +1];
    strcpy(sum._pal,_pal);
    strcat(sum._pal,pal);
    return sum;
}


Cadena & Cadena::operator = (const Cadena&obj)
{
    this->_pal = new char [strlen(obj._pal)+1];
    strcpy(this->_pal,obj._pal);
    return *this;
}


Cadena & Cadena::operator = (const char*palabra)
{
    this->_pal = new char [strlen(palabra)+1];
    strcpy(this->_pal,palabra);
    return *this;
}

ostream & operator<<(ostream &salida, const Cadena &pal)
{
    salida << pal._pal;
    return salida;
}
