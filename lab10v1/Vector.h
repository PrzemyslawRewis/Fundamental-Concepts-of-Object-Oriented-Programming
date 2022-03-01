#pragma once
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

using namespace std;


class Vector
{
    public:
    Vector()=default;
    explicit Vector(int n);
    explicit Vector(double n);
    Vector(Vector && obj);
    Vector(const Vector &obj);
    double& vec(int cos);
    Vector extended(int cos);
    void print(string s1) const;
    static double dot(const Vector& obj,const Vector & obj2); 
    static Vector sum(const Vector& obj,const Vector & obj2);
    explicit operator double() const;
    double norm() const ;
    ~Vector();

    
    private:
    double * dane;
    int dlugosc;


};