#ifndef FIGURAS2D_H_INCLUDED
#define FIGURAS2D_H_INCLUDED
#include "figuras.h"
#include <iostream>
class Figura2D : public Figuras
{

public:
    virtual ~Figura2D(){};
    virtual double area() = 0;
    virtual double perimetro() = 0;
};


#endif // FIGURAS2D_H_INCLUDED
