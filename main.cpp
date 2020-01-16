#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#include "class.h"

using namespace std;


int main()
{
    string str = "Adam Nowak";
    Konto k2 = str;
    k2.wyswietl();
    k2.wplata(2000);
    double stan = k2;
    cout << stan << endl;
    Konto k3(k2);
    k3.wyswietl();
    cout << k3.wyplata(1000);
    cout << k3.wplata(3000);


    Konto Konto("Adam", "Nowak", "0000 0001 0003 9571");
    Konto.wypisz();

    cout << "--------------------Wyswietlanie danych------------------------" << endl << endl;
    operator <<(cout, Konto);


    cout << "--------------------Wprowadzanie danych------------------------" << endl << endl;
    Konto.wpisz();
    Konto.wypisz();

    operator >>(cin, Konto);
    operator <<(cout, Konto);



    cout << "------------------Operator przeciazenia /+/  ------------------------" << endl << endl;
    
    Konto = Konto + k3;
    
    Konto.wypisz();


    cout << "------------------Operator przeciazenia /-/  ------------------------" << endl << endl;

    Konto = Konto - k3;

    Konto.wypisz();

    system("PAUSE");
    return 0;
}
