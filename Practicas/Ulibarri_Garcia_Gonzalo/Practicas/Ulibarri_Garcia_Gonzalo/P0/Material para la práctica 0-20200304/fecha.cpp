#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "fecha.hpp"

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
        cambiarcero(*this);


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


void Fecha::fechaacadena(const Fecha &fech){

    cout << Fecha::diasSemana[zeller(fech)]<<" "<<fech.dia()<<" de "<<Fecha::mesesTotales[fech.mes()]<<" de "<<fech.anno();

}


Fecha Fecha::operator+(const int dias){

    Fecha f(*this);

    int queda=dias;
    while(queda!=0){
        switch(maxdiameses[f.mes()-1]){
            case 30:
                if(f.dia()+queda>maxdiameses[f.mes()-1]){
                    queda=queda-(maxdiameses[f.mes()-1]-f.dia());
                    f.mes_++;
                    f.dia_=1;
                }else
                {
                    f.dia_=f.dia()+queda;
                    queda=0;
                }
                break;
            case 31:
                if(f.mes()==12 && f.dia()+queda>31)
                    f.anno_++;
                else{
                    if(f.dia()+queda>maxdiameses[f.mes()-1]){
                       
                        queda=queda-(maxdiameses[f.mes()-1]-f.dia());
                         f.mes_++;
                         f.dia_=1;
                    }else{ 
                        f.dia_=f.dia()+queda;
                        queda=0;
                    }

                }
                break;
            default:
                if(bisiesto(f.mes()) && f.dia()+queda>29){
                    
                    queda=queda-(29-f.dia());
                   
                }else{
                    if (!bisiesto(f.mes()) && f.dia()+queda>28){
                    queda=queda-(28-f.dia());
                   

                    }
                    f.mes_++;
                    f.dia_=1;
                    f.dia_=f.dia()+queda;
                    queda=0;
                
                
                }
        }
    }
    return f;   
}

Fecha Fecha::operator-(const int dias){
    Fecha f(*this);
    int queda=dias;
    while(queda!=0){
        switch(maxdiameses[f.mes()-1]){
            
            case 31:
                if(f.dia()-queda<0){
                    if(f.mes()==1)
                        f.mes_=12;
                    else{
                        f.mes_--;
                    }
                    queda=queda-f.dia();
                    f.dia_=maxdiameses[f.mes()-1];
                }else{
                    if(bisiesto(f.anno()) && f.mes()==2)
                        f.dia_=29-queda;
                    else
                    f.dia_=maxdiameses[f.mes()-1]-queda;
                }
            break; 

            default: 
            if(f.dia_-queda<0){
                queda=queda-f.dia();
                f.mes_--;
                f.dia_=maxdiameses[f.mes()-1];
            }else
                f.dia_=maxdiameses[f.mes()-1]-queda;

        }

    }
    return f;
}

Fecha& Fecha::operator++(){
    if(mes_==12 && dia_==31){
        anno_++;
        dia_=mes_=1;
    }else{
        if(dia_==maxdiameses[mes_-1] || (bisiesto(anno_) && mes_==3 && dia_==29)){
            mes_++;
            dia_=1;
        }
        else
        {
            dia_++;
        }
        
    }
  return *this;
}

Fecha& Fecha::operator--(){
    if(mes_==1 && dia_==1 ){
        anno_--;
        mes_=12;
        dia_=maxdiameses[mes_-1];
        
    }else{
        if(dia_==0)
            mes_--;
        if(bisiesto(anno_) && mes_==3)
            dia_=29;
        else{
            dia_=maxdiameses[mes_-1];
            } 
    }
  return *this;

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

    if(f1==f2)
        return true;
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

bool operator>=(const Fecha &f1,const Fecha &f2){

    if(f1==f2)
        return true;
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
