#include "gato.h"

Gato::Gato(string nombre, int edad) : Mascota(nombre, edad){};

void Gato::comer(){
    cout<< "Gato"<<endl;
    Mascota::comer();
}

void Gato::dormir(){
    cout<< "Gato"<<endl;
    Mascota::dormir();
}

void Gato::jugarConLaser(){
cout << "Juego con el laser"<<endl;
}
