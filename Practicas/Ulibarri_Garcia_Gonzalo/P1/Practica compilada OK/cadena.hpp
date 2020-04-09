#ifndef CADENA_HPP
#define CADENA_HPP
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <iterator>


class Cadena{

  public:

    explicit Cadena(size_t tam=0,const char c = ' ');
    explicit Cadena(char *c);
    Cadena(const Cadena &c);
    const char* c_str() const ;
    inline size_t length() const{return tam_;}

    Cadena& operator=(const char* c);
    Cadena& operator=(const Cadena &c);
    Cadena& operator+=(const Cadena &c);
    Cadena& operator+=(const char *c);
    Cadena operator+(const Cadena &c)const;
    Cadena operator+(const Cadena &c);
    char& operator[](const size_t c);
    char operator[](const size_t c) const ;
    char& at(size_t c);
    char at(size_t c) const;

    Cadena substr(size_t pos,size_t tama);
    inline ~Cadena(){delete[] cadena_;}

    class Invalida
      	{
      	public:
      		Invalida(const char* er);
      		const char* por_que() const;
      	private:
      		const char* error_;
      	};

  
  typedef char* iterator; 
	typedef const char* const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    iterator begin() {return cadena_;} 
    const_iterator cbegin() const {return cadena_;}
    reverse_iterator rbegin() {return std::reverse_iterator<iterator>(end());}
    const_reverse_iterator crbegin()const {return std::reverse_iterator<const_iterator>(cend());}


    iterator end() {return (cadena_+tam_);}
    const_iterator cend() const{return (cadena_+tam_);}
    reverse_iterator rend() {return std::reverse_iterator<iterator>(begin());}
    const_reverse_iterator crend()const {return std::reverse_iterator<const_iterator>(cbegin());}

    Cadena(Cadena&& cad);
  	Cadena& operator = ( Cadena&&);

  private:

    char* cadena_;
    size_t tam_;

};

bool operator==(const Cadena &c1,const Cadena &c2);
bool operator!=(const Cadena &c1,const Cadena &c2);
bool operator<(const Cadena &c1,const Cadena &c2);
bool operator>(const Cadena &c1,const Cadena &c2);
bool operator<=(const Cadena &c1,const Cadena &c2);
bool operator>=(const Cadena &c1,const Cadena &c2);

std::ostream& operator<<(std::ostream& os,const Cadena &cadena);
std::istream& operator>>(std::istream& is, Cadena &cadena);

#endif
