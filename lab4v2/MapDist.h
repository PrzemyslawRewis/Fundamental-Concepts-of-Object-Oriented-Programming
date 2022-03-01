#pragma once
#include "MapPoint.h"
#include <cmath>

using namespace std;

struct MapDist
{
    double longitude;
    double latitude;

};

const MapDist distance(MapPoint m1,MapPoint m2);
double angularDistance(MapDist d);
const MapPoint& closestPlace(MapPoint* m1, MapPoint* m2,MapPoint* m3);
MapPoint inTheMiddle(MapPoint* m1,MapPoint* m2,string name);

