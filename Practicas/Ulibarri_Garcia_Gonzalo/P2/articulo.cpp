#include "articulo.hpp"

Articulo::Articulo(const Cadena& c,const Cadena& t,const Fecha& f, double p,unsigned ejemplares){
    codigo_=c;
    titulo_=t;
    fechapub=f;
    precio_=p;
    nejemplares=nejemplares;
}

ostream& operator<<(ostream& os,const Articulo& a)
{
    os<<"["<<a.referencia()<<"] "<<"\""<<a.titulo()<<"\""<<", "<<a.f_publi().anno()<<". "<<setprecision(2)<<a.precio()<<" €";
    return os;
}


