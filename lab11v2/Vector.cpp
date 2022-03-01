#include "Vector.h"
#include "Complex.h"
using namespace std;


Vector::Vector(Complex obj):Vector(obj.Re(),obj.Im()){}


void Vector::print(string s1) const
{
  int i =0;
  cout<<s1;
  cout<<"[";
 
  while(i<dlugosc-1)
  {
    
    cout<<dane[i]<<", ";
    i++;
  }
  if(dlugosc==-1)
    cout<<"]"<<endl;
  else  
    cout<<dane[i]<<"]"<<endl;

}

  
double& Vector::operator[](int i) const
{
  return dane[i];
}
Vector Vector::operator+(const Vector& v) const
{
  int longer=0;
  longer=(v.dlugosc>this->dlugosc)?v.dlugosc:this->dlugosc;
  Vector wynik(longer);
  int i =0;
  while(i<dlugosc)
  {
    wynik.dane[i]=this->dane[i]+v.dane[i];
    i++;
  }
  return wynik;

}
double operator*(const Vector& v1,const Vector& v2)
{
  if(v1.dlugosc==v2.dlugosc)
  {
    double wynik=0.0;
    int i=0;
    while(i<v1.dlugosc)
    {
      wynik+=v1.dane[i]*v2.dane[i];
      i++;
    }
    return  wynik;
  }
  else
  {
    return 1.0;
  }

}
Vector& Vector::operator=(const Vector& obj)
{
  this->dlugosc=obj.dlugosc;
  this->dane=new double[this->dlugosc];
  for(int i =0; i<dlugosc;i++)
  {
    this->dane[i]=obj.dane[i];
  }
  return *this;

}

double Vector::norm()const
{
  double wynik=0.0;
  int i =0;
  while(i<dlugosc)
  {
    wynik+=dane[i]*dane[i];
    i++;
  }
  return pow(wynik,0.5);
}
Vector::operator double ()const
{
  return this->norm();

}


double Vector::getDane(int i) const
{
  return dane[i];
}