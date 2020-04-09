
#include "cadena.hpp"
#include <iomanip>

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
Cadena::Cadena(char* c)
{ 
  /*int tam =0;
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
  }*/
  
  tam_=strlen(c);
  cadena_=new char[tam_+1];
  strcpy(cadena_,c);
  

  cadena_[tam_+1]='\0';

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

  cadena_[tam_+1]='\0';

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

  cadena_[tam_+1]='\0';

  return *this;
}

///____________________________________________________________________________
//sobrecarga del operador = para cadena-cadenaBajoNivel
Cadena& Cadena::operator=(const char *c)
{ 
 /* size_t i=0;
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
  */
  tam_=strlen(c);
  cadena_ =new char[tam_+1];
  strcpy(cadena_,c);
  cadena_[tam_+1]='\0';



  return *this;
}

///____________________________________________________________________________
//sobrecarga del operador =+ para cadena-cadena
void Cadena::operator+=(const Cadena &c)
{

  size_t nuevotam = tam_+c.tam_;
  tam_=nuevotam;
  cadena_ = new char[nuevotam+1];
  
  size_t j=0;
  for(size_t i=tam_+1;i<nuevotam;i++)
  {
    cadena_[i]=c.cadena_[j];
    j++;
  }

  cadena_[nuevotam+1]='\0';

}

///____________________________________________________________________________
//sobrecarga del operador + para cadena=cadena-cadena
Cadena operator+(const Cadena &c1,const Cadena &c2)
{
size_t tama=c1.length()+c2.length();
Cadena cad(tama,' ');

for(size_t i=0,j=0 ; i<tama ; i++)
{
  if(i<c1.length())
    cad[i]=c1[i];
  if(i>=c1.length())
  {
    cad[i]=c2[j];
    j++;
  }
}
  cad[tama+1]='\0';

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


