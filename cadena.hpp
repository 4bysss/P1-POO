#include <string.h>
#include <iterator>
#include <iostream>//Temporal y solo para testeo
class Cadena{
	public:
explicit	Cadena(unsigned int n=0,const char=' ');
		Cadena(const char*);
		Cadena(const Cadena&);
		Cadena(Cadena &&);
		unsigned int length() const;
		Cadena& operator=(Cadena &&);
		Cadena& operator=(const Cadena&);
		const char* c_str() const;
		Cadena& operator += (const Cadena&);
		friend Cadena operator + (const Cadena&,const Cadena&);
		friend bool operator == (const Cadena&,const Cadena&);
		friend bool operator < (const Cadena&, const Cadena&);
		char& operator[](unsigned int);
		char operator[](unsigned int)const;
		char& at(int);
		char at(int)const;
		Cadena substr(int ,int )const;
		~Cadena();
		void mostrar();//Test
		typedef char* iterator;
		typedef char* const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		iterator begin()const{return s_;}
		iterator end()const{return s_+ length();}
		const_iterator cbegin()const{return s_;}
		const_iterator cend()const{return s_+ length();}
		reverse_iterator rbegin()const{return reverse_iterator(end());}
		reverse_iterator rend()const{return reverse_iterator(begin());}
		const_reverse_iterator crbegin()const{return const_reverse_iterator(cend());}
		const_reverse_iterator crend()const{return const_reverse_iterator(cbegin());}

	private:
		int tam_;
		char* s_;
};
std::istream& operator>>(std::istream& in, Cadena&cad);
std::ostream& operator<<(std::ostream& in,const Cadena&cad);
bool operator == (const Cadena&,const Cadena&);
bool operator != (const Cadena&,const Cadena&);
bool operator < (const Cadena&, const Cadena&);
bool operator > (const Cadena&, const Cadena&);
bool operator <= (const Cadena&,const Cadena&);
bool operator >= (const Cadena&,const Cadena&);
Cadena operator+ (const Cadena&,const Cadena&);
