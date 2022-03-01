#include "Vector2D.h"

using namespace std;
int Vector2D::count=0;
Vector2D::Vector2D(const Vector2D& obj):nazwa(obj.nazwa),wsp1(obj.wsp1),wsp2(obj.wsp2)
{
    ++Vector2D::count;
    cout<<"--- kopiowanie";
    obj.print();
    
}
Vector2D::Vector2D(Vector2D&& obj)
{
    ++Vector2D::count;
    cout<<"--- przenoszenie";
    obj.print();
    this->nazwa=std::move(obj.nazwa);
    this->wsp1=std::move(obj.wsp1);
    this->wsp2=std::move(obj.wsp2);
    obj.wsp1=0.0;
    obj.wsp2=0.0;

   
    
    
    

}
Vector2D Vector2D::fromCarthesian(string s1,double x1,double x2)
{

    return Vector2D(x1,x2,s1);
    

}
const Vector2D Vector2D::fromPolar(string s1,double x1,double x2)
{
    double radiany=(x2/180.0)*M_PI;
    return Vector2D(x1*cos(radiany),x1*sin(radiany),s1);

}
void Vector2D::print(string s1) const
{
    cout<<s1<<this->nazwa<<"="<<"("<<this->wsp1<<", "<<this->wsp2<<")"<<endl;

}
double Vector2D::dot(const Vector2D& obj) const
{
    return this->wsp1*obj.wsp1+this->wsp2*obj.wsp2;
   
}
Vector2D Vector2D::add(const Vector2D& obj) const
{
    Vector2D tmp;
    tmp.wsp1=wsp1+obj.wsp1;
    tmp.wsp2=wsp2+obj.wsp2;
    return tmp;

}
Vector2D Vector2D::fromCarthesian(double x,double y)
{
    return Vector2D(x,y);

}
Vector2D::~Vector2D()
{
    --count;
}
