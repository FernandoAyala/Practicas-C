#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED
#include <iostream>
#include"figuras3D.h"

class Esfera : public Figura3D{
private:
    double radio;
public:
    Esfera(double radio);
    double area();
    double volumen();
};


#endif // ESFERA_H_INCLUDED
