#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED
#include <iostream>

using namespace std;
class Complejo
{
private:
        int re;
        int im;
    public:
        Complejo(int , int);
        Complejo(const Complejo &);
        void setReal(int );
        // Complejo &operator=(const Complejo &);
        Complejo operator+(const Complejo &) const;
        Complejo operator+=(const Complejo &);
        Complejo operator*(const Complejo &) const;
        friend Complejo operator*(const int &, const Complejo &);
        friend ostream & operator<<(ostream &salida, const Complejo &);
        friend istream & operator>>(istream &entrada, Complejo &);

};

#endif // COMPLEJO_H_INCLUDED
