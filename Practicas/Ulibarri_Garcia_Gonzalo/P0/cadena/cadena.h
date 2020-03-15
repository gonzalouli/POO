#ifndef CADENA_H
#define CADENA_H





class Cadena{

  public:

    explicit Cadena(int tam,char c = ' ');
    explicit Cadena(int tam = 0,char *c = nullptr);
    Cadena(const Cadena &c);
    void puts(const Cadena &c);
    Cadena& operator=(const Cadena &c);
    void operator+=(const Cadena &c);
    Cadena operator+(const Cadena &c);
    bool operator==(const Cadena &c);
    bool operator!=(const Cadena &c);
    bool operator<(const Cadena &c);
    bool operator>(const Cadena &c);
    bool operator<=(const Cadena &c);
    bool operator>=(const Cadena &c);
    inline char operator[](const int c);
    char at(int c);
    Cadena substr(unsigned i,unsigned tama);



  private:

    char* cadena_;
    int tam_;
  
  


};




#endif