#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <string>
using namespace std;

    const int meses30[4]={4,6,9,11};       
    const int meses31[7]={1,3,5,7,8,10,12};
    
class Fecha{

    static const int anioMinimo=1902,anioMaximo=2037;
    const char * Fecha::diasSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    const char * Fecha::mesesTotales[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    const int Fecha::cteMes[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
    const int Fecha::cteMesBi[2]= {0,3};
  

    public:
        Fecha(int a,int m,int n){if (!validarfech()){ throw Invalida::Invalida(); delete this;}}
        Fecha(int a,int m){if (!validarfech()){ throw Invalida::Invalida();; delete this;}}
        explicit Fecha(int a){if (!validarfech()){ throw Invalida::Invalida(); delete this;}}
        Fecha();
        Fecha &copia(const Fecha & fech);
        Fecha(const char* c);
        void cambiarcero(Fecha &fech);
        bool validarfech();
        Fecha& operator=(const Fecha &fech);
        inline Fecha hoy(){Fecha();}
        class Invalida{};
        
        friend Fecha operator+(const Fecha &fech,int dias);
        friend Fecha operator-(const Fecha &fech,int dias);
        friend void operator++(Fecha &fech);
        friend void operator--(Fecha &fech);
                friend bool operator==(const Fecha &f1,const Fecha &f2);

        friend bool operator<(const Fecha &f1,const Fecha &f2);
        friend bool operator>(const Fecha &f1,const Fecha &f2);
        friend bool operator>=(const Fecha &f1,const Fecha &f2);
        friend bool operator<=(const Fecha &f1,const Fecha &f2);
        friend bool operator!=(const Fecha &f1,const Fecha &f2);

        int dia() const;
        int mes() const;
        int anio() const;
        void fechaacadena(const Fecha &fech);

    private:

        int dia_,mes_,anio_;
        

};

bool bisiesto(int a){a % 4 == 0 && !(a % 400 == 0 || a % 100 != 0);}
int zeller(const Fecha &f);





#endif