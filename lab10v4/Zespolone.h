# pragma once

#include "Wymierne.h"

class Zespolone
{
    friend Zespolone Dodaj(const Zespolone& w1,const Zespolone &w2);
    public:
    /*konstruktor domyslny*/
    Zespolone()=default;
    /*konstruktor parametrowy @param x re @param y im*/
    Zespolone(double x,double y):_re(x),_im(y){}
    /*konstruktor parametrowy @param x re */
    Zespolone(double x):_re(x),_im(0.0){}
    /*kostruktor parametrowy @param obj liczba wymierna */
    Zespolone(const Wymierne& obj):_re(static_cast<double>(obj.getLicznik())/static_cast<double>(obj.getMianownik())),_im(0.0){}
    /*konstruktor kopiujacy*/
    Zespolone(const Zespolone& obj):Zespolone(obj._re, obj._im){}
    /*kostruktor przenoszacy*/
    Zespolone(Zespolone&& obj):_re(std::exchange(obj._re,0.0)),_im(std::exchange(obj._im,0.0)){}
    /*metoda wypisujaca @param s1 napis*/
    void Print(string s1);
    /*getter im*/
    double Im();

    private:
    double _re;
    double _im;

};
/*funkcja dodająca dwie liczby zespolone*/
Zespolone Dodaj(const Zespolone& w1,const Zespolone &w2);