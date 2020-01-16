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
    Konto(string imie, string nazwisko, string nrKonta, double stan);     //konstruktor
    Konto(const Konto&);        //konstruktor kopiujący
    Konto(string, string = "0000 0001 0003 9571", double = 0.0);    //konstruktor konwertujący

    operator double() {       //funkcja konwertująca
        return stanKonta;
    }

    string wplata(double);
    string wyplata(double);
    void wyswietl();
    ~Konto();

    void wpisz();
    void wypisz();

    Konto operator+(const Konto&);           //przeciążenie operatora + dla klasy konto (po lewej stronie znaku + jest obiekt konto a po prawej liczba int)
    Konto operator-(const Konto&);           //przeciążenie operatora - dla klasy konto (po lewej stronie znaku - jest obiekt konto a po prawej liczba int)
    
    friend ostream& operator<< (ostream&, Konto const&); //////
    friend istream& operator>> (istream&, Konto&); ///////
};

#endif /* class_hpp */
