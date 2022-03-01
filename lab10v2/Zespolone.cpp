#include "Zespolone.h"

using namespace std;

void Zespolone::Print(string s1)const
{
    cout<<s1<<"("<<re<<","<<im<<")"<<endl;
}

Zespolone Dodaj(const Zespolone& z1,const Zespolone& z2)
{
    Zespolone wynik;
    wynik.re=z1.re+z2.re;
    wynik.im=z1.im+z2.im;
    return wynik;
}

