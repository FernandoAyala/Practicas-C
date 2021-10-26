#include "funh.h"
Cadena::Cadena()
{
    pal=NULL;
}

Cadena::Cadena(const char* _pal)
{
    this->pal= new char[strlen(_pal)+1];
    strcpy(this->pal,_pal);
}

 Cadena::Cadena(const Cadena &obj)
 {
     this->pal= new char[strlen(obj.pal)+1];
     strcpy(this->pal,obj.pal);
 }

 Cadena::~Cadena()
 {
     delete[] pal;
 }



  Cadena Cadena::operator+(const Cadena &obj) const
  {
      Cadena sum;
      sum.pal= new char[strlen(pal) + strlen(obj.pal) +1];
      strcpy(sum.pal,pal);
      strcat(sum.pal,obj.pal);
      return sum;
  }

  istream & operator>>(istream &entrada,Cadena &obj)
  {
      char aux[200];
        entrada.getline(aux,200,'\n');
        delete []obj.pal;
      obj.pal=new char[strlen(aux)+1];
      strcpy(obj.pal,aux);
      return entrada;

  }

ostream & operator<<(ostream &salida,const Cadena &obj)
{
    salida<<obj.pal<<endl;
    return salida;
}

Cadena operator+(const char *_pal,const Cadena &obj)
{
    Cadena sum;
    sum.pal= new char[strlen(_pal) + strlen(obj.pal) + 1];
    strcpy(sum.pal,_pal);
    strcat(sum.pal,obj.pal);
    return sum;
}

Cadena & Cadena::operator=(const Cadena &obj)
{

        this->pal = new char[strlen(obj.pal) + 1];
        strcpy(this->pal, obj.pal);
    return *this;
}

int Cadena::longitud()
{
    return strlen(this->pal);
}
