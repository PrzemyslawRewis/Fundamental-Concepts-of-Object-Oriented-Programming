#pragma once

#include "Wymierne.h"

using wymierne::Wymierne;

class Double
{
private:
    double x;
    int licznik;

public:
    inline Double(double x) : x(x), licznik(0){};
    inline Double(const Wymierne &w) : Double(double(w)){};

    inline double getx() const { return x; };
    void setx(const Double &d) const { const_cast<Double *>(this)->x = d.x; };

    void print() const
    {
        Double *th = const_cast<Double *>(this);
        th->licznik++;
        std::cout << "Print nr " << licznik << ". Val = " << x << std::endl;
    }
};

Double Dodaj(const Double &d1, const Double &d2)
{
    return Double(d1.getx() + d2.getx());
}
void print(const Double &d)
{
    d.print();
}
