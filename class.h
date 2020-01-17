#ifndef class_hpp
#define class_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Konto {
private:

	string imie;
	string nazwisko;
	string nrKonta;
	double stanKonta;

public:
	Konto();
	Konto(string i, string n, string nr);
	Konto(string imie, string nazwisko, string nrKonta, double stan);	 //konstruktor
	Konto(const Konto&);        //konstruktor kopiujďż˝cy
	Konto(string, string = "0000 0001 0003 9571", double = 0.0);	//konstruktor konwertujďż˝cy

	operator double() {   	//funkcja konwertujďż˝ca
		return stanKonta;
	}

	string wplata(double);
	string wyplata(double);
	void wyswietl();
	~Konto();

	void wpisz();
	void wypisz();
	void wypiszStanKonta();

	Konto operator+(const Konto&);           //przeciďż˝ďż˝enie operatora + dla klasy konto (po lewej stronie znaku + jest obiekt konto a po prawej liczba int)
	Konto operator-(const Konto&);           //przeciďż˝ďż˝enie operatora - dla klasy konto (po lewej stronie znaku - jest obiekt konto a po prawej liczba int)
	
	friend ostream& operator<< (ostream&, Konto const&); //////
	friend istream& operator>> (istream&, Konto&); ///////
};


#endif /* class_hpp */
