#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include <iostream>
using namespace std;

class Mascota{
private:
    string nombre;
    int edad;
public:
    Mascota( string nombre, int edad);
    void comer();
    void dormir();
    string getNombre() const;
    int getEdad() const;
};

#endif // MASCOTAS_H_INCLUDED
