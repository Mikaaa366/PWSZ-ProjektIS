#include "class.h"
#include <iostream>
#include <sstream>

using namespace std;

string doubleToString(double x) {
    stringstream ss;
    ss << x;
    string str;
    ss >> str;
    return str;
}
Konto::Konto(string imie, string nazwisko, string nrKonta, double stan) {

    cout << "Konstruktor Konto();" << endl;
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->nrKonta = nrKonta;
    this->stanKonta = stan;
}

Konto::Konto() {  //konstruktor bez argumentow klasy


    stanKonta = 3000;
    cout << "nowy obiekt Konto" << endl;
}

Konto::Konto(string i, string n, string nr) {   //konstruktor z argumentami klasy
    stanKonta = 3000;
    imie = i;
    nazwisko = n;
    nrKonta = nr;
    cout << "nowy obiekt Konto nalezace do osoby imieniem (" << imie << ")  o nazwisku(" << nazwisko << ")  i numerze konta (" << nrKonta << ")" << endl;
}

Konto::~Konto() {//destruktor  klasy
    cout << "usuwam obiekt Konto" << endl;
}
//konstruktor kopiujący
Konto::Konto(const Konto& k) {
    cout << "Konstruktor kopiujacy Konto (Konto&);" << endl;
    this->imie = k.imie;
    this->nazwisko = k.nazwisko;
    this->nrKonta = k.nrKonta;
    this->stanKonta = k.stanKonta;
}
//konstruktor konwertujący
Konto::Konto(string imieNazwisko, string nrKonta, double stan) {
    cout << "Konstruktor konwertujacy  Konto (string);" << endl;
    this->imie = imieNazwisko.substr(0, imieNazwisko.find(" "));
    this->nazwisko = imieNazwisko.substr(imieNazwisko.find(" "),
        imieNazwisko.size());
    this->nrKonta = nrKonta;
    this->stanKonta = stan;
}
string Konto::wplata(double kwota) {
    string msg = "Wplata na konto nr: " + nrKonta + ", kwoty: "
   		+ doubleToString(kwota);
	//wyrażenie lambda
	stanKonta += kwota;
	msg += "\nStan konta: " + [](double x)->string 
	{
	    stringstream ss;
	    ss << x;
	    string str;
	    ss >> str;
	    return str; 
	}(stanKonta)+"\n";

	return msg;
}
string Konto::wyplata(double kwota) {
	stringstream ss;
	ss << kwota;
	string msg = "Wyplata z konta nr: " + nrKonta + ", kwoty: "
		+ doubleToString(kwota);

	if (stanKonta >= kwota) {
		stanKonta -= kwota;
		msg += "\nStan konta po operacji: " + doubleToString(stanKonta) + "\n";
	} else {
	    msg += "\nZa maoo srodkow aby zrealizowac wyplate";
	}
	return msg;
}
void Konto::wyswietl() {
    cout << imie << " " << nazwisko << ", nr konta: " << nrKonta << ", stan = "
        << stanKonta << endl;
}
void Konto::wpisz() {
	cout << "Podaj imie wlasciciela: ";
	cin >> imie;
	cout << "Podaj nazwisko wlasciciela: ";
	cin >> nazwisko;
	cout << "Podaj numer konta: ";
	cin.ignore();
    getline(cin, nrKonta);
    cout << "Podaj dostepne srodki: ";
    cin >> stanKonta;

}

void Konto::wypisz() {
    cout << "Konto  nalezy do " << imie << " " << nazwisko << " numer konta to " << nrKonta << "dostepne srodki to " << stanKonta << endl;
}
void Konto::wypiszStanKonta() {
	cout << "Stan konta wynosi:" << stanKonta << endl;
}
Konto Konto::operator+(const Konto& konto) { //przeciazenie operatora + dla klasy konto
    Konto Konto; //stworzenie nowego obiektu
    Konto.stanKonta += konto.stanKonta; // dodanie kasiory do konta
    return Konto;// zwrocenie obiektu
}
Konto Konto::operator-(const Konto& konto) { //przeciazenie operatora - dla klasy konto
    Konto Konto; //stworzenie nowego obiektu
    Konto.stanKonta -= konto.stanKonta; // odjecie kasiory do konta
    return Konto;// zwrocenie obiektu
}
////////////////////////
ostream& operator<<(ostream &wyjscie, Konto const & konto)
{
    wyjscie << "Konto  nalezy do " << konto.imie << " " << konto.nazwisko << " numer konta to " << konto.nrKonta << " dostepne srodki to " << konto.stanKonta << endl;
    return wyjscie;
}
///////////////////////
istream& operator>>(istream &wejscie, Konto & konto)
{
    wejscie >> konto.imie >> konto.nazwisko >> konto.nrKonta >>konto.stanKonta;
    return wejscie;
}
