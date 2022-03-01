#include"Wymierne.h"

using namespace std;
using wymierne::Wymierne;
void Wymierne::Print(string s1) const
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
int wymierne::Nwd(int m, int n)
{
    int oldm, oldn;
    while( m % n != 0 )
    {
        oldm = m;
        oldn = n;
        m = oldn;
        n = oldm % oldn;
    }
    return n;
 } 

void Wymierne::Simplify() 
{
    int nw = wymierne::Nwd(getLicznik(), getMianownik());
    Licznik(getLicznik() / nw);
    Mianownik(getMianownik() / nw);
}     
Wymierne wymierne::Pomnoz(const Wymierne& w1,const Wymierne& w2) 
{
    return Wymierne(w1.getLicznik()*w2.getLicznik(),w1.getMianownik()*w2.getMianownik());

}
Wymierne wymierne::Dodaj(const Wymierne& w1,const Wymierne& w2) 
{
    return Wymierne(w1.getLicznik()*w2.getMianownik()+w2.getLicznik()*w1.getMianownik(),w1.getMianownik()*w2.getMianownik());

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
