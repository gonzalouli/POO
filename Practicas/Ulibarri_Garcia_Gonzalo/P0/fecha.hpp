#include <ctime>    
#ifndef FECHA_HPP_
#define FECHA_HPP_

std::time_t tiempo_calendario = std::time(nullptr);
std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);


class fecha{



public:

    friend fecha() : dia_{tiempo_descompuesto->tm_mday},mes_{tiempo_descompuesto->tm_mon + 1}
    ,anno_{tiempo_descompuesto->tm_year + 1900} {}; ///ctor predeterminado

    friend fecha(int dia,int mes,int anno) : dia_{dia},mes_{mes},anno_{anno} {}
    friend fecha(int dia, int mes) : dia_{dia},mes_{mes},anno_{tiempo_descompuesto->tm_year + 1900} {};
    friend fecha(int dia) : dia_{dia},mes_{tiempo_descompuesto->tm_mon + 1},anno_{tiempo_descompuesto->tm_year + 1900} {}
    friend fecha (const fecha& f);
    friend fecha(char *fech); 





private:
    int dia_;
    int mes_;
    int anno_;



}

#endif