#include <string.h>
#include <iterator>
#include <iostream>//Temporal y solo para testeo
class Cadena{
	public:
		Cadena(unsigned int n=0,char=' ');
		Cadena(const char*);
		Cadena(const Cadena&);
		Cadena(Cadena&&);
		unsigned int length() const;
		Cadena& operator=(Cadena&&);
		Cadena& operator=(Cadena&);
		const char* c_str() const;
		Cadena& operator += (const Cadena&);
		Cadena operator + (const Cadena&);
		bool operator == (Cadena&);
		bool operator != (Cadena&);
		bool operator !=(const char*) const;
		bool operator ==(const char*) const;
		bool operator < (Cadena&);
		bool operator > (Cadena&);
		bool operator <= (Cadena&);
		bool operator >= (Cadena&);
		char& operator[](unsigned int);
		char at(unsigned int);
		Cadena substr(unsigned int ,unsigned int );
		~Cadena();
		void mostrar();//Test
		typedef char* iterator;
		typedef char* const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		iterator begin(){return &s_[0];}
		iterator end(){return &s_[tam_+1];}
		const_iterator cbegin()const{return &s_[0];}
		const_iterator cend()const{return &s_[tam_+1];}
		reverse_iterator rbegin(){return reverse_iterator(end());}
		reverse_iterator rend(){return reverse_iterator(begin());}
		const_reverse_iterator crbegin()const{return const_reverse_iterator(cend());}
		const_reverse_iterator crend()const{return const_reverse_iterator(cbegin());}

	private:
		unsigned tam_;
		char* s_;
};
std::istream& operator>>(std::istream& in, Cadena&cad);
std::ostream& operator<<(std::ostream& in, Cadena&cad);
bool operator == (const char*, Cadena&);
bool operator != (const char*, Cadena&);
