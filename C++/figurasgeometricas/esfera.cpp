#include "esfera.h"
#include <math.h>

Esfera::Esfera(double _radio)
{
    radio =_radio;
}

double Esfera:: volumen(){
     double vol= ((pow(radio,3)*PI)*(4)/3);
     return vol;
   }

double Esfera:: area(){
     double ar = 4*PI*pow(radio,2);
     return ar;
   }
