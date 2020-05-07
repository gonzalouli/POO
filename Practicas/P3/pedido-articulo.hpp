#ifndef PEDIDO_ARTICULO_HPP
#define PEDIDO_ARTICULO_HPP
#include "articulo.hpp"
#include "pedido.hpp"
#include "lineapedido.hpp"
#include <iomanip>

class Pedido;
class LineaPedido;
class Articulo;

struct OrdenaPedidos
{   
	bool operator()( Pedido& p1, Pedido& p2) const;
};

struct OrdenaArticulos
{
	bool operator()( Articulo& art1,  Articulo& art2) const
	{
		return art1.referencia() < art2.referencia();
	}
};

class Pedido_Articulo{



    public:

        typedef std::map<Articulo*,LineaPedido,OrdenaArticulos> ItemsPedido;
        typedef std::map<Pedido*,ItemsPedido,OrdenaPedidos> PedArt;
        
        typedef std::map<Pedido*,LineaPedido,OrdenaPedidos> Pedidos;
        typedef std::map<Articulo*,Pedidos,OrdenaArticulos> ArtPed;

        void pedir(Pedido& p,Articulo& a,float precio,unsigned cantidad=1);
        void pedir(Articulo& a,Pedido& p,float precio,unsigned cantidad=1);

        const ItemsPedido& detalle(Pedido &p);
        Pedidos& ventas(Articulo& a);
        
        
        ostream& mostrarDetallePedidos(ostream& os) ;
        ostream& mostrarVentasArticulos(ostream& os) ; 



    private:
        PedArt pedido_articulos;
        ArtPed articulos_pedido;

};


ostream& operator<<(ostream& os,const Pedido_Articulo::ItemsPedido &ip);
ostream& operator<<(ostream& os,const Pedido_Articulo::Pedidos& p);





#endif


