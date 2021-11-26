#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
private:
    unsigned char _dia;
    unsigned char _mes;
    unsigned int _anio;
    bool fechaValida(unsigned char,unsigned char,unsigned int);
public:

    Fecha(unsigned char,unsigned char,unsigned int);
};

#endif // FECHA_H_INCLUDED
