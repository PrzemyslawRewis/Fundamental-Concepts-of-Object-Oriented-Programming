#include "Vector.h"

using namespace std;

Vector::Vector(int n)
{
  dlugosc = n;
  dane = new double[dlugosc];
  for (int i=0;i<n;i++)
  {
    dane[i]=0;
  }
    
}
Vector::Vector(double n)
{
    dlugosc=1;
    dane=new double[1];
    dane[0]=n;

}
Vector::Vector(Vector && obj)
{
    int i=0;
    this->dlugosc=std::move(obj.dlugosc);
    this->dane=new double[this->dlugosc];
    while (i<dlugosc)
    {
        this->dane[i]=std::exchange(obj.dane[i],0);
        i++;
    }
    delete [] obj.dane;
    obj.dane=nullptr;
    
    

}
Vector::Vector(const Vector &obj)
{
    int i=0;
    this->dlugosc=obj.dlugosc;
    this->dane=new double[this->dlugosc];
    while (i<dlugosc)
    {
        this->dane[i]=obj.dane[i];
        i++;
    }



}
double& Vector::vec(int cos)
{
    return dane[cos];

}
void Vector::print(string s1) const
{
    int i=0;
    cout<<s1;
    cout<<"[";
    while(i<dlugosc-1)
    {
        cout<<dane[i]<<", ";
        i++;
    }
    cout<<dane[i]<<"]"<<endl;

}
double Vector::dot(const Vector& obj,const Vector & obj2)
{
    if(obj.dlugosc==obj2.dlugosc)
    {
        double wynik=0.0;
        int i=0;
        while (i<obj.dlugosc)
        {
            wynik+=obj.dane[i]*obj2.dane[i];
            i++;
        }
        return wynik;
        
    }
    else
    {
        __throw_logic_error("Wymiary mnozonych wektorow musza byc takie same, a nie sa!");
    }

} 
Vector Vector::sum(const Vector& obj,const Vector & obj2)
{
   int rozmiar=(obj.dlugosc>obj2.dlugosc)?obj.dlugosc:obj2.dlugosc;
   Vector wynik(rozmiar);
   if(obj.dlugosc>=obj2.dlugosc)
    {
        int i=0;
        while(i<obj2.dlugosc)
        {
            wynik.dane[i]=obj.dane[i]+obj2.dane[i];
            i++;
        }
        while(i<obj.dlugosc)
        {
            wynik.dane[i]=obj.dane[i];
            i++;
        } 

    }
    else
    {
        int i=0;
        while(i<obj.dlugosc)
        {
            wynik.dane[i]=obj.dane[i]+obj2.dane[i];
            i++;
        }
        while(i<obj2.dlugosc)
        {
            wynik.dane[i]=obj2.dane[i];
            i++;
        } 
    }
    return wynik;
   

}

double Vector::norm() const
{
    double wynik=0.0;
    int i=0;
    while (i<dlugosc)
    {
        wynik+=dane[i]*dane[i];
        i++;
    }
    return pow(wynik,0.5);
}
Vector::operator double() const
{
    return this->norm();

}
Vector Vector::extended(int cos)
{
    Vector wynik(cos);
    for(int i=0;i<dlugosc;i++)
        wynik.dane[i]=dane[i];
    return wynik;    
}

Vector::~Vector()
{
    delete [] dane;
    dlugosc=0;
    dane = nullptr;
}
