#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;


class Cadena {

private:
    char * pal;

public:
        Cadena(const char *);
        ~Cadena();
        Cadena();
        Cadena operator+(const Cadena &) const;
        Cadena& operator=(const char *);
        Cadena& operator+=(const char *);
        bool operator==( const char *) const;
        bool operator!=(const Cadena &) const;
        friend Cadena operator+(const char *,const Cadena &obj);
        friend ostream &operator<<(ostream &sal, const Cadena &obj);
        friend istream &operator>>(istream &en, Cadena &obj);
};

#endif // CADENA_H_INCLUDED
