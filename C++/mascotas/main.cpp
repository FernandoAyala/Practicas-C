#include <iostream>
#include "mascotas.h"
#include "perro.h"
#include "gato.h"
using namespace std;

int main()
{
    Perro pluto("Pluto",4,4);
    cout << "pluto: " << endl;
    cout << pluto << endl;
    cout<<endl;
    pluto.dormir();
    cout<<endl;
    pluto.comer();
    cout<<endl;
    pluto.moverCola();

    Gato garfield("Garfield",4);
    cout<<endl;
    garfield.dormir();
    cout<<endl;
    garfield.comer();
    cout<<endl;
    garfield.jugarConLaser();

    return 0;
}
