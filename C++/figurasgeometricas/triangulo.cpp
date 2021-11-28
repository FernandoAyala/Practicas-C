#include "triangulo.h"
#include <math.h>
#include "valorinvalidoException.h"
Triangulo::Triangulo(double _lado1,double _lado2,double _lado3)
{
    if(_lado1 <=0 || _lado2<=0 || _lado3 <= 0)
    {
        throw ValorInvalidoException();
    }
    else
    {
        lado1 =_lado1;
        lado2 =_lado2;
        lado3 =_lado3;
    }
}

double Triangulo:: perimetro()
{
    double per= lado1*3;
    return per;
}

double Triangulo:: area()
{
    double ar = ((lado1*lado2)*sqrt(3))/4;
    return ar;
}
