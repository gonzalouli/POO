#ifndef ARTICULO_HPP
#define ARTICULO_HPP
#include "usuario.hpp"
#include "tarjeta.hpp"
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

class Articulo {

    public:
        Articulo(const Cadena& c,const Cadena& t, const Fecha& f, double p,unsigned ejemplares = 0);

        inline const Cadena& referencia()const{return codigo_;}
        inline const Cadena& titulo()const{return titulo_;}
        inline const Fecha& f_publi()const{return fechapub;} 

        inline const double precio()const{return precio_;}
        inline double& precio(){return precio_;} 

        inline const unsigned stock()const{return nejemplares;}
        inline unsigned& stock(){return nejemplares;}




    private:
        Cadena codigo_,titulo_;
        Fecha fechapub;
        double precio_;
        unsigned nejemplares;

};

ostream& operator<<(ostream& os,const Articulo& a);

#endif