#ifndef PERRO_H_INCLUDED
#define PERRO_H_INCLUDED
#include <iostream>
#include "mascotas.h"
using namespace std;

class Perro : public Mascota{
private:
    int muevoCola;
public:
    Perro(string nombre, int edad, int muevoCola);
    void moverCola();
    friend ostream & operator<<(ostream &salida, const Perro &);
    void comer();
    void dormir();
};



#endif // PERRO_H_INCLUDED
