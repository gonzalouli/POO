#include "usuario-pedido.hpp"

void Usuario_Pedido::asocia(Usuario& u,Pedido& p)
{

    pedidos_.insert(&p);
    if(usuarios_.find(&u) != usuarios_.end()) {
        usuarios_.find(&u)->second.insert(&p);
    } else {
        Pedidos pedido;
        pedido.insert(&p);
        usuarios_.insert(make_pair(&u, pedido));
    }
}

void Usuario_Pedido::asocia(Pedido& p, Usuario& u)
{
    this->asocia(u,p);
}

const Usuario_Pedido::Pedidos Usuario_Pedido::pedidos(Usuario &u) const
{
    return usuarios_.find(&u)->second;
}

const Usuario* Usuario_Pedido::cliente(Pedido& p) const
{
    assert(pedidos_.find(&p) != pedidos_.end());
        return p.tarjeta()->titular();
}
