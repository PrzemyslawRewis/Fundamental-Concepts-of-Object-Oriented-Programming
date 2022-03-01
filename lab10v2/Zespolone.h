#pragma once
#include "Wymierne.h"

using namespace std;

class Zespolone
{
    friend Zespolone Dodaj(const Zespolone& z1,const Zespolone& z2);
    public:
    Zespolone()=default;
    Zespolone(double x,double y):re(x),im(y){}
    Zespolone(double x):re(x),im(0.0){}
    explicit Zespolone(const Wymierne& w1):re(static_cast<double>(w1)),im(0.0){}
    Zespolone(const Zespolone& obj):re(obj.re),im(obj.im){}
    Zespolone(Zespolone&& obj):re(std::exchange(obj.re,0.0)),im(std::exchange(obj.im,0.0)){};
    void Print(string s1)const;
    private:
    double re;
    double im;

};

Zespolone Dodaj(const Zespolone& z1,const Zespolone& z2);
