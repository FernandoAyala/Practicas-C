#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED
#include <iostream>
#include"figuras2D.h"

class Circulo : public Figura2D{
private:
    double radio;
public:
    Circulo(double radio);
    double area();
    double perimetro();

};


#endif // CIRCULO_H_INCLUDED
