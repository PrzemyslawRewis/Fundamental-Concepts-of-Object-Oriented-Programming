#include"Wymierne.h"

using namespace std;
void Wymierne::Print(string s1)const
{
    if(_mianownik!=1)
        cout<<s1<<_licznik<<"/"<<_mianownik<<endl;
    else
        cout<<s1<<_licznik<<endl;    

}
void Wymierne::Set(const Wymierne &obj) const
{
    const_cast<Wymierne*>(this)->_licznik=obj._licznik;
    const_cast<Wymierne*>(this)->_mianownik=obj._mianownik;
    
}
Wymierne Pomnoz(const Wymierne& w1,const Wymierne& w2) 
{
    Wymierne wynik;
    wynik._licznik=w1._licznik*w2._licznik;
    wynik._mianownik=w1._mianownik*w2._mianownik;
    return wynik;

}
void Wymierne::Mianownik(int x) 
{   
    if(x!=0)
        _mianownik=x;
    else
        _mianownik=1;

}
void Wymierne::Licznik(int x) const
{
    const_cast<Wymierne*>(this)->_licznik=x;
}
Wymierne::operator double() const
{
    return static_cast<double>(_licznik)/static_cast<double>(_mianownik);

}
int Wymierne::getLicznik() const
{
    return _licznik;
}
int Wymierne::getMianownik() const
{
    return _mianownik;
}

