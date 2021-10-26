#include "funcade.h"


using namespace std;

Cadena::Cadena(const char *cad)
{
    if(!cad)
    {
        this->vcad = new char[1];
        *this->vcad='\0';
        return;
    }
    this->vcad=new char[strlen(cad)+1];
    strcpy(this->vcad,cad);
}
Cadena::~Cadena()
{
    delete[]this->vcad;
}
Cadena::Cadena(const Cadena &otra)
{

    this->vcad=new char[strlen(otra.vcad)+1];
    strcpy(this->vcad,otra.vcad);
}
Cadena &Cadena::operator =(const Cadena &otra)
{
    size_t longcad = strlen(otra.vcad);

    if(longcad != strlen(this->vcad))
    {
        delete[]this->vcad;
        this->vcad = new char[longcad+1];
    }
    strcpy(this->vcad,otra.vcad);

    return *this;
}
Cadena Cadena::operator +(const Cadena &cad2)const
{
    Cadena suma;
   // delete[]suma.vcad;
    suma.vcad = new char[strlen(this->vcad)+strlen(cad2.vcad)+1];
    strcpy(suma.vcad,this->vcad);
    strcat(suma.vcad,cad2.vcad);

    return suma;
}

void Cadena::imprimir()
{
    printf(this->vcad);
}
