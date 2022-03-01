#pragma once
#include "Shape.h"
using namespace std;
class Circle : public Shape
{
    public:
    Circle(int x):promien(x){}
    void print(std::ostream &o) const
    {
        o<<"Kolo o promieniu: "<<promien<<endl;
    }
    double area() const
    {
        return M_PI*promien*promien;

    }
    ~Circle()=default;
    private:
    int promien;


};

void print(const Circle& obj)
{
    obj.print(cout);
}