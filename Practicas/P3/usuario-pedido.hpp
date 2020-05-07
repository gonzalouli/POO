#ifndef USUARIO_PEDIDO_HPP
#define USUARIO_PEDIDO_HPP
#include <map>
#include <iomanip>
#include <set>
#include "usuario.hpp"
#include "pedido.hpp"
using namespace std;
class Pedido;

class Usuario_Pedido{

    public:

       	typedef set<Pedido*> Pedidos;
        typedef map<Usuario*,Pedidos> Usuarios;

        void asocia(Usuario& u,Pedido& p);
        void asocia(Pedido& p,Usuario& u);
        const Pedidos pedidos(Usuario& u)const ;
        const Usuario* cliente(Pedido& p)const ;

    private:

        Pedidos pedidos_;
        Usuarios usuarios_;

};



#endif