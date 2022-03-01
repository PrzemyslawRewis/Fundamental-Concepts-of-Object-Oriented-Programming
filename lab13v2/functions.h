#pragma once
#include <iostream>
#include <cmath>
using namespace std;


/*klasa reprezentujaca funkcje liniowa(a*x+b) @param a -wspolczynnik a funkcji
 @param b wspolczynnik b funkcji*/
class Linear
{
    /*zaprzyjazniony przeciazony operator << */
    friend ostream& operator <<(ostream& os,Linear obj);
    public:
    /*konstruktor @param x - a @param y -b */
    Linear(double x,double y)
    {
        a=x;
        b=y;
    }
    /*przeciazony operator() @param x argument funkcji*/
    double operator()(double x)
    {
        return a*x+b;

    }

    private:
    double a;
    double b;


};
/*przeciazony operator << */
ostream& operator <<(ostream& os,Linear obj)
{
    return os<<obj.a<<"*x"<<obj.b;
}
/*klasa reprezentujaca pierwiastek z liczby*/
class Sqrt
{
    
    public:
    Sqrt()=default;
    /*przeciazony operator() @param x argument funkcji*/
    double operator()(double x) const
    {
        return std::pow(x,0.5);

    }

};
/*klasa reprezentujaca funkcje sinus(a*x+b) @param a -wspolczynnik a funkcji
 @param b wspolczynnik b funkcji*/
class Sin
{
    public:
    /*konstruktor @param x - a @param y -b */
    Sin(double x,double y)
    {
        a=x;
        b=y;
    }
    /*przeciazony operator() @param x argument funkcji*/
    double operator()(double x)
    {
        return sin(a*x+b);

    }
    
    private:
    double a;
    double b;


};