#pragma once
#include <iostream>
#include <cmath>
#include "MapDist.h"
using namespace std;

class MapPoint; 
class MapDist;

MapPoint inTheMiddle(MapPoint * p1,MapPoint *p2,string name);

class MapPoint
{
    friend class MapDist;
    friend MapPoint inTheMiddle(MapPoint * p1,MapPoint *p2,string name);
    friend MapDist distance(MapPoint p1,MapPoint p2);
    public:
    MapPoint();
    MapPoint(string name,float dlugosc,char dl,float szerokosc,char sz);
    MapPoint(string name,double dlugosc,double szerokosc);
    void print() const;
    void movePoint(const double longitudeShift,const double latitudeShift) ;
    MapPoint closestPlace(MapPoint* p1,MapPoint* p2);
    string getName() const;
    ~MapPoint();
    private:
    string nazwa;
    double longitude;
    double latitude;

};


