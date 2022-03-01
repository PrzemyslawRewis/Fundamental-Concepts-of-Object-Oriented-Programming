#pragma once
#include <iostream>
#include <utility>

using namespace std;


namespace wymierne{

class Wymierne
{
    
    public:
    /*konstruktor domyslny*/
    inline Wymierne():_licznik(0),_mianownik(1){}
    /*konstruktor parametrowy @param x licznik @param y mianownik*/ 
    inline Wymierne(int x,int y):_licznik(x),_mianownik((y!=0)? y: 1){Simplify();}
    /*konstruktor parametrowy @param x licznik */
    inline explicit Wymierne(int x):_licznik(x),_mianownik(1){}
    /*destruktor*/
    ~Wymierne()=default;
    /*metoda wypisujaca @param s1 napis*/
    void Print(string s1)const;
    /*metoda ustawiajaca*/
    void Set(const Wymierne &obj) const;
    /*getter licznika*/
    inline int getLicznik() const
    {
        return _licznik;
    }
    /*getter mianownika*/
    inline int getMianownik() const
    {
        return _mianownik;
    }
    /*metoda  ustawiajca mianownik*/
    void Mianownik(int x); 
    /*metoda  ustawiajaca licznik*/
    void Licznik(int x) const;
    /* operator konwersji liczby wymiernej na liczbe typu doubl*/
    inline operator double() const 
    {
        return static_cast<double>(_licznik)/static_cast<double>(_mianownik);
    }
    void Simplify() ;


    private:
    int _licznik;
    int _mianownik;

};
int Nwd(int m, int n);
/*funkcja mnozaca dwie liczby wymierne*/
Wymierne Pomnoz(const Wymierne& w1,const Wymierne& w2) ;
Wymierne Dodaj(const Wymierne& w1,const Wymierne& w2);
}
