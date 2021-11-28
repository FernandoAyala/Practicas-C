#include "cuadrado.h"
#include "valorinvalidoException.h"

Cuadrado::Cuadrado(double _lado)
{
    if(_lado <= 0)
    {
       throw ValorInvalidoException() ;
    }
    else
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
