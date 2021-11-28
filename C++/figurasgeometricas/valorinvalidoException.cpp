#include "valorinvalidoException.h"

const char * ValorInvalidoException::what()
{
    return "Error en el Valor No puede ser menor a CERO";
}
