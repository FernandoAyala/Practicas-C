#include "fecha.h"

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia=dia;
    _mes=mes;
    _anio=anio;
}

Fecha Fecha::operator++(int)
{
    _dia++;
    return *this;
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
