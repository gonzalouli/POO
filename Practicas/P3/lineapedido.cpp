#include "lineapedido.hpp"




    ostream& LineaPedido::operator<<(ostream& os,const LineaPedido& lp){
        os<<lp.precio_venta()<<" "<<"€"<<"\t"<<lp.cantidad()<<endl;
        return os;
    }
