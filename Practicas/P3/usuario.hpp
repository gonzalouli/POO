#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "articulo.hpp"
#include "tarjeta.hpp"
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <random>


using namespace std; 

class Tarjeta;
class Numero;
class Articulo;

static random_device rd;
static uniform_int_distribution <std::size_t> dis(0, 63);


class Clave
{
    public:

    Clave(const char* pass="");
    Clave(const Clave &c);
    inline const Cadena& clave()const {return passwd_;};
    operator const char*() const{return passwd_.c_str();}
    enum Razon {CORTA,ERROR_CRYPT};

    bool verifica(const char* pasclaro)const;

    class Incorrecta{
        public:

            Incorrecta(const Razon r):razon_(r){}
            Razon razon()const{return razon_;}
            
        private:
            Clave::Razon razon_;
    };

    private:
        Cadena passwd_;
};


class Usuario
{

    public:

        typedef std::unordered_map<Articulo*,unsigned> Articulos; 
        typedef std::map<Numero, Tarjeta*> Tarjetas;
        typedef std::unordered_set<Cadena> Usuarios;
        static Usuarios listado;

        Usuario( const Cadena&, const Cadena&, const Cadena&,  const Cadena&,  const Clave&);


        Usuario(const Usuario& us)=delete;
        Usuario& operator=(const Usuario& us)=delete;

       
        inline const Cadena& id()const{return identificador_;}
        inline const Cadena& nombre()const{return nombre_;}
        inline const Cadena& apellidos()const{return apellidos_;}
        inline const Cadena& direccion()const{return direccion_;} 
        
        inline const Tarjetas tarjetas()const{return mistarjetas;}
        inline const Tarjetas& tarjetas(){return mistarjetas;}
        inline const Articulos& compra() { return misarticulos; }
        inline const Articulos& compra()const { return misarticulos; }
        void compra(Articulo& a, unsigned cant=1);


        void es_titular_de(Tarjeta &tarjeta);
        void no_es_titular_de(Tarjeta &tarjeta);

        inline size_t n_articulos()const{return misarticulos.size();}

        ~Usuario();

        friend ostream& operator<<(ostream& os, const Usuario& us);


        class Id_duplicado{
            public:
                Id_duplicado(Cadena id):id_error(id){}
                inline const Cadena& idd()const{return id_error;}
            private:
                Cadena id_error;
        };

    private:

        Cadena identificador_,nombre_, apellidos_,direccion_;
        Clave clave_;
        Tarjetas mistarjetas;
        Articulos misarticulos;
};


ostream& mostrar_carro(ostream& os,const Usuario& us);


#endif