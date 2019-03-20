#include <ctime>    
#ifndef FECHA_HPP_
#define FECHA_HPP_

class fecha{

public:

    explicit fecha(int dia=0, int mes = 0, int anno = 0 ): dia_(dia),mes_(mes),anno_(anno);
    fecha(const char *fecha);
    
    const dia() {return dia_;}
    const mes() {return mes_;}
    const anno() {return anno_}; 
    static int annomin =  1808;
    static int annomax =  2048;

    class Invalida{
    public:
        Invalida (const char * motivo);;
        const por_que(const char* invalida) {cout << "FALLO"; return motivo;};
    private: 
        const char * motivo;
    }

private:
    int dia_;
    int mes_;
    int anno_;
}




#endif