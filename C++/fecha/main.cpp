#include "fecha.h"

int main()
{
    Fecha fechaActual;
    Fecha fecha1(15, 7, 2021);
    // Fecha fecha2(30, 2, 2021); // Fecha inv�lida
    Fecha fecha3(30, 4, 2021);
    Fecha fecha4(31, 12, 2021);
    Fecha fecha5(1, 1, 2022);
//
    fecha1++; // 16, 7, 2021
//    fecha3++; // 1,5,2021
//    fecha4++; // 1,1,2022
//
//    bool comparacion1 = fecha1 == fecha3;
//    bool comparacion2 = fecha4 == fecha5;
//
//    fecha1 += 4;
//    --fecha5;

    cout << fecha1 <<endl;
    cout << fecha3 <<endl;
    cout << fecha4 <<endl;
    cout << fecha5 <<endl;

//    cin >> fecha5;
//    cout << fecha5;

    return 0;
}
