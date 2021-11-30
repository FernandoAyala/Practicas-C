#include "hora.h"


Hora::Hora()
{
    seg = 0;
}

void Hora::ajusta(){
    while(seg>=86400)
        seg -= 86400;
}


Hora::Hora(int h, int m, int s)
{
    seg = h*3600 + m*60 + s;
    this->ajusta();
}


istream &operator>>(istream &en, Hora &obj)
{
    int h, m, s;
    en >> h;
    en >> m;
    en >> s;
    obj.seg = h*3600 + m*60 + s;
    obj.ajusta();
    return en;
}

ostream &operator<<(ostream &sa, const Hora &obj)
{
    sa <<obj.seg/3600 << ':' << (obj.seg%3600)/60 << ':' << obj.seg%60;
    return sa;
}


bool Hora::operator>=(const Hora &obj)const
{
    return seg>=obj.seg;
}

bool Hora::operator<(const Hora &obj)const
{
    return seg<obj.seg;
}

Hora Hora::operator++(int)
{
    Hora aux(*this);
    this->seg++;
    this->ajusta();
    return aux;
}

//Hora Hora::operator+(const Hora &obj)const
//{
//    return Hora(0, 0, seg + obj.seg);
//}

Hora operator+(int s, const Hora &obj)
{
    return Hora(0, 0, s + obj.seg);
}

Hora& Hora::operator+=(int s)
{
    this-> seg += s;
    this->ajusta();
    return *this;
}

Hora Hora::getHoraMaxima()
{
    return Hora(23,59,59);
}
