#ifndef FUNCH_H_INCLUDED
#define FUNCH_H_INCLUDED
#include <iostream>
using namespace std;
class Hora
{
private:
        int horas;
        int minutos;
        int seg;
    public:
        Hora(int = 0);
        Hora (const Hora &);
        Hora &operator=(const Hora &);
        Hora operator+(const Hora &) const;
        Hora &operator++();
        Hora operator++(int);
        friend ostream & operator<<(ostream &salida, const Hora &);
        friend istream & operator>>(istream &entrada, Hora &);

    // protected: // Despues

};


#endif // FUNCH_H_INCLUDED
