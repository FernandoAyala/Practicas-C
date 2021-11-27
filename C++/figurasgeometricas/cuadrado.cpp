#include "cuadrado.h"

Cuadrado::Cuadrado(double _lado)
{
    lado =_lado;
}

double Cuadrado:: perimetro(){
     double per= lado*4;
     return per;
   }

double Cuadrado:: area(){
     double ar = lado*lado;
     return ar;
   }
