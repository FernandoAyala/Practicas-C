#include <iostream>
#include "figuras.h"
#include "figuras2D.h"
#include "figuras3D.h"
#include "circulo.h"
#include "cuadrado.h"
#include "triangulo.h"
#include "esfera.h"

using namespace std;


int main()
{
    Figura2D * figuraBidimensional;
    Figura3D * figuraTridimensional;

    // Definir las variables necesarias

    double radio = 5;

    figuraBidimensional = new Circulo(radio);
    cout <<"Area "<< figuraBidimensional -> area() << endl;
    cout <<"Perimetro "<< figuraBidimensional -> perimetro() << endl;
    delete figuraBidimensional;

    double lado = 5;

    figuraBidimensional = new Cuadrado(lado);
    cout <<"Area "<< figuraBidimensional -> area()<< endl;
    cout <<"Perimetro "<< figuraBidimensional -> perimetro()<< endl;
    delete figuraBidimensional;

    double lado1 = 5;
    double lado2 = 5;
    double lado3 = 5;

    figuraBidimensional = new Triangulo(lado1, lado2, lado3);
    cout <<"Area "<< figuraBidimensional -> area()<< endl;
    cout <<"Perimetro "<< figuraBidimensional -> perimetro()<< endl;
    delete figuraBidimensional;

    double radioE = 2;

    figuraTridimensional = new Esfera(radioE);
    cout <<"Area "<< figuraTridimensional -> area()<< endl;
    cout <<"VOlumen " << figuraTridimensional -> volumen()<< endl;
    delete figuraTridimensional;

    // Hacer lo mismo para Tetraedro y Cubo

    return 0;
}
