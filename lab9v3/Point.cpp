#include "Point.h"

using namespace std;

int Point::number=0;
//konstuktory
Point::Point():_nazwa(" "),_dlugosc(0.0),_szerokosc(0.0),_numerobiektu(++Point::number){}
Point::Point(string s1,double x,double y):_nazwa(s1),_dlugosc(x),_szerokosc(y),_numerobiektu(++Point::number){}
Point::Point(const Point& obj):_nazwa(obj._nazwa),_dlugosc(obj._dlugosc),_szerokosc(obj._szerokosc),_numerobiektu(++Point::number)
{
    cout<<"--- Kopiujemy "<<obj._numerobiektu<<". " <<obj._nazwa<<endl;    
}
Point::Point(Point&& obj)
{
    cout<<"--- Przenosimy "<<obj._numerobiektu<<". "<<obj._nazwa<<endl;
    ++Point::number;
    _numerobiektu=Point::number;
    _nazwa=std::move(obj._nazwa);
    _dlugosc=std::move(obj._dlugosc);
    _szerokosc=std::move(obj._szerokosc);
    obj._nazwa="";
    obj._dlugosc=0.0;
    obj._szerokosc=0.0;

}

Point Point::setPoint(double x,double y)
{
    return Point("PunktX",x,y);

}

Point Point::setContrary(double x,double y)
{
    return Point("PunktX",-x,-y);
}
Point Point::newMoved(string s1,double x,double y)
{
    return Point(s1,x,y);

}
Point::~Point()
{
    --Point::number;
    _dlugosc=0.0;
    _szerokosc=0.0;
    _nazwa=" ";

}
//funkcje
void Point::fullPrint() const
{
    cout<<_numerobiektu<<". "<<_nazwa<<" "<<"("<<_dlugosc<<","<<_szerokosc<<")"<<endl;

}
void Point::changeName(string s1)
{
    this->_nazwa=s1;
}