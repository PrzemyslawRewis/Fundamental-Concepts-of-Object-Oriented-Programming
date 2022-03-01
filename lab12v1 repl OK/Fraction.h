#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int nwd(int m, int n){
	int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
	    m = oldn;
	    n = oldm % oldn;
	}
    return n;
}


class Fraction
{
 
  public:
  /*konstruktor domyslny*/
  Fraction()=default;
  /*konstruktor parametrowy @param x licznik @param y mianownik*/
  Fraction(int x,int y)
  {
    int dziel=nwd(x,y);
    licznik=x/dziel;
    mianownik=y/dziel;
  }
  /*konstruktor parametrowy @param x licznik*/
  Fraction(int x):licznik(x),mianownik(1){}
  /*getter licznika*/
  int getLicznik()const {return licznik;}
  /*getter mianownika*/
  int getMianownik()const {return mianownik;}
  /*operator konwersji Fraction na double*/
  explicit operator double(){return static_cast<double>(licznik)/mianownik;}
  /*przeladowany operator*=*/
  Fraction operator*=(double l)
  {
    this->licznik*=l;
    int dziel=nwd(this->licznik,this->mianownik);
    licznik=licznik/dziel;
    mianownik=mianownik/dziel;
    return *this;
  }
  bool operator < (const Fraction &obj)
  {
    Fraction y=obj;
    double x=static_cast<double>(*this);
    double z=static_cast<double>(y);
    return (x<z)?true:false;
    
  }
  


  private:
  int licznik;
  int mianownik;

  

};
/*przeladowany operator <<*/
std::ostream& operator<<(std::ostream& o,const Fraction & obj)
{
  int calkowite=obj.getLicznik()/obj.getMianownik();
  int ulamkowe=(obj.getLicznik()-(calkowite*obj.getMianownik()));
  if (calkowite==0)
  return o<<ulamkowe<<"/"<<obj.getMianownik();
  else if(ulamkowe!=0)
  return o<<calkowite<<"+"<<abs(ulamkowe)<<"/"<<abs(obj.getMianownik());
  else if(obj.getMianownik()==1)
  return o<<calkowite;
  else
  return o<<calkowite<<"/"<<abs(obj.getMianownik());

  
}
/*przeladowany operator == dwa ulamki*/
bool operator==(const Fraction &obj1,const Fraction&obj2)
{
  if((obj1.getLicznik()==obj2.getLicznik())&&(obj1.getMianownik()==obj2.getMianownik()))
  return true;
  else
  return false;

}

/*przeladowany operator == ulamek i double*/
bool operator==(const Fraction&obj1,double l)
{
  double val=(static_cast<double>(obj1.getLicznik())/obj1.getMianownik());
  return (val==l)?true:false;
}
/*przeladowany operator * dwoch ulamkow*/
Fraction operator*(const Fraction &obj1,const Fraction&obj2)
{
    Fraction wynik=Fraction(obj1.getLicznik()*obj2.getLicznik(),obj1.getMianownik()*obj2.getMianownik());
    return wynik;
}
/*przeladowany operator -*/
Fraction operator-(const Fraction &obj1)
{
  Fraction wynik=Fraction(-obj1.getLicznik(),obj1.getMianownik());
  return wynik;

}
/*przeladowany operator + dwoch ulamkow Fraction*/
Fraction operator+(const Fraction &obj1,const Fraction&obj2)
{
  Fraction wynik=Fraction(obj1.getLicznik()*obj2.getMianownik()+obj2.getLicznik()*obj1.getMianownik(),obj1.getMianownik()*obj2.getMianownik());
  return wynik;

}
/*przeladowany operator + ulamek i liczba calkowata*/
Fraction operator+(int x,const Fraction&obj2)
{
  Fraction wynik=Fraction((x*obj2.getMianownik()+obj2.getLicznik()),obj2.getMianownik());
  return wynik;

}