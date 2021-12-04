#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED
#include <iostream>

using namespace std;

class Racional {

private:
    float num,
            den;

public:

        Racional();
        Racional(float, float);
        Racional(float);
        Racional operator+(Racional &);
        bool operator>(const Racional &);
        float real() const;
        friend Racional operator+(int s,const Racional &obj);
        friend ostream &operator<<(ostream &sal, const Racional &obj);
        friend istream &operator>>(istream &en, Racional &obj);
};

#endif // RACIONAL_H_INCLUDED
