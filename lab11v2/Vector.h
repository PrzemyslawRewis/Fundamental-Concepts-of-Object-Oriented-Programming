#pragma once
#include <iostream>
#include <utility>
#include <cmath>

class Complex;



using namespace std;
class Vector
{
  public:
  Vector()=default;
  explicit Vector (int n)
  {
    dlugosc=n;
    dane=new double[dlugosc];
    for(int i=0;i<dlugosc;i++)
       dane[i]=0;
  }
  Vector (Vector &&obj)
  {
    int i =0;
    this->dlugosc=std::move(obj.dlugosc);
    this->dane=new double[this->dlugosc];
    while(i<dlugosc)
    {
      this->dane[i]=std::exchange(obj.dane[i],0);
      i++;
    }
    obj.dlugosc=-1; 

  }
  Vector(double x,double y)
  {
    dlugosc=2;
    dane=new double[dlugosc];
    dane[0]=x;
    dane[1]=y;
  }
  Vector(Complex obj);
  Vector(const Vector& obj)
  {
    int i =0;
    this->dlugosc=obj.dlugosc;
    this->dane=new double[this->dlugosc];
    while(i<dlugosc)
    {
      this->dane[i]=obj.dane[i];
      i++;
    }
  }
  void print(string s1) const;
  double& operator[](int i) const;
  Vector operator+(const Vector& v) const;
  friend double operator*(const Vector& v1,const Vector& v2);
  explicit operator double ()const;
  double norm()const;
  Vector& operator=(const Vector& obj);

  ~Vector()
  {
    delete []dane;
    dlugosc=0;
    dane=nullptr; 
  }
  double getDane(int i) const;
  private:
  double * dane;
  int dlugosc;
};
double operator*(const Vector& v1,const Vector& v2) ;