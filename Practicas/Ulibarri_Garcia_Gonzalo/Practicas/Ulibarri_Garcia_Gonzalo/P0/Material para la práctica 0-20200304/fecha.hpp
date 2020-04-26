#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

   

class Fecha{

    const int maxdiameses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    const char * diasSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    const char * mesesTotales[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    const int cteMes[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
    const int cteMesBi[2]= {0,3};


    public:
      static const int AnnoMinimo=1902,AnnoMaximo=2037;

        explicit Fecha(int a=0,int m=0,int n=0);
        Fecha(const Fecha & fech);
        Fecha(const char* c);
        void cambiarcero(Fecha &fech);
        bool validarfech();
        Fecha& operator=(const Fecha &fech);
        inline Fecha hoy(){return Fecha();}

        Fecha operator+(int dias);
        Fecha operator-(int dias);
        Fecha& operator++();
        Fecha& operator--();

        inline int dia() const{return dia_;}
        inline int mes() const{return mes_;}
        inline int anno() const{return anno_;}
        void fechaacadena(const Fecha &fech);
        inline bool bisiesto(int a){return (a % 4 == 0 && !(a % 400 == 0 || a % 100 != 0));}

        class Invalida
      	{
      	public:
      		Invalida(const char* er);

      		const char* por_que() const;
      	private:
      		const char* error_;
      	};

    private:
        int dia_,mes_,anno_;
        bool treinta(int mes);

};


bool operator==(const Fecha &f1,const Fecha &f2);
bool operator<(const Fecha &f1,const Fecha &f2);
bool operator>(const Fecha &f1,const Fecha &f2);
bool operator>=(const Fecha &f1,const Fecha &f2);
bool operator<=(const Fecha &f1,const Fecha &f2);
bool operator!=(const Fecha &f1,const Fecha &f2);
int zeller(const Fecha &f);





#endif
