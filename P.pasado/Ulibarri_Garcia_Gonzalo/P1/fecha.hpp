#include <ctime>    
#include <iostream>
#include <cstring>
#include <chrono>
#ifndef FECHA_HPP_
#define FECHA_HPP_
using namespace std;

class Fecha{

public:


    explicit Fecha(int dia=0, int mes = 0, int anno = 0 );
    Fecha(const char* fecha); 
    operator const char*() const;
    const char* cadena() const;

    Fecha operator--(int fecha);
    Fecha operator--();
    Fecha operator++(int fecha);
    Fecha operator++();
    
    const char *diaSeman() const noexcept;
    const int dia() const noexcept {return dia_;}
    const int mes() const noexcept {return mes_;}
    const int anno() const noexcept {return anno_;} 
    static int annomin;
    static int annomax;

    static const char* diasSemana[];
    static const char* meses[];

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
    tm hoy(const Fecha& F) const;
    int diaSemana() const noexcept;
};

const char * Fecha::diasSemana[7] = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"};
const char * Fecha::meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};


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

std::ostream& operator<< (std::ostream& out, const Fecha& fech);
std::istream& operator>> (std::istream& imp, Fecha& fech);

int Fecha::annomin = 1808;
int Fecha::annomax = 2048;


#endif//FECHA_HPP_
