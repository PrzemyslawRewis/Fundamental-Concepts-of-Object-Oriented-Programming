#pragma once
#include <iostream>
#include <utility>

using namespace std;



class Wymierne
{
    friend Wymierne Dodaj(const Wymierne& w1,const Wymierne& w2);
    public:
    Wymierne():licznik(0),mianownik(1){}
    explicit Wymierne(int x):licznik(x),mianownik(1){}
    Wymierne(int x,int y):licznik(x),mianownik((y!=0)?y:1){}
    Wymierne(const Wymierne& obj):licznik(obj.licznik),mianownik(obj.mianownik){}
    Wymierne(Wymierne && obj):licznik(std::exchange(obj.licznik,0)),mianownik(std::exchange(obj.mianownik,1)){}
    void Print(string s1) const;
    static Wymierne Pomnoz(const Wymierne& w1,const Wymierne& w2);
    operator double() const;    
    int getLicznik();
    int getMianownik();

    private:
    int licznik;
    int mianownik;

};
Wymierne Dodaj(const Wymierne& w1,const Wymierne& w2);