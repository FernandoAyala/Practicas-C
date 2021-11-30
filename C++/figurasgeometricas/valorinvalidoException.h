#ifndef VALORINVALIDOEXCEPTION_H_INCLUDED
#define VALORINVALIDOEXCEPTION_H_INCLUDED

#include <exception>


class ValorInvalidoException : public std::exception
{
public:
    const char* what() throw();
};


#endif // VALORINVALIDOEXCEPTION_H_INCLUDED
