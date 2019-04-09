#include <iostream>
#include <istream>
#include <ostream>
#include <ctime>   
#include <string.h> 
#include <cstring>
#include <iterator>
#ifndef CADENA_HPP_
#define CADENA_HPP_


class Cadena {



public:
	explicit Cadena(int tam = 0, char *c =nullptr ): tam_{tam},s{c} {
		s=new char[tam+1];
		for(int i=0;i<tam;i++)
			s[i] = c[i];
		
		s[tam] = '\0';

	}
	
	Cadena(): tam_(0) {
		s= new char[1];
		s[0] = '\0';
	}

	Cadena (const Cadena &cadena){
		tam_=strlen(cadena);
		s=new char[tam_+1];
		strcpy(s,cadena);
		
	}

	Cadena (Cadena&& cadena){
 	s = cadena.s;
 	tam_ = cadena.length(cadena);
	cadena.s = nullptr;
 	cadena.tam_ = 0;
 	cadena.s = new char[1];
 	cadena.s[0] = '\0';
	}

	Cadena(const char* s): tam_(strlen(s)) {
		this->s = new char[tam_ + 1];
		strcpy(this->s, s);
	}

	Cadena(const char* s, int n):tam_(n){
		if(n > strlen(s))
		tam_ = strlen(s);
		this->s = new char[tam_ + 1];
		for(int i = 0 ; i < tam_ ; i ++)
		this->s[i] = s[i];
		this->s[tam_] = '\0';
	}
	operator const char*() const;

	~Cadena() { delete [] s; }


	const char* cadstring() const { return s; }
	friend std::basic_istream<char>& operator >>(std::basic_istream<char>& imp, Cadena& c);
	
	int length(const Cadena& cadena);
	
	const char& operator [](int indice)const ;
	
	Cadena& operator =(const Cadena& cadena);
	Cadena& operator +=(const Cadena& cadena);
	
	Cadena substring(int indice = 0, int n = 0) const;
		
	class Error{
    		public:
        		Error (const char * motivo){motivo_ = motivo;}

        		const char *por_que() const {return motivo_;}
    		private: 
        		const char * motivo_;
    };

		typedef char* iterator;
        typedef const char* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        iterator begin() { return s; }
        iterator end() { return (s + tam_); }
        iterator begin() const { return s; }
        iterator end() const { return (s + tam_); }
        const_iterator cbegin() { return s; }
        const_iterator cend() { return (s + tam_); }
        const_iterator cbegin() const { return s; }
        const_iterator cend() const { return (s + tam_); }
        reverse_iterator rbegin() {
            return std::reverse_iterator<iterator> (s + tam_);
        }
        reverse_iterator rend() {
            return std::reverse_iterator<iterator> (s);
        };
        reverse_iterator rbegin() const {
            return std::reverse_iterator<iterator> (s + tam_);
        }
        reverse_iterator rend() const {
            return std::reverse_iterator<iterator> (s);
        };
        const_reverse_iterator crbegin() {
            return std::reverse_iterator<const_iterator> (s + tam_);
        }
        const_reverse_iterator crend() {
            return std::reverse_iterator<const_iterator> (s);
        }
        const_reverse_iterator crbegin() const {
            return std::reverse_iterator<const_iterator> (s + tam_);
        }
        const_reverse_iterator crend() const {
            return std::reverse_iterator<const_iterator> (s);
}	


private:
	static int tamamax;
		int tam_; ///tamaño
	char *s;
	


};

int Cadena::tamamax = 32;

bool operator +(const Cadena& cad1, const Cadena& cad2);
bool operator <(const Cadena& cad1, const Cadena& cad2);
bool operator >(const Cadena& cad1, const Cadena& cad2);
bool operator ==(const Cadena& cad1, const Cadena& cad2);
bool operator !=(const Cadena& cad1, const Cadena& cad2);
bool operator >=(const Cadena& cad1, const Cadena& cad2);
bool operator <=(const Cadena& cad1, const Cadena& cad2);

std::basic_ostream<char>& operator <<(std::basic_ostream<char>& os, const Cadena& c);

#endif //CADENA_HPP_