#include <iostream>
#include <windows.h>
#include "hora.h"

using namespace std;

int main()
{
    HoraDelDia inicio, fin(0,0,20); ///Horas, Minutos, Segundos
    cout<<"ingrese el horario de inicio: ";
    cin>>inicio;
    cout<<endl<<"ingrese el horario de fin: ";
    cin>>fin;
    while(inicio!=fin)
    {
        system("cls");
        cout<<"actual: "<<inicio++<<endl<<"fin: "<<fin; ///++ incrementea en 1 segundo la hora
        Sleep(1000);
    }
    cout<<"fin";
    HoraDelDia h1(22,54,21), h2(1,20,55), h3; ///la hora nunca debe ser mayor a las 23:59:59
    h3 = h1+h2;
    cout<<h3<< endl;
    h3+=2; ///segundos
    cout<<h3<< endl;
    h3 = 3+h3; ///segundos
    cout<<h3<< endl;
    h3 = HoraDelDia::getHoraMaxima(); ///devuelve una hora a las 23:59:59
    cout<<h3<< endl;
    return 0;
}
