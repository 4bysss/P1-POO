class Fecha{
	public:
		//Fecha();
		Fecha(const Fecha&f);
		explicit Fecha(const int d=0, const int m=0,const int y=0);
		Fecha(char const*f);
		Fecha& operator=(const Fecha&f);
		Fecha& operator+=(int);
		Fecha& operator-=(int);
		Fecha& operator++();
		Fecha operator++(int);
		Fecha& operator--();
		Fecha operator--(int);
		Fecha operator+(int);
		Fecha operator-(int);
		bool operator<(const Fecha&);
		bool operator==(const Fecha&);
		bool operator>(Fecha&);
		bool operator!=(const Fecha&);
		bool operator<=(const Fecha&);
		bool operator>=(Fecha&);
		char* cadena();
		void mostrar();
		//prueba
		int aux();
		int diia()const;
		int mees()const;
		int annno()const;
		//~Fecha();
		class Invalida{
			public:
				Invalida(const char*a):razon_(a){};
				const char* por_que()const;
			private:
				const char* razon_;
		};
	private:
		int dia_,mes_,anno_;
		void validar();

};
std::ostream& operator<<(std::ostream&on,const Fecha&fech);
std::istream& operator>>(std::istream&in, Fecha&fech);
