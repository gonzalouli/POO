#include "usuario.hpp"
#include <cstring>

using namespace std;
/*
bool luhn(const Cadena& numero)
{
  size_t n = numero.length();
  size_t suma = 0;
  bool alt = false;
  for (int i = n - 1; i > -1; --i) {
    n = numero[size_t(i)] - '0';
    if (alt) {
      n *= 2;
      if (n > 9)
	n = (n % 10) + 1;
    }
    alt = !alt;
    suma += n;
  }
  return !(suma % 10);
}
*/

Tarjeta::TarjetasNoDuplic Tarjeta::cards;

Numero& Numero::operator=(const Cadena& num){
    numero_=num.c_str();
    return *this;
}


Numero::Numero(const Cadena& num){
    unsigned i,j;
    Cadena aux;
    while(i<num.length()){
        if(!isdigit(num[i]))
            throw Incorrecto(DIGITOS);

        if(!isspace(num[i])){
            aux[j]=num[i];
            ++j;++i;
        }    
        i++;
    }

    if(aux.length()<13 || aux.length()>19)
        throw Incorrecto(LONGITUD);

    if(!luhn(aux))
        throw Incorrecto(NO_VALIDO);

    numero_=aux;
}

Numero::operator const char*() const
{
	return numero_.c_str();
}



const bool operator<(const Numero& menor, const Numero &mayor)
{
    return strcmp(menor,mayor)==0;
}



Tarjeta::Tarjeta(const Numero& n, Usuario& u, const Fecha& f){

    if(!cards.insert(n).second){

        if( f<Fecha())
            throw Caducada(f);
        else
        cad=f;
        us=&u;
        titularfacial_=us->nombre()+" "+us->apellidos();
        us->es_titular_de(*this);
    
    }
}


const Tarjeta::Tipo Tarjeta::tipo()const

{   const char* aux=num.c_str();
    if(aux[0]==4)
        return VISA;
    if(aux[0]==5)
        return Mastercard;
    if(aux[0]==6)
        return Maestro;

    if(aux[0]==3 && (aux[1]==4 || aux[1]==7))
        return AmericanExpress;
    else
        return JCB;    
    
    return otro;

}

bool Tarjeta::activa(bool a)
{
    activa_=a;
    return activa_;
}

void Tarjeta::anula_titular() 
{ 
	const_cast<Usuario*&>(us) = nullptr; 
}





Tarjeta::~Tarjeta(){
        us->no_es_titular_de(*this);
}


ostream& operator<<(std::ostream& os,const Tarjeta &t){
    os<<"|"<<t.tipo()<<"|"<<"\n"
    <<"|"<<t.numero()<<"|"<<"\n"
    <<"|"<<t.titularfacial()<<"|"<<"\n"
    <<"|Caduca: "<<setfill('0')<<setw(2)<< t.caducidad().mes() << "/" << setw(2)
       << (t.caducidad().anno() % 100)<<setw(2)<<"|"<<"\n";

    return os;
}




const bool operator<(const Tarjeta& t1,const Tarjeta& t2){

    return strcmp(t1.numero(),t2.numero())==0;

}











