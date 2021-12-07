#include "hora.h"

HoraDelDia::HoraDelDia(int hora, int minutos, int seg)
{
    _seg = hora*3600 + minutos*60 + seg;
    this->ajusta();
}

HoraDelDia::HoraDelDia()
{
    _seg=0;
    _minutos=0;
    _hora =0;
}

void HoraDelDia::ajusta()
{
    while(_seg>=86400)
        _seg-=86400;
}

istream &operator>>(istream &en, HoraDelDia &obj)
{
    int h,m,s;
    en >> h;
    en >> m;
    en>> s;
    obj._seg = h*3600+m*60+s;
    obj.ajusta();
    return en;
}

ostream &operator<< (ostream &sa, const HoraDelDia &obj)
{
    sa<< obj._seg/3600<<":"<< (obj._seg%3600)/60<<":"<< obj._seg%60;
    return sa;
}



bool HoraDelDia::operator!=( const HoraDelDia &obj){

    return _seg != obj._seg;
}


HoraDelDia HoraDelDia::operator++(int s){
    HoraDelDia aux(*this);
    this->_seg++;
    this->ajusta();
    return aux;
}

HoraDelDia HoraDelDia::operator+(HoraDelDia &obj){

    return HoraDelDia(0, 0 , _seg + obj._seg);
}

HoraDelDia operator+(int s, const HoraDelDia &obj){

    return HoraDelDia(0, 0 , s + obj._seg);
}

HoraDelDia HoraDelDia::operator+=(int s)
{
    return HoraDelDia(0,0, _seg + s);
}

HoraDelDia HoraDelDia::getHoraMaxima()
{
    return HoraDelDia(23,59,59);
}
