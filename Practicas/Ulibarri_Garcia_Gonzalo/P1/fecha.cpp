


#include <iostream>
#include <ctime>    
#include <chrono>
#include "fecha.hpp"

#ifndef FECHA_CPP_
#define FECHA_CPP_

using namespace std;
///time_point<system_clock> hoy = system_clock::now();
///std::time_t tc = system_clock::to_time_t(hoy);
std::time_t tiempo_calendario = std::time(nullptr);
std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);
//int dia  = tiempo_descompuesto->tm_mday;
//int mes  = tiempo_descompuesto->tm_mon + 1;  
//int anno = tiempo_descompuesto->tm_year + 1900;

Fecha::Fecha(int dia, int mes, int anno):dia_(dia),mes_(mes),anno_(anno){
    time_t calendario = time(0);
    tm* tiempoDescompuesto = localtime(&calendario);
    if(dia_ == 0){
        //dia mes y año del sistema
    	dia_  = tiempo_descompuesto->tm_mday;
    	mes_  = tiempo_descompuesto->tm_mon + 1;
    	anno_ = tiempo_descompuesto->tm_year + 1900;
    }else{
        if( mes_ == 0){
            //mes y año del sistema
             mes_  = tiempo_descompuesto->tm_mon + 1;
             anno_ = tiempo_descompuesto->tm_year + 1900;
        }else{
            if(anno_ ==0)
               anno_ = tiempo_descompuesto->tm_year + 1900;
        }
    }

    if(dia_>31 || mes_>12){
        throw Invalida("Fecha imposible");
    }

    if(mes_==2 && dia_>29 || mes_==2 && dia_>28 && !(anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0))){
        throw Invalida("Febrero no puede tener esos dias");
    }

    if(anno_ < annomin || anno_ > annomax){
        throw Invalida("Superas los anios permitidos");
    }
}


Fecha::Fecha(const char *fecha){
int formato; 
int dia,mes,anno;
formato = sscanf( fecha, "%d/%d/%d",&dia,&mes,&anno );

if(formato != 3){ 
    throw Invalida("el formato no es de 3");
}else{
    if(anno_ < annomin || anno_ > annomax)
        throw Invalida("Superas los anios permitidos");
}
}

Fecha::operator const char*() const{

  setlocale(LC_ALL, "es_ES");
  static char fechaCad[36];

  tm t = {0, 0, 0, dia_, mes_ - 1, anno_ - 1900, 0, 0, 0};
  mktime(&t);
  int diasem = t.tm_wday;
  sprintf(fechaCad, "%s %d de %s del %d", Fecha::diasSemana[diasem], dia_, meses[mes_], anno_);

  return fechaCad;
}

tm hoy(const Fecha& fecha){
    tm tiempo;
    tiempo.tm_sec = 0; tiempo.tm_min = 0; tiempo.tm_hour = 0; 
    tiempo.tm_mday = fecha.dia();
    tiempo.tm_mon = fecha.mes()-1; 
    tiempo.tm_year = fecha.anno()-1900;
    tiempo.tm_wday = -1;
    tiempo.tm_yday = -1;
    tiempo.tm_isdst = -1;
    return tiempo;
}


const char* Fecha::cadena() const {
    static char* fecha = new char[250];
    char* diacad = new char[3];
    char* annocad = new char[5];
    
    strcpy(fecha, "");
    
    strcat(fecha, this->diaSeman() );
    strcat(fecha, " ");
    
    sprintf(diacad, "%02d", this->dia());
    strcat(fecha, diacad);
    
    strcat(fecha, " de ");
    strcat(fecha, Fecha::meses[this->mes() - 1]);
    strcat(fecha, " de ");
    
    sprintf(annocad, "%04d", this->anno());
    strcat(fecha, annocad);
    
    return fecha;
}


const char* Fecha::diaSeman() const noexcept{
    tm tiempo_descompuesto = hoy(*this);
    time_t tiempo_calendario = mktime(&tiempo_descompuesto);
    tm* tiempo_nuevo = localtime(&tiempo_calendario);
    switch(tiempo_nuevo->tm_wday){
        case 0: return "Lunes ";
        case 1: return "Martes ";
        case 2: return "Miercoles ";
        case 3: return "Jueves ";
        case 4: return "Viernes ";
        case 5: return "Sabado ";
        case 6: return "Domingo ";
        default: return "Dia erroneo";
    }
}

Fecha Fecha::operator++(){ 
    *this=*this-1;
    return *this;
}

Fecha Fecha::operator--(){
    *this=*this-1;
    return *this;
}

Fecha Fecha::operator++(int fecha){
    Fecha self(*this);
    ++(*this);
    return *this;
}

Fecha Fecha::operator--(int fecha){
    Fecha self(*this);
    --(*this);
    return *this;
}

std::istream& operator>> (std::istream& imp, Fecha& fech){
  char cadena[11]="";
  imp.getline(cadena,11);
  try{
    fech = Fecha(cadena);
  }catch(Fecha::Invalida& e){
    imp.setstate(std::ios::failbit);
    throw;
  }
  return imp;
}

std::ostream& operator<< (std::ostream& out, const Fecha& fech){
    out << fech.cadena();
    return out;
}

#endif



int main(){
  cout << "Hola que tal";
  cout << "Adios";

  return 0;
  }















/*
Fecha::operator const char*() const {
    char* s = new char[40];
    setlocale(LC_TIME, "");
    tm f = {};
    f.tm_mday = dia_;
    f.tm_mon = mes_ - 1;
    f.tm_year = anno_ - 1900;
    mktime(&f);
    strftime(s, 40, "%A %d de %B de %Y", &f);
    return s;
}
*/
