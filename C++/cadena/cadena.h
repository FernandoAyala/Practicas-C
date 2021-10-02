#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

class Cadena
{

private:
    char * _pal;
public:
    Cadena();
    ~Cadena();
    Cadena(const char*);
    Cadena operator+(const char *);

    friend ostream & operator<<(ostream &salida, const Cadena &);
};

#endif // CADENA_H_INCLUDED
