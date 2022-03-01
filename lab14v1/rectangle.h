#pragma once
#include "Shape.h"
using namespace std;
class Rectangle : public Shape
{
    public:
    Rectangle(int x,int y):bok1(x),bok2(y){}
    void print(std::ostream &o) const
    {
        o<<"Prostokat o bokach: "<<bok1<<" "<<bok2<<endl;
    }
    double area() const
    {
        return bok1*bok2;
    }
    ~Rectangle()=default;

    private:
    int bok1,bok2;


};

void print(const Rectangle& obj)
{
    obj.print(cout);
}