#ifndef FUNH_H_INCLUDED
#define FUNH_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

class Cadena
{
private:
    char *pal;

public:
    Cadena();
    Cadena(const char*);
    Cadena(const Cadena &);
    ~Cadena();
    Cadena operator+(const Cadena &)const;
    Cadena & operator=(const Cadena &);
    friend istream & operator>>(istream &entrada,Cadena &);
    friend ostream & operator<<(ostream &salida,const Cadena &);
    friend Cadena operator+(const char* ,const Cadena &);
    int longitud();
};


#endif // FUNH_H_INCLUDED
