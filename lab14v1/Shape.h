#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
    public:
    Shape()=default;
    virtual double area() const { return 0.0;}
    virtual void print(std::ostream &o ) const {}
    virtual ~Shape()=default;

};

void print(Shape &obj) 
{
    obj.print(cout);

}