#pragma once
#include <iostream>
#include <cmath>
#include "MapDist.h"
using namespace std;

class MapDist;


class MapPoint
{
    friend MapPoint inTheMiddle(const MapPoint* p1,const MapPoint* p2, string nazwa);
    friend class MapDist;
    friend const MapDist distance(const MapPoint& p1,const MapPoint& p2);

    public:

        MapPoint(string nazwa,const double dlugosc,const double szerokosc);
        MapPoint(string nazwa,const double dlugosc,const char z1,const double szerokosc,const char z2);
        void print() const;
        void movePoint(const double longitudeShift,const double latitudeShift);
        const MapPoint& closestPlace(const MapPoint* p1,const MapPoint* p2) const;
        string getName() const;
        ~MapPoint();

    private:

        string name;
        double longitude;
        double latitude;
        char polkula1;
        char polkula2;


};

