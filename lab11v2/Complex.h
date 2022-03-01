#pragma once
#include "Vector.h"
using namespace std;



class Complex
{
    public:
    /*konstruktor domyslny*/
    Complex()=default;
    /*konstruktor parametrowy @param x re @param y im*/
    Complex(double x,double y):_re(x),_im(y){}
    /*konstruktor parametrowy @param x re */
    Complex(double x):_re(x),_im(0.0){}
    /*kostruktor parametrowy @param obj liczba wymierna */
    explicit Complex(const Vector& obj):_re(static_cast<double>(obj.getDane(0))),_im(static_cast<double>(obj.getDane(1))){}
    /*konstruktor kopiujacy*/
    Complex(const Complex& obj):Complex(obj._re, obj._im){}
    /*kostruktor przenoszacy*/
    Complex(Complex&& obj):_re(std::exchange(obj._re,0.0)),_im(std::exchange(obj._im,0.0)){}
    /*metoda wypisujaca @param s1 napis*/
    void print(string s1) const;
    /*getter _im*/
    double Im() const;
    /*getter _re*/
    double Re() const;
    /*przeladowany operator dodawania*/
    Complex operator+(const Complex& c) ;
    /*przeladowany operator = */
    Complex& operator=(const Complex& obj);
    

    private:
    double _re;
    double _im;
    int licznik=0;

};
/*funkcja dodająca dwie liczby Complex*/
