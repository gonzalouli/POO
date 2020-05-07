#include "pedido.hpp"
using namespace std;


Pedido::Pedido(Usuario_Pedido& UP,Pedido_Articulo& PA, Usuario& u, Tarjeta& t, const Fecha& f){
    
    numeroPedido = numeroUltimoPedido_+1;
    tpago=&t;
    fechaPedido=f;
    importeTotal_=0;

    if(u.compra().empty())
		throw Vacio(&u);
	if(t.titular() != &u)
		throw Impostor(&u);
	if(t.caducidad() < f)
		throw Tarjeta::Caducada(t.caducidad());


	for(auto iter = u.compra().begin() ; iter != u.compra().end() ; iter ++){
        if(iter->second > iter->first->stock()){
            for(auto iter = u.compra().begin() ; iter != u.compra().end() ; iter ++)
                u.compra(*iter->first, 0);
                
            throw SinStock(iter->first);
        }    
			
	}
	
    if(u.compra().empty())
		throw Vacio(&u);  

	UP.asocia(*this, u);
	importeTotal_ = 0;

}


ostream& operator <<(ostream& os, const  Pedido& p) {

    os << "Núm. pedido: " << p.numero() << endl;
    os << "Fecha: " << p.fecha() << endl;
    os << "Pagado con: "<<p.tarjeta()->tipo() << " n.º: " << p.tarjeta()->numero() <<endl;
    os << "Importe: " << p.importeTotal() << " €"<< endl;
    
    return os;
}
































