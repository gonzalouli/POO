#include <iostream>
#include "cadena.hpp"

//constructor de una cadena con un caracter
Cadena::Cadena(size_t tam,char c)
{ size_t i;
  tam_=tam;
  cadena_ =new char[tam+1];
  for( i=0;i<tam;i++)
    cadena_[i]=c;

  cadena_[i]='\0';

}

///____________________________________________________________________________
//constructor de una cadena con una cadena de caracteres a bajo nivel determinada
Cadena::Cadena(size_t tam,char* c)
{
  size_t i=0;
  while(c[i]!='\0')
  {
    tam++;
    i++;
  }
  tam_=tam;
  cadena_ = new char[tam+1];

  for(size_t i=0;i<tam;i++)
  {
    cadena_[i]=c[i];
  }

  cadena_[i]='\0';

}

///____________________________________________________________________________
//constructor de copia de cadena a cadena
Cadena::Cadena(const Cadena &c)
{

  if(this!=&c)
  {
    tam_=c.tam_;
    cadena_ = new char[c.tam_+1];
    cadena_=c.cadena_;
  }
  cadena_[tam_+1]='\0';
  

}

///____________________________________________________________________________
//visualiza la cadena pasada por parametro
void Cadena::puts(const Cadena &c)
{
  size_t i=0;
  while(i<tam_){
    std::cout<<c.cadena_[i];
    ++i;
  }
  std::cout<<"\n";
}

///____________________________________________________________________________

//sobrecarga del operador = para cadena-cadena
Cadena& Cadena::operator=(const Cadena &c)
{
  if(this!=&c){
      tam_=c.tam_;
      delete[] cadena_;
      cadena_ = new char[tam_+1];
      cadena_=c.cadena_;
  }

  cadena_[tam_+1]='\0';

  return *this;
}

///____________________________________________________________________________
//sobrecarga del operador = para cadena-cadenaBajoNivel
Cadena& Cadena::operator=(const char *c)
{ size_t i=0;
    size_t tama;
    while(c[i]!='\0')
    {
      tama++;;
      i++;
    }
      tam_=tama;
      delete[] cadena_;
      cadena_ = new char[tam_+1];
    i=0;
      while(c[i]!='\0')
      {
        cadena_[i]=c[i];
        i++;
      }
      cadena_[tama+1]='\0';
  

  return *this;
}

///____________________________________________________________________________
//sobrecarga del operador =+ para cadena-cadena
void Cadena::operator+=(const Cadena &c)
{

  size_t nuevotam = tam_+c.tam_+1;
  cadena_ = new char[nuevotam];
  size_t j=0;

  for(size_t i=tam_;i<nuevotam;i++)
  {
    cadena_[i]=c.cadena_[j];
  }

  cadena_[nuevotam]='\0';

}

///____________________________________________________________________________
//sobrecarga del operador + para cadena=cadena-cadena
Cadena Cadena::operator+(const Cadena &c)
{
size_t tama=tam_+c.tam_;
Cadena cad(tama,' ');

for(size_t i=0,j=0 ; i<tama ; i++)
{
  if(i<tam_)
    cad.cadena_[i]=cadena_[i];
  if(i>=tam_)
  {
    cad.cadena_[i]=c.cadena_[j];
    j++;
  }
}
  cad.cadena_[tama]='\0';

  return cad;
}

///____________________________________________________________________________
//sobrecarga del operador == para cadena-cadena
bool Cadena::operator==(const Cadena &c)
{
  bool resultado = true;

  if(tam_==c.tam_)
  {
    for(size_t i=0; i<tam_ && resultado==true;i++){

      if(cadena_[i]!=c.cadena_[i])
        resultado=false;
    }
  }else resultado=false;

  return resultado;
}

///____________________________________________________________________________
//sobrecarga del operador != cadena-cadena
bool Cadena::operator!=(const Cadena &c)
{
  bool resultado = false;

  if(tam_==c.tam_)
  {
    for(size_t i=0;i<tam_ && resultado==false;i++){
      if(cadena_[i]!=c.cadena_[i])
        resultado=true;
    }
  }else resultado=true;

  return resultado;
}

///____________________________________________________________________________
//sobrecarga del pperador < para cadena-cadena
bool Cadena::operator<(const Cadena &c)
{
  if(tam_<c.tam_)
    return true;
  else
  {
    return false;
  }
}

///____________________________________________________________________________
// sobrecarga del operador > para cadena-cadena
bool Cadena::operator>(const Cadena &c)
{
  if(tam_>c.tam_)
    return true;
  else
  {
    return false;
  }
}

///____________________________________________________________________________
//sobrecarga del operador <= para cadena-cadena
bool Cadena::operator<=(const Cadena &c)
{
  if(tam_<=c.tam_)
    return true;
  else
  
    return false;

}

///____________________________________________________________________________
//sobrecarga del operdor >= para cadena-cadena
bool Cadena::operator>=(const Cadena &c)
{
  if(tam_>=c.tam_)
    return true;
  else
    return false;

}

///____________________________________________________________________________
// sobrecarga del operador [] para objtener el caracter iesimo de una cadena
char Cadena::operator[](const size_t i)
{
 return cadena_[i];
}

///____________________________________________________________________________
//sobrecarga del operador [] (at) pero en este caso si superamos el tamaño
// de la cadena salta un error
char Cadena::at(size_t c) const
{ char caracter;
  try{

    if(c<tam_){
      throw "ERROR, NO SE ENCUENTRA EL CARACTER. CORE DUMPED.";
      caracter='@';
    }else
    {
        caracter=cadena_[c];
      
    }
    
  }catch(int e){}

  return caracter;
}


///____________________________________________________________________________
//funcion substr que nos muestra una subcadena de la cadena pasada implicitamente
Cadena Cadena::substr(size_t indice,size_t tama)
{ 
  Cadena cad(tama,' ');
  try{
    if(indice+tama>tam_)
      throw Invalida("Fuera de rango");
    else
      for(unsigned i=indice,j=0; i<tama;indice++)
      {
        cad.cadena_[j]=cadena_[i];
        ++j;
      }
  }catch(int e){
    std::cout<<"código de error "<<e<<". Fuera de rango"<<std::endl;
  }
  return cad;
}

///____________________________________________________________________________
