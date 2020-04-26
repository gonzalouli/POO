#include <iostream>
#include "cadena.hpp"


Cadena::Cadena(int tam,char c)
{
  this.tam_=tam;
  this.cadena_ =new char[tam+1];
  for(int i=0;i<tam;i++)
    this.cadena_[i]=c;

  this.cadena_[i]='\0';c

}

Cadena::Cadena(int tam, const char* c)
{
  int i=0;
  while(c[i]!='\0')
  {
    this.tam_++;
    i++;
  }

  cadena_ = new char[this.tam_+1];

  for(int i=0;i<this.tam_;i++)
  {
    this.cadena_[i]=c[i];
  }

  this.cadena_[i]='\0';

}

Cadena::Cadena(const Cadena &c)
{
  int i=0;
  if(this!=&c)
  {
    this.tam_=c.tam;
    this.cadena_ = new char[c.tam+1];
    this.cadena_=c.cadena;
  }
  this.cadena_[tam_+1]='\0';
  delete[] c;
}


void Cadena::puts(const Cadena &c)
{
  int i=0;
  while(i<tam_){
    std::cout<<c.cadena[i];
    ++i;
  }
  std::cout<<"\n";
}


Cadena& Cadena::operator=(const Cadena &c)
{
  if(this!=&c){
      this.tam_=c.tam_;
      delete[] this.cadena_;
      this.cadena = new char[this.tam_+1];
      this.cadena_=c.cadena_;
  }

  this.cadena_[tam_+1]='\0';

  return *this;
}




void Cadena::operator+=(cont Cadena &c)
{

  int nuevotam = this.tam_+c.tam_+1;
  this.cadena_ = new char[nuevotam];
  int j=0;

  for(int i=this.tam_;i<nuevotam;i++)
  {
    this.cadena_[i]=c.cadena_[j];
  }

  this.cadena_[nuevotam]='\0';

}

Cadena& Cadena:operator+(const Cadena &c)
{
int tama=this.tam_+c.tam_;
Cadena cad(tama);

for(int i=0,j=0 ; i<tama ; i++)
{
  if(i<this.tam_)
    cad.cadena_[i]=this.cadena[i];
  else if(i>=this.tam_)
  {
    cad.cadena_[i]=c.cadena[j];
    j++;
  }
}
  cad.cadena_[tama+1]='\0';

  return cad;
}

bool Cadena::operator==(const Cadena &c)
{
  bool resultado = true;

  if(this.tam_==c.tam_)
  {
    for(int i=0;i<this.tam_ && resultado=true;i++){

      if(this.cadena_[i]!=c.cadena_[i])
        resultado=false;
    }
  }else resultado=false;

  return resultado;
}

bool operator!=(const Cadena &c)
{
  bool resultado = false;

  if(this.tam_==c.tam_)
  {
    for(int i=0;i<this.tam_ && resultado=false;i++){
      if(this.cadena_[i]!=c.cadena_[i])
        resultado=true;
    }
  }else resultado=true;

  return resultado;
}

bool Cadena::operator<(const Cadena &c)
{
  if(this.tam_<c.tam_)
    return true;
  else
  {
    return false;
  }
}

bool Cadena::operator>(const Cadena &c)
{
  if(this.tam_>c.tam)
    return true;
  else
  {
    return false;
  }
}

bool Cadena::operator<=(const Cadena &c)
{
  if(this.tam_<=c.tam_)
    return true;
  else
  {
    return false;

}

bool Cadena::operator>=(const Cadena &c)
{
  if(this.tam_>=c.tam_)
    return true;
  else
  {
  return false;

}

char Cadena::operator[](const int c)
{
 return this.cadena_[c];
}

char Cadena::at(int c)
{
  if(c>this.tam_)
    std::cout<<"ERROR, NO SE ENCUENTRA EL CARACTER. CORE DUMPED."<<endl;
  else
  {
      return this.cadena_[c];
  }

}

Cadena Cadena::substr(unsigned indice,unsigned tama)
{
  Cadena cad(tama);
  try{
    if(indice+tama>this.tam_)
      throw std::out_of_range;
    else
      for(unsigned i=indice,j=0; i<tama;indice++)
      {
        cad.cadena_[j]=this.cadena_[i];
        ++j;
      }
  }catch(int e)
    std::cout<<"código de error "<<e<<". Fuera de rango"<<endl;
}
