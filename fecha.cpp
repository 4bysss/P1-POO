#include <ctime>
#include <iostream>
#include <cassert>
#include <string.h>
#include <string>
#include<locale>
#include"fecha.hpp"
#define anno__min 1902
#define anno__max 2037
time_t t=time(nullptr);
tm* dt=localtime(&t);
struct tm* conv=localtime(&t);
char Fechaletra[81];

//Operadores de entrada salida
std::ostream& operator<<(std::ostream&on,const Fecha&fech){
	setlocale(LC_ALL, "spanish");
	conv->tm_year= fech.annno()- 1900;
	conv->tm_mon=fech.mees()-1;
	conv->tm_mday=fech.diia();
	mktime(conv);
	std::strftime (Fechaletra,80,"%A %d de %B de %Y" ,conv);
	std::cout<<Fechaletra;
	return on;
}



std::istream& operator>>(std::istream&in,Fecha&fech){
	char fechizador[80];
	std::cin>>fechizador;
	Fecha aux(fechizador);
	fech = aux;
	return in;
}



const char* Fecha::Invalida::por_que()const{return razon_;}
void Fecha::validar(){
	if(anno_<1902 || anno_>2037){
		throw Fecha::Invalida("Anno invalido");
	}
	else if(mes_==2){
		if((anno_%4==0) &&(anno_%400==0 || anno_%100!=0)){
			if(dia_>29){
				throw Fecha::Invalida("Dia invalido, anno_ bisiesto");
			}
		}
		else if (dia_>28){
			throw Fecha::Invalida("Dia no valido de febrero");
		}
	}
	else if (mes_>12){
		throw Fecha::Invalida("Mes invalido, maximo 12");
	}
	else if(mes_==2&&dia_>28){
		throw Fecha::Invalida("Dia no valido de febrero");
	}
	else if((mes_==4||mes_==6||mes_==9||mes_==11)&&dia_>30){
		throw Fecha::Invalida("Dia invalido, maximo 30");
	}
	else if (dia_>31){
		throw Fecha::Invalida("Dia inavalido, maximo 31");
	}
}


//Constructor por defecto y parametrizado
Fecha::Fecha(const int d, const int m, const int y){
	dia_=d;
	mes_=m;
	anno_=y;
	if(dia_==0){
		dia_=dt->tm_mday;
	}
	if(mes_==0){
		mes_=dt->tm_mon+1;
	}
	if(anno_==0){
		anno_=dt->tm_year+1900;
	}
	validar();
	
}



//Constructorr por copia
Fecha::Fecha(const Fecha&f){
	dia_=f.dia_;
	mes_=f.mes_;
	anno_=f.anno_;
	validar();
}

//Metodos observadores
int Fecha::diia()const{return dia_;}
int Fecha::mees()const{return mes_;}
int Fecha::annno()const{return anno_;}
//Funcion que muestra la Fecha de un objeto (a efectos de testeo);
void Fecha::mostrar(){
	std::cout<<dia_<<"-"<<mes_<<"-"<<anno_<<std::endl;
}



//Constructor parametrizado por strings
Fecha::Fecha(const char *f){
	int n=std::sscanf(f,"%d/%d/%d",&dia_,&mes_,&anno_);
	
	if(n==EOF){
		std::cout<<"ERROR";
	}
	validar();
	
}


Fecha& Fecha::operator=(const Fecha&f){
	dia_=f.dia_;
	mes_=f.mes_;
	anno_=f.anno_;
	return *this;
}



//Operador de conversion
char* Fecha::cadena(){
	setlocale(LC_ALL, "spanish");
	conv->tm_year= anno_ - 1900;
	conv->tm_mon=mes_-1;
	conv->tm_mday=dia_;
	mktime(conv);
	std::strftime (Fechaletra,80,"%A %d de %B de %Y" ,conv );
	return Fechaletra;
}



//Operador postncremento
Fecha Fecha::operator++(int n){
	Fecha aux;
	aux=*this;
	*this+=1;
	return aux;
}



//Operador preincremento
Fecha& Fecha::operator++(){
	int i=1;
	*this+=i;
	return *this;
}



//Operator postdecremento
Fecha Fecha::operator--(int n){
	Fecha aux;
	aux=*this;
	*this+=-1;
	return aux;
}



//Operador predecremento
Fecha& Fecha::operator--(){
	*this+=-1;
	return *this;
}



//Operador -=
Fecha& Fecha::operator-=(int n){
	*this+=-n;
	return *this;
}


//Operato +;
Fecha Fecha::operator+(int n){
	Fecha aux;
	aux=*this;
	aux+=n;
	return aux;
}



//Operator -
Fecha Fecha::operator-(int n){
	Fecha aux;
	aux=*this;
	aux+=-n;
	return aux;
}



//Operador +=
Fecha& Fecha::operator+=(int n){
	this->dia_+=n;
	conv->tm_year=anno_-1900;
	conv->tm_mon=mes_-1;
	conv->tm_mday=dia_;
	mktime(conv);
	anno_=conv->tm_year+1900;
	mes_=conv->tm_mon+1;
	dia_=conv->tm_mday;
	validar();
	return *this;
}



//Operador ==
bool Fecha::operator==(const Fecha&f){
	return(f.dia_==dia_&&f.mes_==mes_&&f.anno_==anno_);
}



bool Fecha::operator<(const Fecha&f){
	if(anno_<f.anno_){
		return true;
	}
	else if(anno_==f.anno_){
		if(mes_<f.mes_){
			return true;
		}
		else if(mes_==f.mes_){
			if(dia_<f.dia_){
				return true;
			}
		}
	}
	return false;
}



//Operador !=
bool Fecha::operator!=(const Fecha&f){
	return(!(*this==f));
}



//Operator >
bool Fecha::operator >(Fecha&f){
	return (f<*this);
}



//Operator <=
bool Fecha::operator <=(const Fecha&f){
	return (!(*this<f));
}



//Operator >=
bool Fecha::operator >=(Fecha&f){
	return (!(f<*this));
}

