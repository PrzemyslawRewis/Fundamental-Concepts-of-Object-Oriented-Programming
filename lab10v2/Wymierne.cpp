#include "Wymierne.h"

using namespace std;


void Wymierne::Print(string s1) const
{
    if(mianownik!=1)
        cout<<s1<<licznik<<"/"<<mianownik<<endl;
    else
        cout<<s1<<licznik<<endl;    

}
Wymierne Wymierne::Pomnoz(const Wymierne& w1,const Wymierne& w2)
{
    Wymierne wynik;
    wynik.licznik=w1.licznik*w2.licznik;
    wynik.mianownik=w2.mianownik*w1.mianownik;
    return wynik;

}
Wymierne::operator double() const
{
    return static_cast<double>(licznik)/static_cast<double>(mianownik);

}
Wymierne Dodaj(const Wymierne& w1,const  Wymierne& w2) 
{
    Wymierne wynik;
    wynik.licznik=w1.licznik*w2.mianownik+w2.licznik*w1.mianownik;
    wynik.mianownik=w1.mianownik*w2.mianownik;
    return wynik;

}

int Wymierne::getLicznik()
{
    return licznik;

}
int Wymierne::getMianownik()
{
    return mianownik;
}