# pragma once

#include "Wymierne.h"

using wymierne::Wymierne;
using namespace std;

namespace zespolone
{

class Zespolone
{
    public:
    /*konstruktor domyslny*/
    inline Zespolone()=default;
    /*konstruktor parametrowy @param x re @param y im*/
    inline Zespolone(double x,double y):_re(x),_im(y){}
    /*konstruktor parametrowy @param x re */
    inline Zespolone(double x):_re(x),_im(0.0){}
    /*kostruktor parametrowy @param obj liczba wymierna */
    inline Zespolone(const Wymierne& obj):_re(static_cast<double>(obj.getLicznik())/static_cast<double>(obj.getMianownik())),_im(0.0){}
    /*konstruktor kopiujacy*/
    inline Zespolone(const Zespolone& obj):Zespolone(obj._re, obj._im){}
    /*kostruktor przenoszacy*/
    inline Zespolone(Zespolone&& obj):_re(std::exchange(obj._re,0.0)),_im(std::exchange(obj._im,0.0)){}
    /*metoda wypisujaca @param s1 napis*/
    void Print(string s1="Z2 = ");
    /*getter im*/
    inline double Im() const
    {
        return _im;
    }
    /*getter Re*/
    inline double Re() const
    {
        return _re;
    }


    private:
    double _re;
    double _im;

};
/*funkcja dodająca dwie liczby zespolone*/

Zespolone Dodaj(const Zespolone& w1,const Zespolone &w2);
}

