CXX = g++
CXXFLAGS = -std=c++11 -Wall -pedantic -Wextra -Werror -pedantic-errors -g
DTA = ../Tests-auto
CPPFLAGS = -I$(DTA) -I. -DP0
VPATH = $(DTA):.

all: test-auto test-consola

test-consola: fecha.o cadena.o test-P0-consola.o
	$(CXX) $(LDFLAGS) -o $@ $^

test-auto: test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o fecha.o cadena.o
	$(CXX) $(LDFLAGS) -o $@ $^

test-caso0-fecha-auto.o: test-auto.hpp fct.h

test-caso0-cadena-auto.o: test-auto.hpp fct.h

fecha.o:fecha.hpp

cadena.o: cadena.hpp

test-P0-consola.o: test-P0-consola.cpp fecha.o cadena.o

clean: 
	$(RM) test-P0-consola *.o
