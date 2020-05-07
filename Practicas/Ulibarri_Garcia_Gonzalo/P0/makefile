#fuentes.cpp compilados con g++ -c 
#luego unidos los .o con g++ 
#make organiza y simplifica esta tarea para multiples ficheros fuentes
#cuando llamamos make, este busca el fichero makefile, y lo ejecuta
#tenemos 4 fuentes, fhola.cpp hola.cpp cosas.cpp adios.cpp
#<nombre programa objetivo> : <dependencias del ejecutable> #los .o

hola : hola.o fhola.o adios.o cosas.o
	g++ -o hola hola.o fhola.o adios.o cosas.o 
	#intro mas tabulador para escribir las ordenes para obtener el ojetivo

#reglas para los objetos .o

#<fich objetivo> : <ficheros de los que depende> 
hola.o : hola.cpp hola.hpp
	g++ -c hola.cpp
fhola.o : fhola.cpp
	g++ -c fhola.cpp
adios.o : adios.cpp 
	g++ -c adios.cpp
cosas.o : cosas.cpp
	g++ -c cosas.cpp

#con Make clean hacemos limpieza

clean:
	rm -f fhola.o hola.o cosas.o adios.o hola 
	#cuidado con rm -f *.o
--------------------------------------------------------empezamos a resumir----------------------------------------------------

#variable del sistema
OBJS = hola.o fhola.o cosas.o adios.o

CXX = c++

CPPFLAGS  =
	#ahora no se contempla ninguna, la usamos donde compilamos los CPP
CXXFLAGS = -std=c++11 -Wall 
	#estandar de cpp	#todos los avisos que puedas (Warning all)
LDFLAGS = 
	#le dice a las reglas implícitas qué opciones usar para el linkado
RM = rm 
	#programa para borrar, rm, o wipe, para borrar permanentemente
RMFLAGS=

@ = 
	#esta variable indica el objetivo de la regla, en este caso es hola
^ =
	#esta variable de entorno se sustituye como todos los objetivos de la regla (todas las dependencias),
	#o sea, en este caso como ${OBJS}
< =
	#se sustituye por la primera dependencia de la regla, en el caso de hola es hola.cpp.


hola: ${OBJS}
	${CXX} -o $@ ${LDFLAGS} $^
hola.o : hola.cpp hola.hpp
	${CXX} -c ${CPPFLAGS} ${CXXFLAGS} $< 
fhola.o : fhola.cpp
	${CXX} -c ${CPPFLAGS} ${CXXFLAGS} $<
adios.o : adios.cpp 
	${CXX} -c ${CPPFLAGS} ${CXXFLAGS} $<
cosas.o : cosas.cpp
	${CXX} -c ${CPPFLAGS} ${CXXFLAGS} $<


#ojo, todas las lineas son iguales, asi que podemos borarlas para compilar todo como

hola: ${OBJS}
	${CXX} -o $@ ${LDFLAGS} $^
hola.o : hola.cpp hola.hpp
fhola.o : fhola.cpp
adios.o : adios.cpp 
cosas.o : cosas.cpp
clean:
	rm -f ${OBJS} hola

#y como sabe el compilador que un .o depende de un .cpp, podemos eliminarlos, y nos quedaria como:

|-----------------------------------------------------------------------------------------------------|
|	hola: ${OBJS}																					  |
|		${CXX} -o $@ ${LDFLAGS} $^																	  |
|	hola: hola.hpp                                                                                    |
|		#hola.hpp esta incluido en hola.cpp, asi que dejamos la dependencia de hola.hpp en hola		  |
|---------------------------------------------------------------------------------------------------- |




#podemos cambiar las variables en la misma llamada al make poniendola detrás
#make CXX=g++ CXXFLAGS=-ansi
#asi el makefile no se modifica pero podemos cambiar la ejecucion del mismo



##SI QUEREMOS QUE HAGA OTRA COSA A PARTE DEL MAKE
#PODEMOS PONER UNA REGLA DENTRO DEL MAKEFLE CON UNA DEPENDENCIA
all : hola doc
#un ejemplo de esto es para generar la documentacion

doc:
	echo "estoy haciendo una documentacion cojonuda"

#ahora al realizar el make o el make all, realizará tambien la orden echo

