#include <iostream>

using namespace std;


int main()
{
    Figura2D * figuraBidimensional;
    Figura3D * figuraTridimensional;

    // Definir las variables necesarias

    figuraBidimensional = new Circulo(radio);
    cout << figuraBidimensional -> area();
    cout << figuraBidimensional -> perimetro();
    delete figuraBidimensional;

    figuraBidimensional = new Cuadrado(lado);
    cout << figuraBidimensional -> area();
    cout << figuraBidimensional -> perimetro();
    delete figuraBidimensional;

    figuraBidimensional = new Triangulo(lado1, lado2, lado3);
    cout << figuraBidimensional -> area();
    cout << figuraBidimensional -> perimetro();
    delete figuraBidimensional;

    figuraTridimensional = new Esfera(/* Inicializar */)
    cout << figuraTridimensional -> area();
    cout << figuraTridimensional -> volumen();
    delete figuraTridimensional;

    // Hacer lo mismo para Tetraedro y Cubo

    return 0;
}
