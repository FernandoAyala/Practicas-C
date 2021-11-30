#include <iostream>
#include "figuras.h"
#include "figuras2D.h"
#include "figuras3D.h"
#include "circulo.h"
#include "cuadrado.h"
#include "triangulo.h"
#include "esfera.h"
#include "valorinvalidoException.h"

using namespace std;


int main()
{
    Figura2D * figuraBidimensional;
    Figura3D * figuraTridimensional;

    // Definir las variables necesarias

    double radio = -1;

    cout <<"CIRCULO"<< endl;
    try
    {
        figuraBidimensional = new Circulo(radio);
        cout <<"Area "<< figuraBidimensional -> area() << endl;
        cout <<"Perimetro "<< figuraBidimensional -> perimetro() << endl;
        delete figuraBidimensional;
    }
    catch( ValorInvalidoException &error)
    {
        cout << error.what() << endl;
    }



    double lado = -5;
    cout <<endl;
    cout <<"CUADRADO"<< endl;
    try
    {
        figuraBidimensional = new Cuadrado(lado);
        cout <<"Area "<< figuraBidimensional -> area()<< endl;
        cout <<"Perimetro "<< figuraBidimensional -> perimetro()<< endl;
        delete figuraBidimensional;
    }
    catch(ValorInvalidoException &error)
    {
        cout << error.what() << endl;
    }

    double lado1 = 5;
    double lado2 = 5;
    double lado3 = 5;
    cout <<endl;
    cout <<"TRIANGULO"<< endl;
    try
    {
        figuraBidimensional = new Triangulo(lado1, lado2, lado3);
        cout <<"Area "<< figuraBidimensional -> area()<< endl;
        cout <<"Perimetro "<< figuraBidimensional -> perimetro()<< endl;
        delete figuraBidimensional;
    }
    catch(ValorInvalidoException &error)
    {
        cout << error.what() << endl;
    }

    double radioE = 2;
    cout <<endl;
    cout <<"ESFERA"<< endl;

    try
    {
        figuraTridimensional = new Esfera(radioE);
        cout <<"Area "<< figuraTridimensional -> area()<< endl;
        cout <<"VOlumen " << figuraTridimensional -> volumen()<< endl;
        delete figuraTridimensional;
    }
    catch (ValorInvalidoException &error)
    {
        cout <<error.what() << endl;
    }

    // Hacer lo mismo para Tetraedro y Cubo

    return 0;
}
