#include "MapPoint.h"

using namespace std;

MapPoint::MapPoint()
{
    longitude=0;
    latitude=0;
    nazwa="Punkt";

}

MapPoint::MapPoint(string name,const double dlugosc, const double szerokosc)
{
    nazwa=name;
    longitude=dlugosc;
    latitude=szerokosc;

}
MapPoint::MapPoint(string name,float dlugosc,char dl,float szerokosc,char sz)
{
    nazwa = name;
    longitude=static_cast<double>((dl=='E') ?  dlugosc : -dlugosc);
    latitude= static_cast<double>((dl=='N') ?  dlugosc : -dlugosc);
    
}
void MapPoint::print() const
{
    cout<<"Wspolrzedne dla "<<nazwa<<": "<<fabs(longitude)<< ((longitude>0) ?  "E, " : "W, ") <<fabs(latitude)<<((latitude>0) ?  "N" : "S")<<endl;

}
void MapPoint::movePoint(const double longitudeShift,const double latitudeShift)
{
    this->longitude+=longitudeShift;
    this->latitude+=latitudeShift;

}
MapPoint MapPoint::closestPlace(MapPoint* p1,MapPoint* p2)
{

}
string MapPoint::getName() const
{
    return this->nazwa;
}
MapPoint::~MapPoint()
{
    cout<<"Usuwanie "<<this->nazwa<<endl;
}
MapPoint inTheMiddle(MapPoint * p1,MapPoint *p2,string name)
{
    return MapPoint(name,(p1->longitude+p2->longitude)/2.0,(p2->latitude+p1->latitude)/2.0); 
    
}