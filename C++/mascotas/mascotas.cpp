#include "mascotas.h"

 Mascota::Mascota( string nombre, int edad): nombre(nombre), edad(edad){};

 void Mascota::comer(){
 cout << "Como mi Alimento mmm rico rico" << endl;
 }

 void Mascota::dormir(){
 cout << "Duermo 8 horas" << endl;
 }


string Mascota::getNombre() const
{
    return nombre;
}

int Mascota::getEdad() const
{
    return edad;
}
