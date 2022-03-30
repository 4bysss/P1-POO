#include <string.h>
#include <ctype.h>
#include <iterator>
#include <iostream>//Temporal y solo para testeo
#include "cadena.hpp"




//Operadores de entrada/salida
std::istream& operator>>(std::istream& in, Cadena&cad){
	char fina[33];
	int i,j;
	in>>fina;
//	fflush(stdin);
	Cadena aux(fina);
	cad=aux;
	return in;
}



std::ostream& operator<<(std::ostream&on, Cadena&cad){
	std::cout<<cad.c_str();
	return on;
}



//Constructor por cadenas
Cadena::Cadena(const char*cad){
	tam_=strlen(cad);
	s_=new char[tam_+1];
	strcpy(s_,cad);
}



//Constructor predeterminado
Cadena::Cadena(unsigned n,char s){
	s_=new char[n+1];
	for(int i=0; i<n;i++){
		s_[i]=s;
	}
	s_[n]='\0';
	tam_=n;
};



//Constructor por copia
Cadena::Cadena(const Cadena& c){
	tam_=c.tam_;
	s_=new char[c.tam_+1];
	strcpy(s_,c.s_);
}



//Metodo length
unsigned int Cadena::length()const{
	return tam_;
}



//Sobrecarga del operador =
Cadena& Cadena::operator=(Cadena&&c){
	
	if(this!=&c){
		if(tam_!=0){
			delete[] s_;
		}
		s_=c.s_;
		tam_=c.tam_;
		c.s_=nullptr;
		c.tam_=0;
	}
	return *this;
}

Cadena::Cadena(Cadena&& c){
	s_=c.s_;
	tam_=c.tam_;
	c.tam_=0;
	c=nullptr;
}
Cadena& Cadena::operator=(Cadena&c){
	if(this!=&c){
		this->tam_=c.tam_;
		this->s_=new char[c.tam_+1];
		strcpy(s_,c.s_);
		s_[tam_]='\0';
	}
	return *this;
}


//Sobrecarga del operador ==
bool operator==(const Cadena&c1,const Cadena&c){
	return(strcmp(c1.s_,c.s_)==0);
}


//Sobrecarga del operador !=
bool operator!=(const Cadena&c1,const Cadena&c){
	return(!(c1==c));
}


//Sobrecarga del operador <
bool operator <(const Cadena&c1,const Cadena&c){
	return((strcmp(c1.s_,c.s_)>0));
}



//Sobrecarga del operador >
bool operator >(const Cadena&c1,const Cadena&c){
	return(c<c1);
}



//Sobrecarga del operador <=
bool operator <=(const Cadena&c1,const Cadena&c){
	return((c1==c)||(c1<c));
}


//Sobrecarga del operador >=
bool operator >=(const Cadena&c1,const Cadena&c){
	return(!(c1<c));
}



//Conversor de clase a cons char*
const char *Cadena::c_str()const{
	return(this->s_);
}



//Sobrecarga del operador []
char& Cadena::operator[](unsigned int i){
	return(this->s_[i]);
}



//Metodo at()
char Cadena::at(unsigned int i){
	if(i>this->tam_-1){
		throw(std::out_of_range("Fuera de los limites de la cadena"));
	}
	else{
		return(this->s_[i]);
	}
}



//Sobrecarga del operador +=
Cadena& Cadena::operator +=(const Cadena&c){
	
	char* s= new char[this->tam_+c.tam_+1];
	strcpy(s, this->s_);
	strcat(s,c.s_);
	s[this->tam_+c.tam_]='\0';
	if(this->tam_!=0){
		delete[]this->s_;
	}
	this->s_=new char[this->tam_+c.tam_+1];
	strcpy(this->s_,s);
	this->tam_+=c.tam_;
	delete []s;
	return *this;
}



//Sobrecarga del operador +;
Cadena Cadena::operator +(const Cadena&c){
	Cadena s(*this);
	s+=c;
	return s;
}



//Metodo subst
Cadena Cadena::substr(unsigned int in, unsigned int tam){
	if(in+tam>tam_-1){
		throw std::out_of_range("Sobrepasado rango de la cadena");
	}
	char ss[tam];
	for(int i=0;i<tam;i++){
		ss[i]=s_[i+in];
	}
	ss[tam]='\0';
	Cadena aux(ss);
	return aux;
}



//Destructor
Cadena::~Cadena(){
	delete[] s_;
}
void Cadena::mostrar(){
	int i=0;
	while(i<=tam_){
		std::cout<<s_[i]<<i<<std::endl;
		i++;
	}
}
