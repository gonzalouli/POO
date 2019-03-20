#include <iostream>
#include <ctime>    
#include "fecha.hpp"

using namespace std;
using namespace std::chrono;time_point<system_clock> hoy = system_clock::now();
std::time_t tc = system_clock::to_time_t(hoy);
std::time_t tiempo_calendario = std::time(nullptr);std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);
//int dia  = tiempo_descompuesto->tm_mday;
//int mes  = tiempo_descompuesto->tm_mon + 1;  
//int anno = tiempo_descompuesto->tm_year + 1900;

Fecha::Fecha(int dia, int mes, int anno):dia_(dia),mes_(mes),anno_(anno) {

    if(dia_ == 0){
        //dia mes y año del sistema
    	dia_  = tiempo_descompuesto->tm_mday;
    	mes_  = tiempo_descompuesto->tm_mon + 1;
    	anno_ = tiempo_descompuesto->tm_year + 1900;
    }else{
        if(mes() == 0){
            //mes y año del sistema
             mes_  = tiempo_descompuesto->tm_mon + 1;
             anno_ = tiempo_descompuesto->tm_year + 1900;
        }else{
            if(anno_ ==0){
               anno_ = tiempo_descompuesto->tm_year + 1900;

            }
        }
    }

}

Fecha::Fecha(const char *fecha){
int formato; 
int dia,mes,anno;
formato = sscanf( fecha, "%d/%d/%d",&dia,&mes,&anno );

if(formato ¡= 3){ throw Invalida("el formato no es de 3");




}






int main(){


}