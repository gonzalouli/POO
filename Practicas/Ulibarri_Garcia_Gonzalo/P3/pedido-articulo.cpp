#include "pedido-articulo.hpp"

ostream& operator<<(ostream& os,const Pedido_Articulo::ItemsPedido &ip){

    os<<"PVP"<<"\t"<<"Cantidad"<<"\t"<<"Articulo"<<endl;
    float preciotot=0;

    for(auto iter= ip.begin();iter!=ip.end();iter++){
        os<<iter->second.precio_venta()<<"€\t"<<iter->second.cantidad()<<"\t";
        os<<iter->first->referencia();
        os<<" "<<iter->first->titulo()<<endl;
        preciotot=preciotot+(iter->second.precio_venta());
    }
    os<<"Total \t "<<preciotot<<" €"<<endl;

    return os;
}

ostream& operator<<(ostream& os,const Pedido_Articulo::Pedidos& p){

    os<<"[Pedidos: "<<p.size()<<"]"<<endl;
    os<<"========================================================================"<<endl;
    os<<" PVP"<<"\t"<<"Cantidad"<<"\t"<<"Fecha de venta"<<"\t\t\t"<<endl;
    double preciototal=0;
    int cantidadtotal=0;
    for(auto iter:p){
        os<<iter.second.precio_venta()<<" €"<<iter.second.cantidad()<<"\t"<<iter.first->fecha()<<endl;
        preciototal=preciototal+iter.second.cantidad()*iter.second.precio_venta();
        cantidadtotal=cantidadtotal+iter.second.cantidad();
    }
    os<<preciototal<<" € \t"<<cantidadtotal<<endl;

    return os;
}



ostream& Pedido_Articulo::mostrarDetallePedidos(ostream& os) {
     double precioTotal=0;

     for(auto iter =pedido_articulos.begin();iter!=pedido_articulos.end();iter++){
        os<<"Pedido num."<<iter->first->numero()<<endl;
        os<<"Cliente: "<<iter->first->tarjeta()->titular()->nombre()<<"Fecha: "<<iter->first->fecha();
        os<<iter->second;
        precioTotal=precioTotal+iter->first->importeTotal();
     }

     os<<"TOTAL VENTAS:\t\t "<<precioTotal;
     return os;

 }



ostream& Pedido_Articulo::mostrarVentasArticulos(ostream& os) {
    for(auto iter=articulos_pedido.begin(); iter!=articulos_pedido.end();iter++){
        os<<"Ventas de ["<<iter->first->referencia()<<"] "<<iter->first->titulo()<<endl;
        os<<iter->second<<endl;
    }
    return os;
}



bool OrdenaPedidos::operator()(Pedido& p1, Pedido& p2)const {

        return p1.numero() < p2.numero();
    
}





