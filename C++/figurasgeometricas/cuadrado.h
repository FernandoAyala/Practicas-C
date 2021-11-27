#ifndef CUADRADO_H_INCLUDED
#define CUADRADO_H_INCLUDED
#include <iostream>
#include"figuras2D.h"

class Cuadrado : public Figura2D{
private:
    double lado;
public:
    Cuadrado(double lado);
    double area();
    double perimetro();

};




#endif // CUADRADO_H_INCLUDED
