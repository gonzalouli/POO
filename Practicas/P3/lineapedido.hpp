#ifndef LINEA_PEDIDO_HPP
#define LINEA_PEDIDO_HPP
#include "iostream"



class LineaPedido{

    public:

        
        explicit LineaPedido(float precioventa,unsigned cantidadvendida=1);
        const float precio_venta()const {return precioventa;}
        const unsigned cantidad() const {return cantidadvendida;}

        friend ostream& operator<<(ostream& os,const LineaPedido& lp);


    private:
        float precioventa;
        unsigned cantidadvendida;

};





#endif