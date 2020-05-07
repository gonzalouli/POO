#ifndef CADENA_HPP
#define CADENA_HPP


class Cadena{

  public:

    explicit Cadena(size_t tam=0,const char c = ' ');
    explicit Cadena(size_t tam,char *c);

    Cadena(const Cadena &c);
    void puts(const Cadena &c);
    inline size_t length() const{return tam_;}

    Cadena& operator=(const char*);
    Cadena& operator=(const Cadena &c);
    void operator+=(const Cadena &c);

    char operator[](const size_t c);
    char at(size_t c);
    char at(size_t c) const;
    Cadena substr(size_t pos,size_t tama);
    inline ~Cadena(){delete[] cadena_;}
  
    Cadena operator+(const Cadena &c);
    bool operator==(const Cadena &c);
    bool operator!=(const Cadena &c);
    bool operator<(const Cadena &c);
    bool operator>(const Cadena &c);
    bool operator<=(const Cadena &c);
    bool operator>=(const Cadena &c);
    class Invalida
      	{
      	public:
      		Invalida(const char* er);

      		const char* por_que() const;
      	private:
      		const char* error_;
      	};

    
  private:

    char* cadena_;
    size_t tam_;




};



#endif
