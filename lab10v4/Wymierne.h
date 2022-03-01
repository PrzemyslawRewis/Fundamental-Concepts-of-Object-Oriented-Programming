#pragma once
#include <iostream>
#include <utility>

using namespace std;

class Wymierne
{
    friend Wymierne Pomnoz(const Wymierne& w1,const Wymierne& w2);
    public:
    /*konstruktor domyslny*/
    Wymierne():_licznik(0),_mianownik(1){}
    /*konstruktor parametrowy @param x licznik @param y mianownik*/
    
    Wymierne(int x,int y):_licznik(x),_mianownik((y!=0)? y: 1){}
    /*konstruktor parametrowy @param x licznik */
    explicit Wymierne(int x):_licznik(x),_mianownik(1){}
    /*konstruktor kopiujacy*/
    Wymierne(const Wymierne & obj):_licznik(obj._licznik),_mianownik(obj._mianownik){}
    /*kostruktor przenoszacy*/
    Wymierne(Wymierne &&obj):_licznik(std::exchange(obj._licznik,0)),_mianownik(std::exchange(obj._mianownik,1)){}
    /*destruktor*/
    ~Wymierne()=default;
    /*metoda wypisujaca @param s1 napis*/
    void Print(string s1)const;
    /*metoda ustawiajaca*/
    void Set(const Wymierne &obj) const;
    /*getter licznika*/
    int getLicznik() const;
    /*getter mianownika*/
    int getMianownik() const;
    /*metoda  ustawiajca mianownik*/
    void Mianownik(int x) ;
    /*metoda  ustawiajaca licznik*/
    void Licznik(int x) const ;
    /* operator konwersji liczby wymiernej na liczbe typu doubl*/
    operator double() const ;


    private:
    int _licznik;
    int _mianownik;

};
/*funkcja mnozaca dwie liczby wymierne*/
Wymierne Pomnoz(const Wymierne& w1,const Wymierne& w2) ;