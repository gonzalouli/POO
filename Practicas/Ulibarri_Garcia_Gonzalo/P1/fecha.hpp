#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha{

    const char * diasSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    const char * mesesTotales[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
      

    public:
      static const int AnnoMinimo=1902,AnnoMaximo=2037;
      
        explicit Fecha(int a=0,int m=0,int n=0);
        Fecha(const Fecha& fech);
        Fecha(const char* c);

        bool validarfech();
        Fecha& operator=(const Fecha &fech);
        inline Fecha hoy_(){return Fecha();}

        Fecha& operator+=(int dias);
        Fecha& operator-=(int dias);
        Fecha operator+(int dias)const; 
        Fecha operator-(int dias)const;
        Fecha& operator++();
        Fecha& operator--();
        Fecha operator++(int );
        Fecha operator--(int );

        inline int dia() const{return dia_;}
        inline int mes() const{return mes_;}
        inline int anno() const{return anno_;}
        
        const char* cadena() const;
        inline bool bisiesto(int a){return (a % 4 == 0 && !(a % 400 == 0 || a % 100 != 0));}

        friend bool operator==(const Fecha &f1,const Fecha &f2);
        friend bool operator<(const Fecha &f1,const Fecha &f2);
        friend bool operator>(const Fecha &f1,const Fecha &f2);
        friend bool operator>=(const Fecha &f1,const Fecha &f2);
        friend bool operator<=(const Fecha &f1,const Fecha &f2);
        friend bool operator!=(const Fecha &f1,const Fecha &f2);

        class Invalida
      	{
      	public:
      		Invalida(const char* er):error_(er){}
      		const char* por_que() const;
      	private:
      		const char* error_;
      	};

    private:
        int dia_,mes_,anno_;
        bool treinta(int mes);

};

int zeller(const Fecha &f);

ostream& operator<<(ostream& os,const Fecha &fecha);
istream& operator>>(istream& is, Fecha &fecha);




#endif
