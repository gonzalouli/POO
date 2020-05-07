#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "fecha.hpp"

using namespace std;

std::time_t tiempo_calendario = std::time(nullptr);
std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);


Fecha::Fecha(int a,int m,int n):dia_(a),mes_(m),anio_(n){
    if(m==3 && !bisiesto(n) && a==29){
    a=28;printf("Año no bisiesto");}

    cambiarcero(*this);

}

Fecha::Fecha(int a,int m):dia_(a),mes_(m){
    anio_ = tiempo_descompuesto->tm_year+1900;
    if(m==3 && !bisiesto(anio_) && a==29){
        a=28;printf("Año no bisiesto");}
    
    cambiarcero(*this);

}


Fecha::Fecha(int a):dia_(a){
    anio_ = tiempo_descompuesto->tm_year+1900;
    mes_ = tiempo_descompuesto->tm_mon+1;
    if(mes_==3 && !bisiesto(anio_) && a==29){
        a=28;printf("Año no bisiesto");}
   
    cambiarcero(*this);

}

Fecha::Fecha():dia_(tiempo_descompuesto->tm_mday),mes_(tiempo_descompuesto->tm_mon+1),anio_(tiempo_descompuesto->tm_year+1900){}


Fecha& Fecha::copia( const Fecha& fech){

    ///if(this != &fech){
        dia_=fech.dia_;
        mes_=fech.mes_;
        anio_=fech.anio_;
    //}   
        cambiarcero(*this);


}

Fecha::Fecha(const char* c){
    char b;
    sscanf(c,"c""/",dia_,b);
    sscanf(c,"/""c""/",b,mes_,b);
    sscanf(c,"/""c",b,anio_);

    cambiarcero(*this);

}

void Fecha::cambiarcero(Fecha &fech){

    if(fech.anio_==0)
        fech.anio_=tiempo_descompuesto->tm_year;
    if(fech.dia_==0)
        fech.dia_=tiempo_descompuesto->tm_wday;
    if(fech.mes_==0)
        fech.mes_=tiempo_descompuesto->tm_mon;

}

bool Fecha::validarfech(){

    bool valida  = true;
    int meses30[]={4,6,9,11};
    int meses31[]={1,5,7,8,10,12};

    if( Fecha::anioMinimo>=anio_ || anio_>=Fecha::anioMaximo)
        valida = false;

    if( mes_>12 || mes_<0)
        valida = false;

    if( (dia_<0 || dia_>30) && meses30[0]==mes_ || meses30[1]==mes_ 
    ||meses30[2]==mes_ || meses30[3]==mes_)
        valida = false;

    if( (dia_<0 || dia_>31) && meses31[0]==mes_ || meses31[1]==mes_ 
    ||meses31[2]==mes_ || meses31[3]==mes_ || meses31[4]==mes_ || meses31[5]==mes_ 
    ||meses31[6]==mes_ || meses31[7]==mes_)
        valida = false;

    if( (dia_<0 || dia_>28) && mes_==2 && !bisiesto(anio_))
        valida = false;

    if( (dia_<0 || dia_>29) && mes_==2 && bisiesto(anio_))
        valida = false;

return valida;

}

Fecha& Fecha::operator=(const Fecha &fech){

    dia_=fech.dia_;
    mes_=fech.mes_;
    anio_=fech.anio_;

}

Fecha operator+(const Fecha &fech,int dia_s){
    
    Fecha f(fech);
    int mes_es30[]={4,6,9,11};
    int mes_es31[]={1,3,5,7,8,10,12};

    if( (f.dia_+dia_s>30 &&  mes_es30[0]== fech.mes_ || mes_es30[1]==fech.mes_ 
    ||mes_es30[2]==fech.mes_ || mes_es30[3]==fech.mes_ ) || 
    (f.dia_+dia_s>31 && mes_es31[0]==fech.mes_ || mes_es31[1]==fech.mes_ 
    ||mes_es31[2]==fech.mes_ || mes_es31[3]==fech.mes_ || mes_es31[4]==fech.mes_ || mes_es31[5]==fech.mes_ 
    ||mes_es31[6]==fech.mes_ || mes_es31[7]==fech.mes_ ) || 
    (f.dia_+dia_s>28 && fech.mes_==2 && !bisiesto(fech.anio_) ) || 
    (f.dia_+dia_s>29 && fech.mes_==2 && bisiesto(fech.anio_)))
    {

        if(fech.mes_<12) 
            f.mes_=fech.mes_+1;
        else
            f.anio_=fech.anio_+1;
    }
}

Fecha operator-(const Fecha &fech,int dia_s){

     Fecha f(fech);
    int meses30[]={4,6,9,11};
    int meses31[]={1,5,7,8,10,12};
    
    while(dia_s!=0){
        if( (f.dia_+dia_s<0) )
        {
            if(fech.mes_>1){
                f.mes_=fech.mes_-1;
                if(meses30[0]==f.mes_ || meses30[1]==f.mes_ 
                ||meses30[2]==f.mes_ || meses30[3]==f.mes_)
                f.dia_=30;
                if(meses31[0]==f.mes_ || meses31[1]==f.mes_ 
                ||meses31[2]==f.mes_ || meses31[3]==f.mes_ 
                ||meses31[4]==f.mes_ || meses31[5]==f.mes_
                ||meses31[6]==f.mes_ || meses31[7]==f.mes_)
                f.dia_=31;
                if(f.mes_==2 && bisiesto(f.anio_))
                    f.dia_=29;
                if(f.mes_==2 && !bisiesto(f.anio_))
                    f.dia_=28;

            }
            else
                f.anio_=fech.anio_-1;
                while(f.dia_+dia_s>0)
                    dia_s--;
                f.dia_=f.dia_-dia_s;
        }
    }
    if(!f.validarfech())
    throw Fecha::Invalida();
}

int Fecha::dia()const {return  dia_; }
int Fecha::mes()const {return mes_; }
int Fecha::anio()const {return anio_;}

void Fecha::fechaacadena(const Fecha &fech){

    cout << Fecha::diasSemana[zeller(fech)]<<" "<<fech.dia()<<" de "<<Fecha::mesesTotales[fech.mes]<<" de "<<fech.anio();

}


bool operator==(const Fecha &f1,const Fecha &f2){
    if(f1.dia()==f2.dia() && f1.mes()==f2.mes() && f1.anio()==f2.anio())
        return true;
    else
    {
        return false;
    }
    
}

void operator++(Fecha &fech){

    if(
    fech.dia_==29 && bisiesto(fech.anio_) && fech.mes_==2 ||
    fech.dia_==28 && !bisiesto(fech.anio_) && fech.mes_==2||
    fech.dia_==31 && (meses31[0]==fech.mes_ 
                ||meses31[1]==fech.mes_ 
                ||meses31[2]==fech.mes_ || meses31[3]==fech.mes_ 
                ||meses31[4]==fech.mes_ || meses31[5]==fech.mes_
                ||meses31[6]==fech.mes_ || meses31[7]==fech.mes_)

    || fech.dia_==30 && meses30[0]==fech.mes_ || meses30[1]==fech.mes_ 
                ||meses30[2]==fech.mes_ || meses30[3]==fech.mes_){
                if(fech.mes==12)
                    fech.anio_++;
                else
                {
                 fech.mes_++;       
                }
    }else
    {
        fech.dia_++;
    }
    

}

void operator--(Fecha &fech){

    if(fech.dia_==1 && fech.mes==1){
        fech.anio_--;
        fech.mes_=12;
        fech.dia_=31;
    }else{

        if(fech.dia_=1 && fech.mes==3 ){
            if(bisiesto(fech.anio()))
                fech.dia_==29;
            else
                fech.dia_==28;
        }else{
        
            if(fech.dia_=1){
                fech.mes_--;
                if(meses31[0]==fech.mes_ 
                ||meses31[1]==fech.mes_ 
                ||meses31[2]==fech.mes_ || meses31[3]==fech.mes_ 
                ||meses31[4]==fech.mes_ || meses31[5]==fech.mes_
                ||meses31[6]==fech.mes_ || meses31[7]==fech.mes_)
                    fech.dia_==31;
                else
                {
                    fech.dia==30;
                }
                
            }
        
        }
    }
}

bool operator<(const Fecha &f1,const Fecha &f2){

    if(f1.anio()<f2.anio())
    return true;
    else{
        if(f1.anio()==f2.anio()){
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

    if(f1.anio()>f2.anio())
    return true;
    else{
        if(f1.anio()==f2.anio()){
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
    if(f1.anio()<f2.anio())
    return true;
    else{
        if(f1.anio()==f2.anio()){
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
    if(f1.anio()>f2.anio())
        return true;
    else{
        if(f1.anio()==f2.anio()){
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
    int h,k,j;
    int d,m,a;

    if(f.mes<=2){
        m=f.mes+12;
        a=f.anio-1;
    }else{
        m=f.mes-2;
    }

    k=a%100;
    j=a/100;

    h=((700+((26*m-2)/10)+d+k+(k/4)+((j/4)+5*j))%7);
    return h;

}









