#ifndef FUNCADE_H_INCLUDED
#define FUNCADE_H_INCLUDED
#include <iostream>
#include <string.h>
#include <stdio.h>
class Cadena{
    private:
        char *vcad;
    public:
        Cadena(const char *cad = NULL);
        Cadena(const Cadena &otra);
        ~Cadena();
        Cadena operator +(const Cadena &cad2)const;

        Cadena &operator =(const Cadena &otra);
        void imprimir();
};

#endif // FUNCADE_H_INCLUDED
