#include "fecha.h"
#define AN_MIN 1
#define AN_MAX 3000
#define ES_BISIESTO(x) ( ( (x) % 4 == 0 && (x) % 100 != 0 ) || (x) % 400 == 0 )
#include "FechaInvalidaException.h"

using namespace std;

Fecha::Fecha(unsigned char dia, unsigned char mes, unsigned int anio)
{
    if(!fechaValida(dia,mes,anio))
    {
        throw FechaInvalidaException();
    }
    _dia = dia;
    _mes= mes;
    _anio= anio;
}

bool Fecha::fechaValida(unsigned char d, unsigned char m, unsigned int a)
{
    static const char dias[][12] = { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };

    return m > 0 && m <= 12 &&
           a >= AN_MIN && a <= AN_MAX &&
           d > 0 && d <= dias[ES_BISIESTO(a)][m - 1];
}
