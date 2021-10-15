#include"Complejo.h"

Complejo::Complejo(int real,int imag)
{
 re=real;
 im=imag;
}

Complejo Complejo::operator+(const Complejo &otroC) const
{
return Complejo(otroC.re+re,otroC.im+im);
}

//Complejo Complejo::operator+=(const Complejo &otroC)
//{
//    // TODO
//    return *this;
//}



/*** re + otroC.re
     this->im + otroC.im**/

ostream & operator<<(ostream &salida, const Complejo &complejo)
{
 salida<<complejo.re;
if (complejo.im<0)
 salida<<complejo.im<<"i";
else
 salida<<"+"<<complejo.im<<"i";
return salida;
}

// No es necesario.. Ya que no usa memoria dinamica.
// Complejo &Complejo::operator=(const Complejo &complejo)
//{
// re=complejo.re;
// im=complejo.im;
// return *this;
//}

Complejo Complejo::operator*(const Complejo &complejo) const
{
return Complejo(re*complejo.re - im*complejo.im , re*complejo.im + im*complejo.re);
}

Complejo operator*(const int &x, const Complejo &complejo)
{
return Complejo(x*complejo.re , x*complejo.im);
}

void Complejo:: setReal(int re)
{
    // Se usa this para referenciarse a la clase.
    // sino lo tiene se refiera a la variable local de la funcion
    this->re=re;
}
