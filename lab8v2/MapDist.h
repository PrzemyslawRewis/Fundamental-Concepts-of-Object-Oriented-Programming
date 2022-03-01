#pragma once
#include <iostream>
#include <cmath>
#include "MapPoint.h"
using namespace std;

class MapDist;
class MapPoint;

const MapDist distance(const MapPoint& p1,const MapPoint& p2);

class MapDist
{
    friend const MapDist distance(const MapPoint& p1,const MapPoint& p2);
    public:
        MapDist()=default;
        MapDist(const MapPoint &p1,const MapPoint &p2);
        double getlongitude() const;
        double getlatitude() const;
        double angularDistance() const;

    private:
        double distancelongitude;
        double distancelatitude;

};

