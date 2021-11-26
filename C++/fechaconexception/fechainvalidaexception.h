#ifndef FECHAINVALIDAEXCEPTION_H_INCLUDED
#define FECHAINVALIDAEXCEPTION_H_INCLUDED

#include <exception>


class FechaInvalidaException : public std::exception
{
public:
    const char* what() throw()
    {
        return "Error en la fecha";
    }
};

#endif // FECHAINVALIDAEXCEPTION_H_INCLUDED
