#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
#include "figuras2D.h"
#include <iostream>
class Triangulo : public Figura2D{

private:
    double lado1;
    double lado2;
    double lado3;

public:
    Triangulo(double lado1, double lado2, double lado3);
    double area();
    double perimetro();

};




#endif // TRIANGULO_H_INCLUDED
