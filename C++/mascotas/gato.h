#ifndef GATO_H_INCLUDED
#define GATO_H_INCLUDED
#include "mascotas.h"
using namespace std;

class Gato : public Mascota{

public:
    Gato(string nombre, int edad);
    void jugarConLaser();
    void comer();
    void dormir();
};


#endif // GATO_H_INCLUDED
