#include <iostream>
#include <ctime>
#include <time.h>
#include <cassert>
#include <stdlib.h>
#include "fecha.hpp"
#include <iomanip>

using namespace std;


std::time_t tiempo_calendario = std::time(nullptr);
std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);

Fecha::Fecha(int a,int m,int n):dia_(a),mes_(m),anno_(n){
  if(a==0)
    dia_=tiempo_descompuesto->tm_mday;
  if(m==0)
    mes_=tiempo_descompuesto->tm_mon + 1;
  if(n==0)
    anno_= tiempo_descompuesto->tm_year + 1900;
   if (!validarfech()){
    throw Invalida("Fecha no valida");
  }
    if(m==3 && !bisiesto(n) && a==29){
    a=28;
    printf("El año introducido no bisiesto");
  }

}


Fecha::Fecha( const Fecha& fech){
    if(this != &fech){
        dia_=fech.dia();
        mes_=fech.mes();
        anno_=fech.anno();
    }

}

Fecha::Fecha(const char* c){
    int validaconversion;
    validaconversion=sscanf(c,"%2d/%2d/%4d",&dia_, &mes_, &anno_);
    if(validaconversion==3){
      *this=Fecha(dia_,mes_,anno_);
      if(!validarfech()) throw Invalida("Fecha no valida");
    }else
      throw Invalida("Conversion imposible");

}

const char* Fecha::Invalida::por_que() const
	{
		return error_;
	}


bool Fecha::validarfech(){

    bool valida  = true;
    tm t = {};
    t.tm_mday= dia_;
    t.tm_mon=mes_;
    t.tm_year=anno_;
    mktime(&t);
    if(t.tm_mday!=dia_){throw Invalida("error en el dia");valida=false;}
    if(t.tm_mon!=mes_) {throw Invalida("error en el mes");valida=false;}
    if(t.tm_year!=anno_) {throw Invalida("error en el anio");valida=false;}
    if(( !bisiesto(mes_) && dia_==29) ||  (treinta(mes_) && dia_==31)){ 
      throw Invalida("No es un anio bisiesto, no puede tener 29 dias");
      valida=false;
    }

    if(AnnoMinimo>anno_ || AnnoMaximo<anno_){
      throw Invalida("Fuera de rango");
      valida=false;
    }

return valida;

}


const char * Fecha::fechaacadena() const {
    char* cadena=new char[100];
    cout << Fecha::diasSemana[zeller(*this)]<<" "<<dia()<<" de "<<Fecha::mesesTotales[mes()]<<" de "<<anno();
    sprintf(cadena,"%s %d de %s de %d",Fecha::diasSemana[zeller(*this)],dia(),Fecha::mesesTotales[mes()],anno());
    return cadena;
}


Fecha Fecha::operator+(int dias) const{

    Fecha f(*this);
    f+=dias;
    return f;

}


Fecha &Fecha::operator+=(int dias){

    struct tm fecha = {};
    fecha.tm_mday = dia_;
    fecha.tm_mon = mes_ - 1;
    fecha.tm_year = anno_ - 1900;
    
    time_t aux = mktime(&fecha) + dias;
    tm* tiempoDescompuesto = localtime(&aux);
    
    int dia = tiempoDescompuesto->tm_mday;
    int mes = tiempoDescompuesto->tm_mon + 1;
    int anno = tiempoDescompuesto->tm_year + 1900;
    
    *this = Fecha(dia, mes, anno);
    
    return *this;  
}


Fecha Fecha::operator-( int dias)const {
    Fecha f(*this);
    f+=-dias;
    return f;
}



Fecha& Fecha::operator-=(int dias){

    *this+=-dias;
    return *this;
}


Fecha& Fecha::operator++(){
    *this+=1;
    return *this;
}


Fecha& Fecha::operator--(){
    *this-=1;
    return *this;

}


Fecha Fecha::operator++(int){
    Fecha aux(*this);
    ++aux;
    return aux;
}


Fecha Fecha::operator--(int){
    Fecha aux(*this);
    --aux;
    return aux;
}


bool operator==(const Fecha &f1,const Fecha &f2){
    if(f1.dia()==f2.dia() && f1.mes()==f2.mes() && f1.anno()==f2.anno())
        return true;
    else
    {
        return false;
    }
}




bool operator<(const Fecha &f1,const Fecha &f2){

    if(f1.anno()<f2.anno())
    return true;
    else{
        if(f1.anno()==f2.anno()){
            if(f1.mes()<f2.mes())
                return true;
            else{
                if(f1.mes()==f2.mes()){
                    if(f1.dia()<f2.dia())
                    return true;
                }
            }
        }
    }
    return false;
}



bool operator>(const Fecha &f1,const Fecha &f2){

    if(f1.anno()>f2.anno())
    return true;
    else{
        if(f1.anno()==f2.anno()){
            if(f1.mes()>f2.mes())
                return true;
            else{
                if(f1.mes()==f2.mes()){
                    if(f1.dia()>f2.dia())
                    return true;
                }
            }
        }
    }
    return false;
}



bool operator<=(const Fecha &f1,const Fecha &f2){

    return (f1<f2 || f1==f2);

}


bool operator>=(const Fecha &f1,const Fecha &f2){

    return (f1>f2 || f1==f2);

}


bool operator!=(const Fecha &f1,const Fecha &f2){
    return !(f1==f2);
}


int zeller(const Fecha &f){
    
    int h,a,m,y;

    a=(14-f.mes())/12;
    y=f.anno()-a;
    m=f.mes()+12*a-2;

   h= ( f.dia() +   y   +   y/4 -   y/100   +   y/400   +   (31*m)/12   )   %7;
    return h;
}


bool Fecha::treinta(const int mes){
  if(mes==4 || mes==6 || mes==9 || mes==11)
    return true;
  else
    return false;
}



ostream& operator<<(ostream& os,const Fecha &fecha)
{
    os<<fecha.fechaacadena();
    return os;
}

istream& operator>>(istream& is, Fecha &fecha)
{   char *c= new char[11];

    is>>setw(11)>>c; //tomamos el tamaño de is a 11
    int d,m,a; 
    sscanf(c,"%2d/%2d/%4d",&d,&m,&a); //tomamos el dia mes y año de la fecha en cuestion

    try{
        
        Fecha fecha(d,m,a);
        std::cout<<"La fecha es:"<<fecha<<std::endl;

    }catch(const Fecha::Invalida &I){
        if(!fecha.validarfech()){
            std::cerr<<"LA FECHA NO ES VALIDA"<<std::endl;
            std::cerr<<I.por_que()<<std::endl;
        }
    }

    return is;
}





