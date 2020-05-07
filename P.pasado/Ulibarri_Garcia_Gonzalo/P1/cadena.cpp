

#ifndef CADENA_CPP
#define CADENA_CPP
#include "cadena.hpp" 


int Cadena::length(const Cadena &cadena){
	int tamano = strlen(cadena);
	return tamano;
}

Cadena operator+(Cadena &cad1, const Cadena &cad2){
Cadena temporal(cad1);
temporal= temporal+cad2;
return temporal;
}

Cadena& Cadena::operator=(const Cadena& cadena){
	tam_=cadena.tam_;
	delete [] s;
	s = new char[tam_ +1];
	strcpy(s,cadena.s);
}

Cadena::operator const char*() const { return s;}

Cadena& Cadena::operator +=(const Cadena& cadena) {
char* tempo = new char[tam_ + 1];
strcpy(tempo, s);
delete[] s;
tam_ += cadena.tam_;
s = new char[tam_ + 1];
strcpy(s, tempo);
strcat(s, cadena.s);
return *this;
}

bool operator <(const Cadena& a, const Cadena& b){
	return a<b ;
}

bool operator >(const Cadena& a, const Cadena& b){
	return a>b ;
}

bool operator ==(const Cadena& a, const Cadena& b){
	return a==b ;
}

bool operator !=(const Cadena& a, const Cadena& b){
	return !(a==b);
}

bool operator <=(const Cadena& a, const Cadena& b){
	return (a==b || a<b) ;
}

bool operator >=(const Cadena& a, const Cadena& b){
	return (a==b || a>b);
}


const char& Cadena::operator [](int indice) const { return s[indice]; }

Cadena Cadena::substring(int indice, int n) const {
	
	if(indice >= tam_ || n > tam_ - indice)
		throw Error("Error: Indice fuera de rango...");

}


std::basic_istream<char>& operator >>(std::basic_istream<char>& imp, Cadena& cadena) {
    
    char* palabra = new char[cadena.tamamax + 1];
    palabra[0] = '\0';
    
    imp.width(cadena.tamamax + 1);
    
    imp >> palabra;
    cadena.tam_ = strlen(palabra);
    cadena.s = new char[cadena.tam_ + 1];
    
    strcpy(cadena.s, palabra);
    
return imp;
}

std::basic_ostream<char>& operator <<(std::basic_ostream<char>& out, const Cadena& cadena) {
    out << cadena.cadstring();
    return out;
}



using namespace std;
int main(){

	cout << "Hola que tal";
	cout << "Adios";
return 0;
}

#endif 