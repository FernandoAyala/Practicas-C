#ifndef FIGURAS3D_H_INCLUDED
#define FIGURAS3D_H_INCLUDED
#include "figuras.h"
#include <iostream>

class Figura3D : public Figuras
{

public:
    virtual ~Figura3D(){};
    virtual double area() = 0;
    virtual double volumen() = 0;
};


#endif // FIGURAS3D_H_INCLUDED
