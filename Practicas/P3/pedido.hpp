#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include "usuario.hpp"
#include "tarjeta.hpp"
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"

using namespace std;

class Usuario_Pedido;
class Pedido_Articulo;

class Pedido{


    public:

        Pedido(Usuario_Pedido& UP,Pedido_Articulo& PA,  Usuario& u, Tarjeta& t,  const Fecha& F=Fecha());

        int numero()const{return numeroPedido;}
        const Tarjeta* tarjeta()const{return tpago;}
        const Fecha& fecha()const{return fechaPedido;}
        float importeTotal()const{return importeTotal_;}
        static int n_total_pedidos(){return numeroUltimoPedido_;}

        class Vacio{
            public:
                Vacio(Usuario* usuario):usuario_(usuario){}
                Usuario& usuario() const{return *usuario_;}

            private:
               Usuario* usuario_;
        };


        class Impostor{
            public:
                Impostor(Usuario* usuario): impostor_(usuario){}
                Usuario& usuario() const{return *impostor_;}
            
            private:
                Usuario* impostor_;
        };


        class SinStock{
            public:
                SinStock(Articulo* articulo): articulo_(articulo){}
                Articulo& articulo() const{return *articulo_;}
                
            private:
                Articulo* articulo_;
        };

    private:
        int numeroPedido;
        const Tarjeta* tpago;
        Fecha fechaPedido;
        float importeTotal_;
        static int numeroUltimoPedido_;
};

ostream& operator <<(ostream& os, const Pedido& p);

#endif