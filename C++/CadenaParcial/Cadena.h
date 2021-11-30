#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <string.h>
#include <iostream>

using namespace std;

class Cadena
{
    private:
        char *cad;
    public:
        Cadena();
        ~Cadena();
        Cadena(const char *c);
        Cadena& operator=(const char *c);
        Cadena operator+(const Cadena &obj) const;
        bool operator==(const char *c) const;
        bool operator!=(const Cadena &obj) const;
        Cadena& operator+=(const char *c);
        friend ostream &operator<<(ostream &os, const Cadena &obj);
        friend istream &operator>>(istream &is, Cadena &obj);
        friend Cadena operator+(const char *c, const Cadena &obj);
};

#endif // CADENA_H_INCLUDED
