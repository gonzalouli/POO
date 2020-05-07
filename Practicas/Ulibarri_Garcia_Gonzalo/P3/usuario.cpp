#include "usuario.hpp"
#include <cstring>

using namespace std;

Usuario::Usuarios Usuario::listado;

Usuario::Usuario(const Cadena& id,const Cadena& nombre,const Cadena& apellidos, const Cadena& direccion, const Clave& clave)
{
    if(!listado.insert(id).second)
        throw Id_duplicado(id);
    else
    {
        this->identificador_=id;
        this->nombre_=nombre;
        this->apellidos_=apellidos;
        this->direccion_=direccion;
        this->clave_=clave;
    }
}

void Usuario::compra(Articulo& a, unsigned cant) {
    Articulos::iterator encontrado = misarticulos.find(&a);
    if(encontrado == misarticulos.end())
        misarticulos.insert(std::make_pair(&a, cant));
    else {
        if(cant == 0) 
            misarticulos.erase(encontrado);
        else 
            encontrado->second = cant;
    }
}

bool Clave::verifica(const char* passclaro)const
{
    
    return (strcmp(crypt(passclaro,passwd_.c_str()),passwd_.c_str())==0);  
}

Clave::Clave(const Clave& c){
    passwd_=c.clave();
}

Usuario::~Usuario()
{
    for(auto &iter : mistarjetas)
        iter.second->anula_titular();

    listado.erase(identificador_);
}



void Usuario::es_titular_de(Tarjeta& tarjeta) {
    if(tarjeta.titular() == this)
       mistarjetas[tarjeta.numero() ]= const_cast<Tarjeta*>(&tarjeta);
}

void Usuario::no_es_titular_de(Tarjeta &tarjeta){
    mistarjetas.erase(tarjeta.numero());
}


Clave::Clave(const char* passwd)
{   
    const char *valores = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";

    if(std::strlen(passwd)<5)
        throw Incorrecta(CORTA);
    else
    {
        char salt[2]={valores[dis(rd)],valores[dis(rd)]};     

        char* encriptada =crypt(passwd,salt);

        if( encriptada == nullptr)
            throw Incorrecta(ERROR_CRYPT);
        else
        {
            passwd_ = Cadena(encriptada);
        }
    }
}


ostream& operator<<(ostream& os, const Usuario& us){

    os<<us.id()<<" ["<<us.clave_.clave()<<" "<<us.nombre()<<" "<<us.apellidos()<<"\n"
    <<us.direccion()<<"\nTarjetas: \n";

    for(auto &iter : us.mistarjetas)
        os<<*iter.second<<endl;

    return os;
}



ostream& mostrar_carro(ostream& os,const Usuario& us){

    Usuario::Usuarios::iterator iter = us.listado.find(us.id());
    
    if(iter != us.listado.end()){
        os<<"Carrito de compra de "<<us.nombre()<<" "<<us.apellidos()
        <<" [Articulos: "<<us.n_articulos()<<"]"<<endl
        <<"Cant. Articulo"<<endl<<
        "======================================================================================="<<endl;

        if(us.n_articulos()==0)
            return os;  
        
        os << setw(65) << setfill('=') << '\n'  << setfill(' ');

        for(auto &iter : us.compra()){
            os << *iter.first <<endl;
        }
    }

    return os;

}



