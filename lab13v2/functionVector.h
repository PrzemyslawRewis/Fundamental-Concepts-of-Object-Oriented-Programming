#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "functions.h"

using namespace std;
/*klasa reprezentujaca wektor funkcji*/
class FunctionVector
{
    public:
    
    /*funkcja wstawiajaca funkcje do wektora*/
    void insert(function<double (double)> f)
    {
        vec.push_back(f);

    }
    /*  funkcja liczaca f3 (f2 (f1(x)))*/
    double calc(double x)
    {
    
        double wynik;
        for (auto i: vec)
        {
            wynik=i(x);
            x=wynik;
        }
        return wynik;
        
    }
    /*operator zwracjacy wyniki pośrednie*/
    double operator [](int index){  

        auto i=vec[index];
        this->x=i(this->x);
        return this->x; 

    }

    private:
    
    vector<function<double (double)>> vec;
    double x=0.5;
   
    

};
