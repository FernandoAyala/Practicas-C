#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include<iostream>

using namespace std;

class HoraDelDia{

private:
    int _hora,
        _minutos,
        _seg;
public:
    HoraDelDia();
    HoraDelDia(int,int,int);
    bool operator !=(const HoraDelDia &);
    HoraDelDia operator++(int);
    HoraDelDia operator+( HoraDelDia&);
    HoraDelDia operator+=(int);
    void ajusta();
    friend HoraDelDia operator+(int s ,const HoraDelDia &obj);
    friend istream &operator>>(istream &, HoraDelDia &);
    friend ostream &operator<<( ostream &,const HoraDelDia &);
    static HoraDelDia getHoraMaxima();
};


#endif // HORA_H_INCLUDED
