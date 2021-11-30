#include "valorinvalidoException.h"

const char * ValorInvalidoException::what() throw()
{
    return "Error en el Valor No puede ser menor a CERO";
}
