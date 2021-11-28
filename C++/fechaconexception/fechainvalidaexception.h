#ifndef FECHAINVALIDAEXCEPTION_H_INCLUDED
#define FECHAINVALIDAEXCEPTION_H_INCLUDED

#include <exception>


class FechaInvalidaException : public std::exception
{
public:
    const char* what();
};

#endif // FECHAINVALIDAEXCEPTION_H_INCLUDED
