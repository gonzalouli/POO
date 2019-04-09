#include <ctime>    
#include <iostream>
#ifndef FECHA_HPP_
#define FECHA_HPP_
using namespace std;

class Fecha{

public:

    explicit Fecha(int dia=0, int mes = 0, int anno = 0 );
    Fecha(const char* cad); 
    operator const char*() const;
    

    Fecha operator--(int fecha);
    Fecha operator--();
    Fecha operator++(int fecha);
    Fecha operator++();
    
    const int dia() const noexcept {return dia_;}
    const int mes() const noexcept {return mes_;}
    const int anno() const noexcept {return anno_;} 
    static int annomin;
    static int annomax;

    class Invalida{
    public:
        Invalida (const char * motivo){motivo_=motivo; };
        const char *por_que(){ return motivo_;}
    private: 
        const char * motivo_;
    };

private:
    int dia_;
    int mes_;
    int anno_;
};

inline bool operator <(const Fecha& a, const Fecha& b){
return a<b;
}
inline bool operator !=(const Fecha& a, const Fecha& b) { return !(a == b); }
inline bool operator >(const Fecha& a, const Fecha& b){
return a>b;
}
inline bool operator <=(const Fecha& a, const Fecha& b){ return a == b || a < b; }
inline bool operator >=(const Fecha& a, const Fecha& b){ return a == b || b > a; }
inline bool operator ==(const Fecha& a, const Fecha& b){
    return a.dia() == b.dia() && a.mes() && b.mes() && a.anno() == b.anno();
}


int Fecha::annomin = 1808;
int Fecha::annomax = 2048;


#endif//FECHA_HPP_
