#include "Boolean.h"

Boolean::Boolean()
{
    _valor=0;
}

Boolean::Boolean(int valor)
{
    _valor=valor;
    //this-> _valor = _valor
    /*this es una pseudovariable que accede a los miembros de la clase*/

}


int Boolean::getValue() const
{
    return _valor;
}

int Boolean::_and(Boolean &obj) const
{
    return ((_valor * obj._valor)>0 ? 1 : 0);
}

int Boolean::_or(Boolean &obj) const
{
    return ((_valor + obj._valor)>0 ? 1 : 0);
}

int Boolean::_not() const
{
    return (_valor == 0 ? 1 : 0);
}

Boolean Boolean::operator*(const Boolean &obj) const
{
    return Boolean (((_valor * obj._valor)>0 ? 1 : 0));
}

Boolean Boolean::operator+(const Boolean &obj) const
{
    return Boolean(((_valor + obj._valor)>0 ? 1 : 0));
}
