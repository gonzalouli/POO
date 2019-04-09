


#include <iostream>
#include <ctime>    
#include <chrono>
#include "fecha.hpp"

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
  static const char* semana[] = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"};
  static const char* mes[] = {"", "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "septiembre", "octubre", "noviembre", "diciembre"};
  mktime(&t);
  int diasem = t.tm_wday;
  sprintf(fechaCad, "%s %d de %s del %d", semana[diasem], dia_, mes[mes_], anno_);

  return fechaCad;
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
