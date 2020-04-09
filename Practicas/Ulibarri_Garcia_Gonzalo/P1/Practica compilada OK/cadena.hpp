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

    Cadena& operator=(const char*);
    Cadena& operator=(const Cadena &c);
    void operator+=(const Cadena &c);

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


        /*typedef char* iterator;
        typedef const char* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        iterator begin() { return cadena_; }
        iterator end() { return (cadena_ + tam_); }
        
        iterator begin() const { return cadena_; }
        iterator end() const { return (cadena_ + tam_); }
        
        const_iterator cbegin() { return cadena_; }
        const_iterator cend() { return (cadena_ + tam_); }
        
        const_iterator cbegin() const { return cadena_; }
        const_iterator cend() const { return (cadena_ + tam_); }
        
        reverse_iterator rbegin() { return std::reverse_iterator<iterator> (cadena_ + tam_); }
        reverse_iterator rend() { return std::reverse_iterator<iterator> (cadena_); };
        
        reverse_iterator rbegin() const { return std::reverse_iterator<iterator> (cadena_ + tam_); }
        
        reverse_iterator rend() const { return std::reverse_iterator<iterator> (cadena_); };
        
        const_reverse_iterator crbegin() { return std::reverse_iterator<const_iterator> (cadena_ + tam_); }
        const_reverse_iterator crend() { return std::reverse_iterator<const_iterator> (cadena_); }
        
        const_reverse_iterator crbegin() const { return std::reverse_iterator<const_iterator> (cadena_ + tam_); }
        const_reverse_iterator crend() const { return std::reverse_iterator<const_iterator> (cadena_); }
*/
    Cadena(Cadena&& cad);
  	Cadena& operator = ( Cadena&&);

  private:

    char* cadena_;
    size_t tam_;

};

Cadena operator+(const Cadena &c1,const Cadena &c2);
bool operator==(const Cadena &c1,const Cadena &c2);
bool operator!=(const Cadena &c1,const Cadena &c2);
bool operator<(const Cadena &c1,const Cadena &c2);
bool operator>(const Cadena &c1,const Cadena &c2);
bool operator<=(const Cadena &c1,const Cadena &c2);
bool operator>=(const Cadena &c1,const Cadena &c2);

std::ostream& operator<<(std::ostream& os,const Cadena &cadena);
std::istream& operator>>(std::istream& is, Cadena &cadena);

#endif
