#include "Racional.h"

Racional::Racional(){
    num= 0;
    den = 1;
}

Racional::Racional(float _num , float _den)
{
    num = _num;
    den = _den;
}

Racional::Racional(float _num)
{
    num=_num;
    den = 1;
}

ostream &operator<<(ostream &sal, const Racional &obj)
{
      sal << obj.num
        << '/'
        << obj.den;
        return sal;
}

Racional Racional::operator+(Racional &obj)
{
    return Racional(obj.num + num , obj.den + den);
}

Racional operator+(int s, const Racional &obj)
{

    return Racional(obj.num +s, obj.den);
}

float Racional::real() const
{
    return num;
}

istream &operator>>(istream &en, Racional &obj)
{
    en >>obj.num
        >>obj.den;
        return en;
}

bool Racional::operator>(const Racional &obj)
{
    return num>obj.num;
}
