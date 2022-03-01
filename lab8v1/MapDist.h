#pragma once
#include <iostream>
#include "MapPoint.h"


using namespace std;

class MapDist;
class MapPoint;

MapDist distance(MapPoint p1,MapPoint p2);

class MapDist
{
    friend class MapPoint;
    friend MapDist distance(MapPoint p1,MapPoint p2);
    public:
    MapDist()=default;
    MapDist(MapPoint p1,MapPoint p2);
    double getlongitude() const;
    double getlatitude() const;
    double angularDistance() const;

    private:
    double longdistance;
    double latidistance;
    

};


