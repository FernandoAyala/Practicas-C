#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>

using namespace std;

class Fecha{

private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha(int dia=18, int mes=9, int anio=2021);
    Fecha operator++(int);

    friend ostream &operator<<(ostream& salida, const Fecha &);
    friend istream & operator>>(istream &entrada,  Fecha &);
};


#endif // FECHA_H_INCLUDED
