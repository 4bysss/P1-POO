CXX = g++
 
CPPFLAGS = -std=c++11 -g -DP1 -I../Tests-auto -I.
VPATH = ../Tests-auto:.

all: test-P1-auto test-fechacadena-consola

test-fechacadena-consola: test-fechacadena-consola.cpp fecha.cpp cadena.cpp
	$(CXX) $(CPPFLAGS) -c test-fechacadena-consola.cpp

test-P1-auto: test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o cadena.o fecha.o
	$(CXX) -o $@ $^

 test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o: \
      test-auto.hpp fecha.hpp cadena.hpp


fecha.o: fecha.cpp fecha.hpp
	$(CXX) $(CPPFLAGS) -c fecha.cpp

cadena.o: cadena.cpp cadena.hpp
	$(CXX) $(CPPFLAGS) -c cadena.cpp

clean:
	rm all
