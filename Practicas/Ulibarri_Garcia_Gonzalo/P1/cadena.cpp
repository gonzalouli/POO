
#include "cadena.hpp"
#include <iomanip>
#include <cstring>

using namespace std;

//constructor de una cadena con un caracter
Cadena::Cadena(size_t tam,char c)
{ size_t i;
  tam_=tam;
  cadena_ =new char[tam+1];
  for( i=0;i<tam;i++)
    cadena_[i]=c;

  cadena_[tam]='\0';

}


///____________________________________________________________________________
//constructor de una cadena con una cadena de caracteres a bajo nivel determinada
Cadena::Cadena(const char* c)
{ 
  tam_=strlen(c);
  cadena_=new char[tam_+1];
  strcpy(cadena_,c);
  

  cadena_[tam_]='\0';

}



///____________________________________________________________________________
//constructor de copia de cadena a cadena
Cadena::Cadena(const Cadena &c)
{

  if(this!=&c)
  {
    tam_=c.tam_;
    cadena_ = new char[tam_+1];
    strcpy(cadena_,c.cadena_);
  }

  cadena_[tam_]='\0';

}

///____________________________________________________________________________
//visualiza la cadena pasada por parametro
const char* Cadena::c_str() const 
{
  return cadena_;
}



///____________________________________________________________________________

//sobrecarga del operador = para cadena-cadena
Cadena& Cadena::operator=(const Cadena &c)
{
  if(this!=&c){
      tam_=c.tam_;
      delete[] cadena_;
      cadena_ = new char[tam_+1];
      strcpy(cadena_,c.cadena_);
  }

  cadena_[tam_]='\0';

  return *this;
}

///____________________________________________________________________________
//sobrecarga del operador = para cadena-cadenaBajoNivel
Cadena& Cadena::operator=(const char *c)
{ 
 
  tam_=strlen(c);
  cadena_ =new char[tam_+1];
  strcpy(cadena_,c);
  cadena_[tam_]='\0';

  return *this;
}

///____________________________________________________________________________
//sobrecarga del operador =+ para cadena-cadena y char
Cadena& Cadena::operator+=(const Cadena &c)
{
  size_t nuevotam = tam_+c.tam_;
  
  cadena_ = new char[nuevotam+1];
  *this=substr(0,tam_);
  strcat(cadena_,c.c_str());

  tam_=nuevotam;
  cadena_[tam_]='\0';
  return *this;
}


Cadena& Cadena::operator+=(const char *c)

{ size_t len =strlen(c);
  cadena_=new char[tam_+len+1];
  *this=substr(0,tam_);//copia todo menos el '\0'
  
  tam_+=len; //coloca su tamaño adecuadamente
  strcat(cadena_,c); //coloca la siguiente cadena concatenada a cadena_
  cadena_[tam_]='\0'; //pone el fin de linea
  return *this;
}




///____________________________________________________________________________
//sobrecarga del operador + para cadena=cadena-cadena
Cadena Cadena::operator+(const Cadena &c)
{
  Cadena cad(*this);
  cad+=c;
  return cad;
}

Cadena Cadena::operator+(const Cadena &c)const
{
  Cadena cad(*this);
  cad+=c;
  return cad;
}

///____________________________________________________________________________
//sobrecarga del operador == para cadena-cadena
bool operator==(const Cadena &c1,const Cadena &c2)
{

  if(strcmp(c1.c_str(),c2.c_str())==0)
      return true;
  else 
      return false;

  
}

///____________________________________________________________________________
//sobrecarga del operador != cadena-cadena
bool operator!=(const Cadena &c1,const Cadena &c2)
{
  if(strcmp(c1.c_str(),c2.c_str())!=0)
      return true;
  else 
      return false;
}

///____________________________________________________________________________
//sobrecarga del pperador < para cadena-cadena
bool operator<(const Cadena &c1,const Cadena &c2)
{
  if(c1.length()<c2.length())
    return true;
  else
  {
    return false;
  }
}

///____________________________________________________________________________
// sobrecarga del operador > para cadena-cadena
bool operator>(const Cadena &c1,const Cadena &c2)
{
  if(c1.length()>c2.length())
    return true;
  else
  {
    return false;
  }
}

///____________________________________________________________________________
//sobrecarga del operador <= para cadena-cadena
bool operator<=(const Cadena &c1,const Cadena &c2)
{
  if(c1.length()<=c2.length())
    return true;
  else
    return false;

}

///____________________________________________________________________________
//sobrecarga del operdor >= para cadena-cadena
bool operator>=(const Cadena &c1,const Cadena &c2)
{
  if(c1.length()>=c2.length())
    return true;
  else
    return false;

}

///____________________________________________________________________________
// sobrecarga del operador [] para objtener el caracter iesimo de una cadena
char& Cadena::operator[](const size_t i)
{
 return cadena_[i];
}

char Cadena::operator[](const size_t i) const 
{
 return cadena_[i];
}

///____________________________________________________________________________
//sobrecarga del operador [] (at) pero en este caso si superamos el tamaño
// de la cadena salta un error
char Cadena::at(size_t c) const
{
    if(c<tam_)
      throw "ERROR, NO SE ENCUENTRA EL CARACTER. FUERA DE RANGO.";
   
  return cadena_[c];
}

char& Cadena::at(size_t c)
{
  if(c>tam_)
      throw "ERROR, NO SE ENCUENTRA EL CARACTER. FUERA DE RANGO.";

  return cadena_[c];
}


///movimientos
Cadena::Cadena(Cadena&& c)
{     tam_=c.tam_;
      cadena_=new char[c.tam_+1];
      strcpy(cadena_,c.cadena_);
      c.tam_ = 0;
      c.cadena_ = nullptr;
}

Cadena& Cadena::operator=(Cadena&& c)
{
 	cadena_ = c.cadena_;
 	tam_ = c.tam_;
 	c.cadena_ = nullptr;
 	c.tam_ = 0;
 	return *this;
}



///____________________________________________________________________________
//funcion substr que nos muestra una subcadena de la cadena pasada implicitamente
Cadena Cadena::substr(size_t indice,size_t tama)const
{ 
  if(indice+tama>tam_)
    throw Invalida("Tamanio invalido");
 
  char* cad=new char[tama+1];
  for(unsigned i=indice,j=0; i<tama;i++)
  {
    cad[j]=cadena_[i];
    ++j;
  }
  cad[tama]='\0';
  
  
  return Cadena(cad);
}

///____________________________________________________________________________


std::ostream& operator << (std::ostream& os, const Cadena& cadena)
{
	os << cadena.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, Cadena &cadena)
{   
  char c[33]="";
  is >> setw(33) >> c;  
  cadena = Cadena(c);  

    return is;
}


Cadena::iterator Cadena::begin(){
  return cadena_;
}

Cadena::const_iterator Cadena::begin() const{
  return cadena_;
}

Cadena::iterator Cadena::end(){
  return cadena_ + tam_;
}

Cadena::const_iterator Cadena::end() const{
  return cadena_ + tam_;
}

Cadena::const_iterator Cadena::cbegin() const{
  return cadena_;
}

Cadena::const_iterator Cadena::cend() const{
  return cadena_ + tam_;
}

Cadena::reverse_iterator Cadena::rbegin(){
  return reverse_iterator(end());
}

Cadena::reverse_iterator Cadena::rend(){
  return reverse_iterator(begin());
}

Cadena::const_reverse_iterator Cadena::crend() const{
  return const_reverse_iterator(cbegin());
}

Cadena::const_reverse_iterator Cadena::crbegin() const{
  return const_reverse_iterator(cend());
}

Cadena::const_reverse_iterator Cadena::rend() const{
  return const_reverse_iterator(cbegin());
}

Cadena::const_reverse_iterator Cadena::rbegin() const{
  return const_reverse_iterator(cend());
}


