OBJETOS = fecha.o cadena.o test-fechacadena-consola.o

CXX = g++

CPPLAGS = c++ -DP1 -I../Tests-auto -I.
CXXFLAGS = -std=c++1 -Wall -pedantic -g
VPATH = ../Tests-auto:.

all:test_F

test_F:test-fechacadena-consola.o fecha.o cadena.o
	${CXX} -o Final ${OBJETOS}
fecha.o:fecha.cpp fecha.hpp
	${CXX} -c fecha.cpp
cadena.o:cadena.cpp cadena.hpp
	${CXX} -c cadena.cpp
test-fechacadena-consola.o:test-fechacadena-consola.cpp
	${CXX} -DP1 -c test-fechacadena-consola.cpp
clean:
	del *.o *.exe

