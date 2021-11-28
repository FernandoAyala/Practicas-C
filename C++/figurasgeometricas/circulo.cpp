#include "circulo.h"
#include "valorinvalidoException.h"

Circulo::Circulo(double _radio)
{
    if(_radio <= 0)
    {
        throw ValorInvalidoException();
    }
    else
    radio =_radio;
}

double Circulo:: perimetro(){
     double per=2*PI*radio;
     return per;
   }

double Circulo:: area(){
     double ar=PI*radio*radio;
     return ar;
   }
