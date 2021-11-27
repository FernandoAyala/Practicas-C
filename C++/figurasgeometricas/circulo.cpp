#include "circulo.h"

Circulo::Circulo(double _radio)
{
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
