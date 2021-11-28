#include "perro.h"

Perro::Perro(string nombre, int edad, int muevoCola) : Mascota(nombre, edad), muevoCola(muevoCola) {};

void Perro::comer()
{
    cout<< "Perro"<<endl;
    Mascota::comer();
}

void Perro::dormir()
{
    cout<< "Perro"<<endl;
    Mascota::dormir();
}

void Perro::moverCola()
{
    cout << "Muevo la cola " << muevoCola << " veces al dia"<<endl;
}

ostream & operator<<(
    ostream &salida,
    const Perro &obj)
{

    salida << "Nombre:"
           <<obj.getNombre()  << endl
           <<"Edad:"
           << obj.getEdad()  << endl
           <<"Mueve Cola:"
           << obj.muevoCola;

    return salida;
}
