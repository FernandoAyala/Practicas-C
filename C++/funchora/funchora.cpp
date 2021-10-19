#include "funch.h"

Hora::Hora(int _seg)
{
    seg=_seg;
}


Hora::Hora(const Hora &obj)
{
    seg=obj.seg;
}

Hora &Hora::operator=(const Hora &obj)
{
    seg = obj.seg;
    return *this;
}


Hora Hora::operator+(
         const Hora &obj) const
{
    Hora aux(this->seg + obj.seg);
    return aux;
}

ostream & operator<<(
                    ostream &salida,
                    const Hora &obj)
{

    salida << obj.seg/3600%24
           << ":"
           << obj.seg/60%60
           << ":"
           <<obj.seg%60;

    return salida;
}

istream & operator>>(
                     istream &entrada,
                     Hora &obj)
{
    entrada >> obj.seg;

    return entrada;
}

Hora & Hora::operator++()
{
    seg++;
 return *this;
}

Hora Hora::operator++(int)
{
    Hora aux(*this);
    this->seg++;
    return aux;
}
