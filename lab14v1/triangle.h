#pragma once
#include "Shape.h"
using namespace std;

class Triangle : public Shape
{
    public:
    Triangle(int x,int y,int z):bok1(x),bok2(y),bok3(z){}
    void print(std::ostream &o) const
    {
        o<<"Trojkat o bokach: "<<bok1<<" "<<bok2<<" "<<bok3<<endl;
    }
    double area() const 
    {
        double x = 0.5*(bok1+bok2+bok3);
        return pow(x*(x-bok1)*(x-bok2)*(x-bok3),0.5);
    }
    ~Triangle()=default; 

    private:
    int bok1,bok2,bok3;


};

void print(const Triangle& obj)
{
    obj.print(cout);
}