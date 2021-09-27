#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
#include <time.h>

using namespace std;

class Fecha
{

private:
    unsigned int _dia;
    unsigned int _mes;
    unsigned int _anio;

    static bool esFechaValida(unsigned int, unsigned int, unsigned int);

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    Fecha operator++(int);
    bool operator==(const Fecha &) const;
    void operator+=(int);
    Fecha operator-(int)const;
    Fecha& operator-=(int);
    Fecha& operator--();
    Fecha operator--(int);

    friend Fecha operator+(const int &, const Fecha &);
    friend Fecha operator-(const int &, const Fecha &);
    friend ostream &operator<<(ostream& salida, const Fecha &);
    friend istream & operator>>(istream &entrada,  Fecha &);
};


#endif // FECHA_H_INCLUDED
