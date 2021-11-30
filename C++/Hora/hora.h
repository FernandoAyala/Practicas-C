#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

#include <iostream>
using namespace std;
class Hora
{
private:
    int horas;
    int minutos;
    int seg;
public:
        Hora();
        Hora(int h, int m, int s);
        void ajusta();
        bool operator>=(const Hora &obj)const;
        bool operator<(const Hora &obj)const;
        Hora operator++(int);
        Hora& operator+=(int s);
        Hora operator+(const Hora &obj)const;
        friend Hora operator+(int s, const Hora &obj);
        friend istream &operator>>(istream &en, Hora &obj);
        friend ostream &operator<<(ostream &sa, const Hora &obj);
        static Hora getHoraMaxima();


};


#endif // HORA_H_INCLUDED
