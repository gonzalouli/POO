#ifndef CADENA_HPP
#define CADENA_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <iterator>


class Cadena{

  public:
    explicit Cadena(size_t tam=0,const char c = ' ');
    Cadena(const char *c);
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

    Cadena substr(size_t pos,size_t tama)const;
    inline ~Cadena(){delete[] cadena_;}

    class Invalida
      	{
      	public:
      		Invalida(const char* er):error_(er){};
      		const char* por_que() const{return error_;};
      	private:
      		const char* error_;
      	};

	typedef char* iterator;
	typedef const char* const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator <const_iterator> const_reverse_iterator;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	const_iterator cbegin() const;
	const_iterator cend() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator crend() const;
	const_reverse_iterator crbegin() const;
	const_reverse_iterator rend() const;
	const_reverse_iterator rbegin() const;


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

//función hash a utilizar con contenedores desordenados de
//Cadena, unordered_[set|map|multiset|multimap].
namespace std{
  template<> 
  struct hash<Cadena> { 
    size_t operator() (const Cadena&cad) const
    { 
      hash<string> hs; 
      const char*p=cad.c_str(); 
      string  s(p); 
      size_t  res=hs(s);  
      return res; 
    }
  };
}
#endif
