#include "MapPoint.h"

using namespace std;

MapPoint::MapPoint(string nazwa,const double dlugosc,const double szerokosc):name(nazwa),longitude(dlugosc),latitude(szerokosc)
{
    polkula1=(longitude>0)?'E':'W';
    polkula2=(latitude>0)?'N':'S';
}
MapPoint::MapPoint(string nazwa,const double dlugosc,const char z1,const double szerokosc,const char z2)
{
    name=nazwa;
    longitude=(z1=='E')?dlugosc:-dlugosc;
    latitude=(z2=='N')?szerokosc:-szerokosc;
    polkula1=z1;
    polkula2=z2;
}
void MapPoint::print() const
{
    cout<<"Wspolrzedne dla "<<name<<": "<<fabs(longitude)<< polkula1 <<", "<<fabs(latitude)<<polkula2<<endl;
}
void MapPoint::movePoint(const double longitudeShift,const double latitudeShift)
{
    longitude+=longitudeShift;
    latitude+=latitudeShift;
    this->polkula1=(longitude>0)?'E':'W';
    this->polkula2=(latitude>0)?'N':'S';
    
}
const MapPoint& MapPoint::closestPlace(const MapPoint* p1,const MapPoint* p2) const
{
    MapDist d1(*this,*p1);
    MapDist d2(*this,*p2);

    if(d1.angularDistance()<d2.angularDistance())
        return *p1;
    else
        return *p2;  


}
string MapPoint::getName() const
{
    return this->name;
}

MapPoint inTheMiddle(const MapPoint* p1,const MapPoint* p2, string nazwa)
{
    MapPoint p("",0.0,0.0);
    p.longitude=(p1->longitude+p2->longitude)/2.0;
    p.latitude=(p1->latitude+p2->latitude)/2.0;
    if(p.longitude>0)
    {
        p.polkula1='E';

    }
    else
    {
        p.polkula1='W';

    }
        

     if(p.latitude>0)
    {
        p.polkula2='N';

    }
    else
    {
        p.polkula2='S';

    }
    p.name=nazwa;
    return p;

}

MapPoint::~MapPoint()
{
    std::cout<<"Usuwanie " <<name<<std::endl;
    
}