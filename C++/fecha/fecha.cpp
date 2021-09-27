#include "fecha.h"

#define AN_MIN 1
#define AN_MAX 3000
#define esBisiesto( X ) ( ( ( X ) % 4 == 0 && ( X ) % 100 != 0 ) || ( X ) % 400 == 0 )

Fecha::Fecha()
{
    time_t x = time(0);
    struct tm y;
    y = *localtime(&x);

    _dia = (unsigned int)y.tm_mday;
    _mes = (unsigned int)y.tm_mon + 1;
    _anio = (unsigned int)y.tm_year + 1900;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia=dia;
    _mes=mes;
    _anio=anio;
}

Fecha Fecha::operator++(int)
{
    _dia++;
    if(_dia == 32)
    {
        _dia=1;
        _mes++;
        if(_mes == 13)
        {
            _mes=1;
            _anio++;
        }
    }

    return *this;
}

void Fecha::operator+=(int dia)
{
    _dia+=dia;

}

ostream &operator<<(
    ostream& salida,
    const Fecha &obj)
{
    salida << obj._dia
           << "/"
           << obj._mes
           << "/"
           << obj._anio;

    return salida;

}

istream & operator>>(
    istream &entrada,
    Fecha &obj)
{
    entrada >> obj._dia
            >> obj._mes
            >>obj._anio;

    return entrada;
}

bool Fecha::esFechaValida( unsigned int dia
                           ,unsigned int mes
                           ,unsigned int anio )
{
    static const unsigned int dias[][12] =
    {
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
        ,{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };

    return mes > 0 && mes <= 12 &&
           anio >= AN_MIN && anio <= AN_MAX &&
           dia > 0 && dia <= dias[esBisiesto(anio)][mes - 1];
}

bool Fecha::operator==(const Fecha &obj) const
{
    return((_anio == obj._anio && _mes==obj._mes && _dia==obj._dia)? true : false);
}


Fecha operator+(const int &dia, const Fecha &obj)
{

    Fecha aux(dia + obj._dia,obj._mes,obj._anio);
    return aux;
}

Fecha operator-(const int &dia, const Fecha &obj)
{

    Fecha aux(dia - obj._dia,obj._mes,obj._anio);
    return aux;
}

Fecha& Fecha::operator--()
{
*this = *this - 1;
return *this;
}

Fecha Fecha::operator--(int)
{
Fecha tmp(*this);
operator--();
return tmp;
}

Fecha Fecha::operator-(int der) const
{
Fecha aux = *this;

static const int dias[][12] =
{
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
,{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};


if(this->_dia - der < 1)
{
if(aux._mes-1 < 1)
{
aux._anio--;
aux._mes = 12;
}
else
{
aux._mes--;
}
aux._dia = aux._dia+dias[esBisiesto(aux._anio)][aux._mes-1]-der;
}
else
{
aux._dia -= der;
}

return aux;
}
