#ifndef TARJETA_HPP
#define TARJETA_HPP
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "usuario.hpp"
#include "tarjeta.hpp"
#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

class Usuario;

class Numero{

    public:
        Numero(){};
        Numero(const Cadena& num);
        Numero& operator=(const Cadena& num);
        operator const char*() const;
        const char* c_str()const{return numero_.c_str();}
        enum Razon {LONGITUD,DIGITOS,NO_VALIDO};

        class Incorrecto{
          public:
            Incorrecto(Razon razon):raz(razon){}
            Razon razon() const{return raz;}
          private:
              Numero::Razon raz;
        };


    private:
        Cadena numero_;
};

bool luhn(const Cadena& numero);
const bool operator<(const Numero& menor, const Numero &mayor);


class Tarjeta{


  public:

    typedef std::set<Numero> TarjetasNoDuplic; 

    enum Tipo {otro,VISA,Mastercard,Maestro,JCB,AmericanExpress};

    Tarjeta(const Numero& n,  Usuario& u,const Fecha& f);
    Tarjeta& operator=(const Tarjeta &tarjeta)=delete;
    Tarjeta(const Tarjeta &t)=delete;

    inline const Numero& numero()const{return num;} 
    inline const Usuario* titular()const{return us;} 
    inline const Fecha& caducidad()const{return cad;}
    inline const bool activa()const{return activa_;}
    inline const Cadena& titularfacial()const {return titularfacial_;}

    const Tipo tipo()const;

    bool activa(bool activa_=true);

    void anula_titular();

    class Caducada{
      public:
        Caducada(Fecha f):caduc(f){}
        const Fecha& cuando()const{return caduc;}
      private:
        Fecha caduc;
    };

    class Num_duplicado{
      public:
        Num_duplicado(Numero n):dupl(n){}
        const Numero& que()const {return dupl;}
      private:
        Numero dupl;
    };
    
    class Desactivada{};

    ~Tarjeta();

    


  private:
    Numero num;
    Usuario* us;
    Fecha cad;
    bool activa_;
    Cadena titularfacial_;

    static TarjetasNoDuplic cards;
   
    

};

const bool operator<(const Tarjeta& t1,const Tarjeta& t2);

std::ostream& operator<<(std::ostream& os,const Tarjeta &t);

#endif